# Vehicle Firmware and Hardware Documentation

This folder contains supporting documentation and media for the vehicle-side STM32 firmware and hardware integration.

The vehicle subsystem receives wireless commands from the controller, drives the DC motor and steering servo, measures distance using the HC-SR04 ultrasonic sensor, controls headlights, and supports integration with the metal detection subsystem.

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

Top view showing the internal layout of the vehicle, including PCB placement, wiring, battery positioning, and drivetrain integration.

---

## Vehicle PCB

![Vehicle PCB](media/car-pcb.png)

The vehicle PCB integrates the motor driver, voltage regulation, STM32 header connections, Bluetooth interface, and vehicle-side wiring. It acts as the main electrical integration board for propulsion, sensing, communication, and power distribution.

---

## Metal Detector PCB

![Metal Detector PCB](media/metal-detector-pcb.png)

The metal detector subsystem uses a separate PCB to reduce congestion on the vehicle PCB and simplify integration. The circuit provides buzzer feedback when metal is detected.

---

## Mechanical Chassis

![Vehicle Chassis](media/car-chassis.png)

The vehicle chassis was designed to support the drivetrain, steering mechanism, ultrasonic sensor, battery, PCB mounting, and wiring access. The chassis and mechanical components were designed for 3D printing and subsystem integration.

---

## Vehicle Subsystem Responsibilities

The vehicle-side STM32 firmware is responsible for:

- Receiving Bluetooth commands from the controller
- Parsing throttle, steering, and headlight commands
- Driving the DC motor through PWM and direction control
- Controlling the steering servo using PWM
- Triggering and reading the HC-SR04 ultrasonic sensor
- Sending distance telemetry back to the controller
- Supporting safe operation during communication loss or invalid command states

---

## Media Checklist

Current media in this folder:

```text
docs/media/
├── car-side.jpeg
├── car-front.jpeg
├── car-top.jpeg
├── car-pcb.png
├── metal-detector-pcb.png
└── car-chassis.png
