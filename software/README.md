# Software and Data Integration

This directory contains the Python-based software components developed for the CGM prototype.

## Components

### Firebase Communication Bridge
- Establishes communication between the ESP32 and Python.
- Receives sensor measurements through serial communication.
- Transfers acquired data to Firebase Realtime Database.
- Supports remote measurement logging.

### Data Processing
- Processes acquired sensor measurements.
- Handles ADC-to-voltage conversion and sensor-current calculations where implemented in Python.
- Supports measurement analysis and visualization.

## Data Parameters

The system logs parameters including:

- ADC raw values
- TIA output voltage (mV)
- Sensor current (µA)
- Device ID
- Battery status
- Timestamp

## Technologies

- Python
- Firebase Realtime Database
- PySerial
- NumPy / Pandas (where used)

## Setup

Install the required dependencies:

```bash
pip install -r requirements.txt
```

Configure Firebase credentials locally before running the communication bridge.

**Security:** Firebase credentials and private configuration files must not be committed to this repository.
