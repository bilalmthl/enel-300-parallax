#include "i2c-lcd.h"

extern I2C_HandleTypeDef hi2c1;  // Use the I2C handle from main.c

// 0x27 shifted left by 1 is exactly 0x4E. Hardcoding this prevents C macro expansion bugs.
#define SLAVE_ADDRESS_LCD 0x4E

void lcd_send_cmd(char cmd) {
    char data_u, data_l;
    uint8_t data_t[4];
    data_u = (cmd & 0xf0);
    data_l = ((cmd << 4) & 0xf0);
    data_t[0] = data_u | 0x0C;  // en=1, rs=0, backlight=1
    data_t[1] = data_u | 0x08;  // en=0, rs=0, backlight=1
    data_t[2] = data_l | 0x0C;  // en=1, rs=0, backlight=1
    data_t[3] = data_l | 0x08;  // en=0, rs=0, backlight=1
    HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDRESS_LCD, (uint8_t *)data_t, 4, 100);
}

void lcd_send_data(char data) {
    char data_u, data_l;
    uint8_t data_t[4];
    data_u = (data & 0xf0);
    data_l = ((data << 4) & 0xf0);
    data_t[0] = data_u | 0x0D;  // en=1, rs=1, backlight=1
    data_t[1] = data_u | 0x09;  // en=0, rs=1, backlight=1
    data_t[2] = data_l | 0x0D;  // en=1, rs=1, backlight=1
    data_t[3] = data_l | 0x09;  // en=0, rs=1, backlight=1
    HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDRESS_LCD, (uint8_t *)data_t, 4, 100);
}

void lcd_clear(void) {
    lcd_send_cmd(0x01);
    HAL_Delay(2);
}

void lcd_put_cur(int row, int col) {
    switch (row) {
        case 0: col |= 0x80; break;
        case 1: col |= 0xC0; break;
    }
    lcd_send_cmd(col);
}

void lcd_init(void) {
    uint8_t data_t[2];

    // 1. Wait for LCD to fully power up before sending anything
    HAL_Delay(50);

    // --- SINGLE NIBBLE INITIALIZATION SEQUENCE (Mimics Python RPLCD) ---
    // Command 1: 0x30
    data_t[0] = 0x30 | 0x0C;
    data_t[1] = 0x30 | 0x08;
    HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDRESS_LCD, data_t, 2, 100);
    HAL_Delay(5);

    // Command 2: 0x30
    data_t[0] = 0x30 | 0x0C;
    data_t[1] = 0x30 | 0x08;
    HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDRESS_LCD, data_t, 2, 100);
    HAL_Delay(1);

    // Command 3: 0x30
    data_t[0] = 0x30 | 0x0C;
    data_t[1] = 0x30 | 0x08;
    HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDRESS_LCD, data_t, 2, 100);
    HAL_Delay(10);

    // Command 4: 0x20 (Lock into 4-bit mode)
    data_t[0] = 0x20 | 0x0C;
    data_t[1] = 0x20 | 0x08;
    HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDRESS_LCD, data_t, 2, 100);
    HAL_Delay(10);

    // --- NORMAL 2-NIBBLE COMMANDS CAN NOW BE USED ---
    lcd_send_cmd(0x28);  // Function set: 2 lines, 5x8 font
    HAL_Delay(1);
    lcd_send_cmd(0x08);  // Display off
    HAL_Delay(1);
    lcd_send_cmd(0x01);  // Clear display
    HAL_Delay(2);
    lcd_send_cmd(0x06);  // Entry mode set: auto-increment cursor
    HAL_Delay(1);
    lcd_send_cmd(0x0C);  // Display ON, Cursor OFF
}

void lcd_send_string(char *str) {
    while (*str) lcd_send_data(*str++);
}
