# ESP32 Firmware

This directory contains the embedded firmware developed for the CGM prototype.

## Responsibilities

- Interface with the analog front-end circuit.
- Acquire ADC measurements from the sensor interface.
- Convert ADC readings into voltage values.
- Calculate sensor current using the TIA feedback resistance.
- Apply measurement filtering and data processing.
- Transmit acquired measurements through serial communication.

## Hardware

- ESP32
- Custom Analog Front End
- External ADS1115 ADC (where applicable)

## Development Environment

- Arduino IDE
- C/C++
- ESP32 Arduino Core

## Note

The firmware is intended for prototype-level sensor acquisition and experimentation. Glucose calibration is a separate development stage.
