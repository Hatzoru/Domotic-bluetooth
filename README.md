# ESP32 Security & Domotics System 🛡️🔥

## 📌 Project Overview
A smart home security prototype designed to detect environmental hazards and intrusions. The system uses an ESP32 microcontroller to monitor gas, smoke, motion, and temperature, sending real-time alerts to a mobile device.

## ⚙️ Tech Stack
- **Microcontroller:** ESP32.
- **Sensors:** 
  - MQ-2 (Flammable gas, smoke, and CO detection)
  - PIR SR501 (Motion detection)
  - DHT11 (Temperature and humidity)
- **Communication:** Bluetooth Classic (Bluetooth Terminal app).
- **Actuators:** Buzzer (Alarm), 2x 5V Relays (Exhaust fan and LED lights).

## 🔧 Key Features
- **Gas Alert:** Activates the exhaust fan and buzzer if gas levels exceed the calibrated threshold (using analog ADC reading).
- **Motion Alarm:** Triggers the buzzer if movement is detected while the system is armed.
- **Remote Control:** Used a Bluetooth terminal app to send characters ('a' to 'f') to turn lights on/off, arm alarms, or test sensors.
- **Custom Circuit:** Designed and simulated the entire schematic in Proteus before physical assembly.

## 📸 Media & Documentation
*(Replace these with actual links to your photos/videos)*
- [Photo: Prototype on the breadboard]
- [Photo: Schematics in Proteus]
- [Video: Testing the gas sensor with a lighter]

## 📝 What I Learned
- Programming microcontrollers using the Arduino IDE (C++).
- Interfacing analog and digital sensors with an ESP32.
- Using optocouplers (PC817) and transistors (BC548) for galvanic isolation and power stages.
- Technical documentation and field notebook tracking.
