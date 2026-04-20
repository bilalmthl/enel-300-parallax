# ENEL-300 Parallax Car Firmware

STM32 firmware for the **car node** in the ENEL-300 wireless parallax demo. This project receives joystick control packets over Bluetooth, drives motor + servo outputs, measures distance with HC-SR04, and streams distance telemetry back to the controller.

## Highlights

- Real-time control over Bluetooth (`USART1`)
- Differential actuator handling (DC motor + steering servo)
- HC-SR04 ultrasonic distance capture using timer input capture
- Periodic telemetry packets with human-readable framing (`D:<value>\n`)
- Failsafe stop if controller packets are stale

## System Architecture

```mermaid
flowchart LR
    C[Controller Board]\nC,throttle,steering,b1 --> BT[HC-05 Link]
    BT --> CAR[Car STM32 Firmware]
    CAR --> M[Motor PWM + Direction]
    CAR --> S[Servo PWM]
    CAR --> U[HC-SR04 Trigger/Echo]
    U --> CAR
    CAR -->|D:value| BT
    BT --> C
```

## Packet Protocol

### Controller -> Car

- Format: `C,<throttle_adc>,<steering_adc>,<b1_state>\n`
- Example: `C,2140,1860,1\n`

### Car -> Controller

- Format: `D:<distance_cm>\n` or `D:TOO FAR\n`
- Example: `D:42.3\n`

## Pin Map (From Current `.ioc` Configuration)

| Function | Peripheral/Pin | Notes |
|---|---|---|
| Bluetooth data | `USART1` | HC-05 control/data link |
| Debug console | `USART2` | `printf` routed here |
| Motor PWM | `TIM3 CH3` | Duty output |
| Motor direction | `PC6` | Direction GPIO |
| Servo PWM | `TIM4 CH2` | 50 Hz servo pulse |
| Ultrasonic trigger | `PC7` | HC-SR04 TRIG |
| Ultrasonic echo capture | `TIM1 CH1` | Input capture timing |
| Status LEDs | `PC8`, `PC9` | Toggled by remote button |

> Exact alternate-function pin routing is generated from `enel-300-parallax.ioc`.

## Build and Flash

This is a CubeMX/STM32CubeIDE-generated project.

1. Open `enel-300-parallax.ioc` in STM32CubeIDE
2. Build the project
3. Flash to the NUCLEO-F446RE target

`Debug/` already contains generated makefiles if you prefer command-line builds from CubeIDE toolchain environments.

## Demo and Documentation

- Demo media placeholders: `docs/media/`
- Wiring photos and notes: `docs/README.md`
- Architecture notes: `docs/architecture.md`
- LinkedIn copy-ready highlights: `LINKEDIN_HIGHLIGHTS.md`

## Project Layout

- `Core/Src/main.c`: Application logic (control RX, telemetry TX, motor/servo control)
- `Core/Inc/`: HAL and app headers
- `Drivers/`: STM32 HAL + CMSIS
- `Debug/`: Generated build artifacts

## Team Note

If you are sharing this publicly, add your final demo links and wiring photos in `docs/` before posting the repository URL.
