# Universal Remote

A programmable IR remote powered by an ESP32 microcontroller with OLED feedback, profile switching, and persistent configuration stored in JSON.

---

## 🧩 Features
- Supports multiple IR profiles (TV, soundbar, etc.)
- Stores configuration persistently in JSON (SPIFFS)
- OLED display for status and profile info
- Built in C++ using PlatformIO and Arduino framework

---

## ⚙️ Hardware
| Component | Description |
|------------|-------------|
| ESP32 DevKit V1 | Microcontroller |
| SSD1306 0.96" OLED | Display |
| CH340G | USB-to-Serial interface |
| IR LED & Receiver | Signal TX/RX |
| Buttons | Profile and command input |

---

## 🧠 Software Architecture
