# Car Firmware Architecture Notes

## Runtime Loop Responsibilities

- Poll control UART and parse `C,...` packets
- Trigger ultrasonic measurement at fixed interval
- Send distance telemetry (`D:...`) at fixed interval
- Apply failsafe stop if control stream times out

## Control Path

1. Parse throttle/steering/button from incoming packet
2. Map ADC-centered values to motor percent and servo pulse width
3. Drive motor direction + PWM and servo PWM
4. Update status LEDs on button edge transitions

## Sensor Path

1. Send 10 us trigger pulse to HC-SR04
2. Use timer input capture to measure echo pulse width
3. Convert pulse width to centimeters
4. Publish formatted text frame to controller

## Timing Constants

- `ULTRASONIC_TRIGGER_PERIOD_MS`
- `DISTANCE_TX_PERIOD_MS`
- `CONTROL_FAILSAFE_MS`

These constants are grouped in `Core/Src/main.c` for easy tuning.
