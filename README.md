# STM32 Radio-Controlled Car with Metal Detection & Distance Sensing  
**ENEL 300 – Winter 2026 Course Project**  
Second-year Electrical Engineering project at the University of Calgary  

---

## Overview

This project involves the design and implementation of a wirelessly controlled embedded vehicle capable of metal detection, object distance measurement, and real-time control.

The system was developed using the STM32 NUCLEO-F446RE platform and integrates sensing, actuation, and communication subsystems into a fully functional prototype designed to meet strict engineering constraints.

The project culminates in a final competition involving navigation, sensing, and performance tasks.

---

## Project Objectives

The system was designed to satisfy the following core requirements:

- Wireless remote control of the vehicle  
- Forward motion and steering capability  
- Detection of copper plates (metal detection)  
- Measurement of object distance (up to 80 cm)  
- Real-time display of distance readings  
- Audible response upon metal detection  
- Headlight control functionality  
- Fully self-powered operation  

---

## System Features

### 🔹 Wireless Control (HC-05)
- Real-time bidirectional Bluetooth communication  
- Custom-built controller  
- Command packet processing and fail-safe handling  

### 🔹 Motor & Steering Control
- PWM-based DC motor control using motor driver  
- Servo-based steering control  
- Smooth real-time actuation  

### 🔹 Distance Sensing (HC-SR04)
- Measures object distance up to 80 cm  
- Timer Input Capture for precise echo timing  
- Approximate accuracy of ±2.5 cm  

### 🔹 Metal Detection System
- Detects copper plates embedded in the track  
- Triggers audible alert upon detection  
- Silent when no metal is present  

### 🔹 Fail-Safe Mechanism
- Stops motor and centers steering on signal loss  
- Ensures safe operation  

---

## System Architecture

### Hardware Components
- Microcontroller: STM32 NUCLEO-F446RE  
- Communication: HC-05 Bluetooth Module  

**Sensors:**
- HC-SR04 Ultrasonic Sensor  
- Custom Metal Detection Circuit  

**Actuators:**
- DC Motor (Injora 55T) (rear drive) 
- Servo Motor (steering)  

**Additional:**
- Buzzer  
- Headlight system  

---

## Firmware Design

### Core Modules

**UART Communication**
- UART1: Bluetooth  
- UART2: Debugging  

**PWM Control**
- Motor speed control  
- Servo steering control  

**Ultrasonic Measurement**
- Timer Input Capture  
- Periodic triggering (~80 ms)  

**Control Logic**
- Parses controller inputs  
- Maps inputs to motor and steering  
- Implements timeout-based fail-safe  

---

## Competition Tasks

### Circuit 1: Sensing & Detection
- Navigate within a 2 m × 2 m boundary  
- Detect copper plates  
- Measure distance to objects  
- Display readings  

### Circuit 2: Mobility Challenge
- Drive 10 m forward and return  
- Traverse a ramp (~20° incline)  

---

## Design Constraints

- Maximum budget: $120 CAD  
- Must include a custom PCB  
- Must include at least one 3D-printed component  
- Arduino platform not allowed  
- Custom controller required  

---

## Key Engineering Challenges

- Reliable Bluetooth communication  
- Accurate ultrasonic timing  
- Real-time system integration  
- Debugging embedded hardware/software interaction  

---

## Results

- Stable wireless control  
- Accurate distance sensing  
- Reliable metal detection  
- Fully integrated working system  

---

## How to Run

1. Open project in STM32CubeIDE  
2. Build and flash firmware  
3. Pair HC-05 modules  
4. Power the system  

---

## Future Improvements

- Closed-loop motor control with encoders  
- Improved communication protocol (CRC)  
- Autonomous navigation  
- Sensor fusion  

---

## Contributors

- Saad Subhani  
- Bilal Melethil  
- Ammaar Khaleel  
