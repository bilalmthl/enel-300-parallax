# Vehicle Firmware and Hardware Documentation

This folder contains supporting documentation and media for the vehicle-side STM32 firmware and hardware integration.

The vehicle subsystem receives wireless commands from the controller, drives the DC motor and steering servo, measures distance using the HC-SR04 ultrasonic sensor, controls headlights, and supports integration with the metal detection subsystem.

---

## Vehicle Overview

The vehicle is built around an **STM32 NUCLEO-F446RE** and integrates wireless communication, motor control, servo steering, ultrasonic distance sensing, metal detection feedback, custom PCB hardware, and onboard battery power.

The car receives throttle, steering, and headlight commands from the controller through an **HC-05 Bluetooth UART link**. The vehicle-side STM32 then controls the motor driver, steering servo, headlights, and ultrasonic sensing behavior.

---

## Demo

### Drive Circuit Demo

[Watch Drive Circuit Demo](media/car-drive-circuit1.mp4)

This demo shows the vehicle completing a drive circuit using wireless controller input, PWM motor control, and servo-based steering.

---

## Final Vehicle

### Side View

![Vehicle Side View](media/car-side.jpeg)

Final vehicle assembly showing the STM32-based control system, onboard power, custom PCB hardware, Bluetooth communication, ultrasonic sensing, and mechanical chassis integration.

### Front View

![Vehicle Front View](media/car-front.jpeg)

Front view showing the HC-SR04 ultrasonic sensor placement, front steering geometry, and vehicle structure.

### Top View

![Vehicle Top View](media/car-top.jpeg)

Top view showing the internal layout of the vehicle, including PCB placement, wiring, battery positioning, drivetrain integration, and major subsystem organization.

---

## Vehicle PCB

![Vehicle PCB](media/car-pcb.png)

The vehicle PCB integrates the motor driver, voltage regulation, STM32 header connections, Bluetooth interface, and vehicle-side wiring. It acts as the main electrical integration board for propulsion, sensing, communication, and power distribution.

Key functions:

- Routes battery power to vehicle subsystems
- Supports regulated low-voltage power distribution
- Interfaces STM32 signals with the motor driver
- Provides organized wiring for Bluetooth, motor control, and sensor connections
- Reduces loose wiring during full-system integration

---

## Metal Detector PCB

![Metal Detector PCB](media/metal-detector-pcb.png)

The metal detector subsystem uses a separate PCB to simplify integration and reduce congestion on the main vehicle PCB. The circuit provides buzzer feedback when metal is detected.

This subsystem was kept electrically separate from the main STM32 control PCB, making it easier to test and integrate independently.

---

## Mechanical Chassis

![Vehicle Chassis](media/car-chassis.png)

The vehicle chassis was designed to support the drivetrain, steering mechanism, ultrasonic sensor, battery, PCB mounting, and wiring access.

The chassis and supporting mechanical components were designed for 3D printing and subsystem integration. The layout provides dedicated space for the battery, electronics, sensing hardware, steering mechanism, and rear drivetrain.

---

## Vehicle Subsystem Responsibilities

The vehicle-side STM32 firmware is responsible for:

- Receiving Bluetooth commands from the controller
- Parsing throttle, steering, and headlight commands
- Driving the DC motor using PWM and direction control
- Controlling the steering servo using PWM
- Triggering and reading the HC-SR04 ultrasonic sensor
- Sending distance telemetry back to the controller
- Controlling headlights
- Supporting safe behavior during communication loss or invalid command states

---

## Vehicle Communication Flow

```text
Controller STM32
      ↓
HC-05 Bluetooth UART Link
      ↓
Vehicle STM32
      ↓
Command Parsing
      ↓
Motor, Servo, Headlight, and Sensor Updates
```

Return telemetry:

```text
HC-SR04 Ultrasonic Sensor
      ↓
Vehicle STM32
      ↓
Bluetooth UART Link
      ↓
Controller STM32
      ↓
LCD Display
```

---

## Hardware Interfaces

| Interface | Purpose |
|---|---|
| UART | Receives Bluetooth commands and sends telemetry |
| PWM | Controls DC motor speed and steering servo position |
| GPIO | Controls direction signals, headlights, and digital outputs |
| Timer input capture / timing logic | Measures HC-SR04 echo pulse timing |
| Power regulation | Supports low-voltage electronics from the vehicle battery system |
| Motor driver interface | Allows STM32 logic to control the higher-current drive motor |

---

## Testing and Validation

The vehicle subsystem was tested through staged validation before full integration:

1. STM32 board bring-up
2. UART Bluetooth communication testing
3. Motor driver and PWM validation
4. Servo steering validation
5. HC-SR04 ultrasonic distance measurement
6. Headlight control testing
7. Metal detector buzzer activation
8. Battery-powered full-system testing
9. Final competition drive testing

---

## Media in This Folder

```text
docs/media/
├── car-side.jpeg
├── car-front.jpeg
├── car-top.jpeg
├── car-pcb.png
├── metal-detector-pcb.png
├── car-chassis.png
└── car-drive-circuit1.mp4
```

---

## Notes for Future Updates

Recommended future additions:

```text
docs/media/
├── demo-drive.gif
├── wiring-top.jpeg
├── wiring-labels.jpeg
├── vehicle-block-diagram.png
├── ultrasonic-demo.mp4
└── failsafe-demo.mp4
```

Before linking this repository on a resume or LinkedIn, it would be useful to add a short demo showing:

- Steering and throttle response
- Bluetooth command control
- Distance telemetry update
- Labeled wiring overview
- Failsafe behavior if available
