# Bluetooth-Controlled Wireless LED Notice Board 📢

An embedded hardware project designed to display wireless text notices on a P10 LED matrix display sent from an Android smartphone via Bluetooth.

---

## ⚙️ How It Works

1. **Wireless Reception:** An **HC-05 Bluetooth module** receives text data wirelessly from a paired Android app and streams it directly to the Arduino UNO via serial UART pins (`Rx` / `Tx`).
2. **Buffer Parsing:** The control firmware checks the incoming serial buffer, extracts the message string, and manages scrolling speed/display logic.
3. **Display Driving:** The parsed text is converted into pixel configurations and scrolled smoothly across a **P10 LED matrix display panel**.
4. **Power Management:** Powered via a dedicated **5V 3A SMPS** power supply because the LED matrix draws too much current to run off the Arduino development board safely.

---

## 🛠️ Hardware Stack & Components

* **Microcontroller:** ATmega328P / Arduino UNO
* **Communication Module:** HC-05 Bluetooth Module (UART Serial Interface)
* **Display Panel:** P10 Single-Color (Red) LED Matrix Display Panel (32x16 resolution)
* **Power Supply:** 5V 3A DC SMPS Adapter
* **Language:** C / C++ (Embedded AVR C / Arduino Framework)

---

## 📂 Repository Structure

Wireless-notice-board/
│
├── notice-board.c           # Main firmware code handling UART and display logic
├── README.md                # Project documentation
├── Hardware-picture.jpeg    # Hardware wiring and assembly image
└── Hardware-working.mp4     # Video demonstration of the working notice board

---

## 🔌 Circuit Pin Connections

| HC-05 Module | Arduino UNO |
| :--- | :--- |
| `TX` | `RX` (Pin 0) |
| `RX` | `TX` (Pin 1) |
| `VCC` | `5V` |
| `GND` | `GND` |

> **Note:** Disconnect the `RX` / `TX` pins of the HC-05 module while uploading code to the Arduino via USB to prevent UART flashing conflicts.
