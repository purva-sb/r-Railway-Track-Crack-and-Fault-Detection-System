# Railway Track Crack and Fault Detection System Using GPS & GSM

An embedded systems project designed to detect railway track faults, stop the motor when a fault is detected, and send location-based SMS alerts to maintenance personnel using GPS and GSM modules.

## Project Overview

Railway track faults can lead to serious safety risks if they are not identified and reported promptly. This project demonstrates a sensor-based railway track fault detection system using an Arduino Nano.

The system monitors track conditions through sensors. When a fault is detected, it stops the motor, activates a buzzer, and sends an SMS alert containing GPS coordinates when a valid GPS fix is available.

## Project Objectives

- Detect railway track cracks or faults using sensors.
- Identify the location of a detected fault using GPS.
- Send SMS alerts through a GSM module.
- Stop the motor when a fault is detected.
- Provide local fault indication using a buzzer and LCD.

## Hardware Components

| Component | Purpose |
|---|---|
| Arduino Nano | Main controller for the system |
| IR Sensors | Detect track faults based on the implemented sensing arrangement |
| GPS Module (NEO-6M) | Provides geographical coordinates |
| GSM Module (SIM800/SIM900) | Sends SMS alerts |
| 16×2 LCD | Displays system status and GPS information |
| Relay Module | Controls the motor |
| DC Motor | Demonstrates the movement and stopping mechanism |
| Buzzer | Provides an audible fault alert |
| Rechargeable Battery | Supplies power to the system |

## Software and Technologies

- Embedded C / Arduino C++
- Arduino IDE
- TinyGPS Library
- SoftwareSerial Library
- LiquidCrystal Library
- GPS and GSM serial communication

## System Working

1. **System Initialization:** The Arduino Nano initializes the sensors, LCD, GPS, GSM, motor control, and buzzer.
2. **Track Monitoring:** The sensors continuously monitor the track according to the implemented detection arrangement.
3. **Fault Detection:** When either sensor is triggered, the Arduino identifies a fault condition.
4. **Motor Control:** The relay changes state to stop the motor.
5. **Fault Indication:** The buzzer activates and the LCD displays a track fault warning.
6. **Location Acquisition:** The GPS module provides latitude and longitude when a valid GPS fix is available.
7. **SMS Notification:** The GSM module sends a fault alert to the configured mobile number, including a Google Maps location link when GPS coordinates are available.
8. **System Reset:** When both sensors return to their normal state, the system resets the alert condition and resumes motor operation.

## Project Features

- Sensor-based railway track fault detection
- GPS-based location identification
- GSM-based SMS notification
- Automatic motor stopping during fault detection
- Audible and LCD-based fault indication
- Embedded hardware and software integration

## Block Diagram

```text
       IR Sensors
            |
            v
      Arduino Nano
       /    |     \
      /     |      \
     v      v       v
   Relay   Buzzer   LCD
     |
     v
   DC Motor

 GPS Module --------> Arduino Nano
                           |
                           v
                      GSM Module
                           |
                           v
                    SMS Fault Alert
                    with GPS Location
```

## Applications

- Railway track inspection prototypes
- Embedded safety monitoring systems
- Sensor-based fault detection
- GPS-enabled remote alert systems
- Educational projects involving microcontrollers and communication modules

## Limitations

- Detection performance depends on the sensors, their placement, and the track conditions.
- GPS location accuracy depends on satellite reception and environmental conditions.
- SMS delivery depends on GSM network coverage and modem operation.
- This is an academic prototype and is not certified for operational railway safety.

## Future Improvements

- Integrate camera-based inspection and computer vision.
- Explore Raspberry Pi or NVIDIA Jetson for edge AI processing.
- Implement advanced crack detection using image processing and machine learning.
- Add wireless monitoring and a maintenance dashboard.
- Improve fault detection reliability through additional sensors and testing.

## Project Images

The following images show the project hardware and implementation.

<img width="1600" height="900" alt="WhatsApp Image 2026-10-11 at 12 15 42 AM" src="https://github.com/user-attachments/assets/1a538c0d-8633-41f3-bc4b-4e0e9ec42cdc" />
<img width="720" height="1280" alt="WhatsApp Image 2026-10-11 at 12 15 42 AM,mn," src="https://github.com/user-attachments/assets/c2b90d0f-4035-44c2-9a46-aa3d410a853f" />
<img width="1600" height="900" alt="WhatsApp Image 2026-10-11 at 12 15 43 AM,n," src="https://github.com/user-attachments/assets/3ecc5b11-10e8-4eba-a733-4c7e738fd9c3" />
<img width="1600" height="567" alt="WhatsApp Image 2026-10-11 at 12 15 43 AMb" src="https://github.com/user-attachments/assets/61164f4b-db6a-4610-8e2c-d3e0a88e7d76" />

### Hardware Implementation

Add your uploaded project photographs here using the image filenames stored in the repository.

```markdown
![Railway Track Detection System](images/railway-track-system.jpg)
![Project Hardware](images/project-hardware.jpg)
```

Replace the example paths above with your actual image filenames and repository paths.


## Conclusion

This project demonstrates the integration of embedded systems, sensors, GPS, GSM communication, and motor control for railway track fault monitoring. It provides a foundation for further development of intelligent inspection systems and edge AI-based railway monitoring solutions.

---

**Project Domain:** Embedded Systems | Internet of Things (IoT) | Hardware Integration

**Controller:** Arduino Nano

**Programming:** Embedded C / Arduino C++
