# Timer-Driver--ADAS-Graduation-Project-
This repository contains the embedded C firmware developed for the STM32F103C6. It includes key ADAS functionalities such as: Automatic Emergency Braking (AEB), Blind Spot Detection and  Ultrasonic Sensor.

---

## 📦 Features

- **🛑 Automatic Emergency Braking (AEB)**  
  Real-time obstacle detection using ultrasonic sensors with active braking control.

- **🕶️ Blind Spot Detection**  
  Left-side detection with LED indicators using threshold-based distance logic.

- **🚘 Adaptive Cruise Control (ACC)**  
  Maintains vehicle speed and safe following distance using PWM and ultrasonic feedback.

---

## 📁 Project Structure

```text
STM32/
├── RTOS/
│   ├── Src/
│   │   ├── CortexMx_OS_porting.c   # ARM-specific low-level context switching
│   │   ├── Scheduler.c             # Task creation, states, and scheduling
│   │   └── MY_RTOS_FIFO.c          # FIFO structure for managing ready tasks
│   └── Inc/
│       ├── CortexMx_OS_porting.h
│       ├── Scheduler.h
│       └── MY_RTOS_FIFO.h
│
├── Drivers/
│   ├── ACC/
│   │   ├── ACC.c                   # Adaptive Cruise Control implementation
│   │   └── ACC.h
│   ├── BlindSpot&AEB/
│   │   ├── BlindSpot&AEB.c         # Blind spot detection & emergency braking
│   │   └── BlindSpot&AEB.h
│   ├── GPS/
│   │   ├── GPS.c                   # GPS data transmission logic
│   │   └── GPS.h
│   ├── GPIO/
│   │   ├── GPIO.c                  # GPIO pin configuration and control
│   │   └── GPIO.h
│   ├── RCC/
│   │   ├── RCC.c                   # Reset and clock control
│   │   └── RCC.h
│   └── UART/
│       ├── UART.c                  # UART configuration and data transmission
│       └── UART.h
│
├── main.c                          # Main application: initializes hardware, creates and starts tasks
```




---

## 🛠️ Technologies Used

### Hardware

* **Microcontroller:** STM32F103C6T6 (ARM Cortex-M3)

* **Sensors:** Ultrasonic Sensors (HC-SR04)
  

### Software

* **Development Environment:** STM32CubeIDE

* **Programming Language:** C

* **Operating System:** Custom Real-Time Operating System (RTOS) (written from scratch)

* **Communication Protocols:** UART (for GPS, Bluetooth)

* **Peripherals:** GPIO, TIM (Timers)
---

## 🚦 System Overview

### 🧠 Task Scheduling

- The RTOS supports:
  - Task creation with a defined stack size and priority
  - Task waiting (delay-based blocking)
  - Cooperative multitasking with PendSV-based context switching

### 📡 Communication Flow

| Module       | Direction | Protocol | Target           |
|--------------|-----------|----------|------------------|
| Ultrasonic   | -         | GPIO + Timer Input Capture | MCU-internal |

---

## 🚀 Getting Started

### 1. Clone the repo
```bash
git clone https://github.com/Graduation-Project-Automotive-ECE25/STM32.git
```

### 2. Open with STM32CubeIDE

Import the project into **STM32CubeIDE** and flash it to your **STM32F103C6T6** development board.

### 3. Hardware Setup

- Connect **ultrasonic sensors** to appropriate GPIO pins  

---

## 🧠 Main Tasks in `main.c`

| Task Name               | Description                                     |
|------------------------|-------------------------------------------------|
| `UltraSonic_Triggering()` | Triggers all ultrasonic sensors at fixed intervals |
| `BlindSpot_and_AEB()`  | Processes ultrasonic readings for blind spot & emergency braking logic |
