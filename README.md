# Indigenous Continuous Glucose Monitoring (CGM) System

**Electrochemical Sensor Interface | Custom Analog Front End | PCB Design | ESP32 | IoT**

## Overview

This project focuses on the development of an indigenous Continuous Glucose Monitoring (CGM) prototype using an electrochemical sensing interface, a custom Analog Front End (AFE), and an ESP32-based embedded acquisition system.

The work involved studying and reverse-engineering a commercial CGM sensor interface, developing custom signal-conditioning circuitry, designing PCBs, acquiring low-level electrochemical sensor signals, and implementing remote data logging using Firebase.

The primary engineering focus was on analog signal acquisition, sensor interfacing, hardware development, and embedded data processing.

## System Architecture

![System Architecture](docs/system_architecture.png)

The system follows this signal acquisition pipeline:

1. Electrochemical glucose sensor
2. Custom potentiostat and Transimpedance Amplifier (TIA)
3. Analog-to-Digital Conversion
4. ESP32-based data acquisition
5. Python communication bridge
6. Firebase Realtime Database

## Technical Contributions

### 1. Electrochemical Sensor Interface
- Studied the working principle of electrochemical glucose sensors.
- Investigated the three-electrode sensing architecture: Working Electrode (WE), Reference Electrode (RE), and Counter Electrode (CE).
- Reverse-engineered the interface of a commercial CGM sensor.
- Investigated sensor current characteristics and electrical response.

### 2. Custom Analog Front End (AFE)
- Designed a custom analog front end for electrochemical signal acquisition.
- Developed Transimpedance Amplifier (TIA) circuits for converting low-level sensor currents into measurable voltages.
- Worked on virtual ground generation and precision voltage referencing.
- Investigated gain selection, signal conditioning, and analog stability.
- Simulated circuit behavior using LTSpice.

### 3. PCB Design and Hardware Development
- Designed circuit schematics and PCB layouts using KiCad.
- Integrated analog signal-conditioning stages, ADC interfacing, voltage regulation, and sensor connectors.
- Worked on grounding, power distribution, and analog signal routing.
- Prepared BOMs and Gerber manufacturing files.
- Evaluated PCB fabrication and assembly requirements.

### 4. Embedded Systems and Data Acquisition
- Developed ESP32 firmware for sensor data acquisition.
- Implemented ADC sampling and voltage conversion.
- Processed sensor measurements using filtering techniques.
- Calculated sensor current from the measured TIA output and feedback resistance.
- Implemented serial communication for transferring measurement data.

### 5. IoT and Remote Data Monitoring
- Developed a Python-based communication bridge.
- Integrated sensor measurements with Firebase Realtime Database.
- Implemented real-time logging of ADC values, TIA voltage, sensor current, and device status.

## Hardware Components

| Component | Application |
|---|---|
| ESP32 | Embedded controller |
| Operational Amplifiers | Custom analog front end |
| ADS1115 | External ADC |
| LM4040 | Precision voltage reference |
| AP2112K-3.3 | Voltage regulation |
| TVS / ESD Protection | Circuit protection |
| Electrochemical Sensor | Glucose sensing interface |

*Component selection may vary across prototype revisions.*

## Software and Tools

- **PCB Design:** KiCad
- **Circuit Simulation:** LTSpice
- **Embedded Development:** Arduino IDE, C/C++
- **Microcontroller:** ESP32
- **Data Processing:** Python
- **Database:** Firebase Realtime Database
- **Communication:** Serial Communication

## Experimental Results

The prototype was tested for electrical signal acquisition and sensor-current measurement.

Example measurements:

| ADC Reading | TIA Output | Sensor Current |
|---:|---:|---:|
| 111 | 89.45 mV | 4.47 µA |
| 251 | 202.27 mV | 10.11 µA |

The measurements demonstrate the acquisition and conversion of low-level sensor currents into digital readings.

Additional characterization data and measurement plots are available in the `results/` directory.

## Repository Structure

```text
├── docs/          # Project documentation
├── hardware/      # Schematics, PCB layouts and BOM
├── firmware/      # ESP32 firmware
├── software/      # Python and Firebase integration
├── simulation/    # LTSpice simulations
├── results/       # Experimental data and plots
└── images/        # Prototype and PCB photographs
```

## Current Development Status

The project covers prototype-level electronics development, analog signal acquisition, embedded firmware, and remote data logging.

Further work is required for:
- Sensor-specific glucose calibration.
- Long-term sensor stability and drift characterization.
- Temperature compensation.
- Measurement accuracy and repeatability evaluation.
- Clinical validation and safety evaluation.

**Note:** This is an electronics development prototype and is not a clinically validated glucose monitoring device. Its readings should not be used for medical decisions.

## Acknowledgements

Developed as part of research and hardware development work at the Centre for Nanotechnology, IIT Guwahati.

