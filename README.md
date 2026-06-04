# Bluetooth-Controlled Wireless LED Notice Board

An independent engineering project designed and developed to allow users to send notices wirelessly from an Android app to a P10 LED matrix display using Bluetooth.

## How it works:
- **Wireless Connection:** An HC-05 Bluetooth module receives raw text characters from a paired Android application and streams them directly to the Arduino UNO via serial UART pins (Rx/Tx).
- **Buffer Parsing:** The Arduino control code checks the incoming serial buffer, extracts the message string, and handles the data logic.
- **Display Output:** The parsed text is converted into pixel configurations and scrolled smoothly across a P10 LED matrix display panel.
- **Power Unit:** Powered via a dedicated 5V 3A SMPS power supply because the LED matrix draws too much current to run off the Arduino development board safely.

## Developer:
- **Abhijeet Patil**
- Department of ECE, MIT School of Engineering (MIT-ADT University)
