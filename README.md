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
<img width="899" height="1599" alt="f1" src="https://github.com/user-attachments/assets/e62d8735-90ad-4990-b556-03ab350b13c9" />
<img width="290" height="447" alt="f2" src="https://github.com/user-attachments/assets/ff4b33b6-24b9-4301-b629-de73cd528a8b" />
<img width="900" height="1600" alt="f3" src="https://github.com/user-attachments/assets/75f94b45-caa9-409f-981e-1a83ddcdeabe" />
<img width="1599" height="899" alt="f4" src="https://github.com/user-attachments/assets/ac4f027a-7f14-468d-bdaa-73e496f9c033" />
<img width="899" height="1599" alt="f5" src="https://github.com/user-attachments/assets/10f028eb-51e3-421f-aab0-36bec1dfcb47" />
<img width="900" height="1600" alt="f6" src="https://github.com/user-attachments/assets/bd8c909a-c51d-485e-a267-da0fb8e49bbd" />
<img width="900" height="1600" alt="f7" src="https://github.com/user-attachments/assets/1d33e9aa-d5ce-4c75-8c5f-06c54a937361" />
<img width="1600" height="900" alt="f8" src="https://github.com/user-attachments/assets/e0fdd8a6-0cdd-4eda-871e-48edf0e2ded9" />



https://github.com/user-attachments/assets/dd6aad47-a3e8-453a-8134-b2874645ebad



https://github.com/user-attachments/assets/d401edcd-4f7a-49cf-82d0-dca85f329f79



https://github.com/user-attachments/assets/303591d0-7f66-4819-aa7c-8c3b71f97572



https://github.com/user-attachments/assets/8e4576c8-b027-40ff-832a-38b9081a313c





## 📝 What I Learned
- Programming microcontrollers using the Arduino IDE (C++).
- Interfacing analog and digital sensors with an ESP32.
- Using optocouplers (PC817) and transistors (BC548) for galvanic isolation and power stages.
- Technical documentation and field notebook tracking.
