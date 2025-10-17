# 🛰️ Universal Remote (ESP32)

![Build](https://github.com/Michael-Pierce-1230/Universal-Remote/actions/workflows/build.yml/badge.svg)

A **smart universal remote** powered by the **ESP32** microcontroller.  
It can record and transmit IR signals, store them in profiles, and display status info on an OLED screen.

This project is designed to evolve into a **smart home remote** capable of controlling TVs, air conditioners, and eventually devices like Chromecast through Wi-Fi.

---

## ⚡ Features

- 🎛️ Multiple configurable **remote profiles**
- 📡 **IR transmission and recording**
- 🕹️ **Physical buttons** with software debounce
- 🖥️ **OLED display** for UI and battery status
- 🔋 **Battery-powered** operation with charging circuit support
- 💾 **Persistent profile storage** (planned via SPIFFS/JSON)
- 🌐 Future support for **Wi-Fi smart control**

---

## 🧠 System Overview

| Component | Description |
|------------|-------------|
| **ESP32** | Main microcontroller handling input/output and Wi-Fi |
| **IR LED & Receiver** | Send and capture remote control signals |
| **OLED Display (I2C)** | User interface for profiles and status |
| **Buttons** | Used for navigation and profile selection |
| **Battery + Charger (TP4056/TP4054)** | Portable power source with USB charging |

---

## 🧩 Software Architecture

```text
src/
├── main.cpp              → Initializes RemoteInterface and DisplayManager
├── RemoteInterface.cpp   → Handles input buttons and IR commands
├── DisplayManager.cpp    → Manages OLED display rendering
include/
├── RemoteInterface.h
├── DisplayManager.h
└── icons.h               → Bitmaps for UI symbols (battery, Wi-Fi, etc.)
