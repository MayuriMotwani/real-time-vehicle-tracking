# 🚗 Real-Time Vehicle Tracking System using ESP32 and GPS

A compact Arduino-based system that tracks a vehicle's real-time GPS location using an ESP32 board and displays coordinates on an OLED screen. This project can be expanded to send data to the cloud for live tracking.

---

## 📦 Project Structure

```
real-time-vehicle-tracking/
│
├── oled_display_test/            # Code for testing OLED display
│   └── L11-SourceCodeTestingtheOLEDdisplay.ino
│
├── board_testing/                # Code to verify ESP32 board functionality
│   └── board_testing.ino
│
├── gps_tracking/                 # Main GPS tracking logic
│   └── gps_tracking_ESP32.ino
│
├── images/                       # hardware setup or output screenshots
├── README.md
├── LICENSE
```

---

## 🧰 Components Used

- ESP32 Dev Board  
- GPS Module (e.g., NEO-6M)  
- OLED Display (0.96" I2C, SSD1306)  
- Jumper Wires  
- Optional: USB cable for power and Serial Monitor

---

## 🔧 Required Arduino Libraries

Install the following libraries from the **Arduino Library Manager**:

- [ESP32 by Espressif Systems](https://github.com/espressif/arduino-esp32)  
  > Board package for ESP32 microcontrollers. Add it via **Board Manager** using the URL:  
  > `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`

- [ESP8266 and ESP32 OLED driver for SSD1306 displays](https://github.com/ThingPulse/esp8266-oled-ssd1306)  
  > Lightweight library to control 0.96" OLED displays with I2C interface.

- [TinyGPS++](https://github.com/mikalhart/TinyGPSPlus)  
  > For parsing GPS data from NEO-6M module.

- [Blynk Library](https://github.com/blynkkk/blynk-library)  
  > Used to send real-time GPS data to the Blynk IoT platform via internet (WiFi).

---

## 🛠️ Getting Started

### 🔹 Step 1: Clone the Repository

```bash
git clone https://github.com/MayuriMotwani/real-time-vehicle-tracking.git
cd real-time-vehicle-tracking
```

### 🔹 Step 2: Open `.ino` Files in Arduino IDE

- For OLED display test: `oled_display_test.ino`  
- For ESP32 board check: `board_testing.ino`  
- For full GPS tracking: `gps_tracking_ESP32.ino`

### 🔹 Step 3: Select Board & Port

- **Board**: `ESP32 Dev Module`  
- **Upload Speed**: `115200`  
- **Port**: Select the one assigned by your OS

### 🔹 Step 4: Upload & Monitor

- Upload the code to your ESP32  
- Open **Serial Monitor** at `115200` baud  
- Watch live GPS data stream in real time

---
## 📲 Blynk Integration

This project uses the [Blynk IoT platform](https://blynk.io) to display live GPS data on your mobile device.

### 🔧 Setup Steps:

1. **Download Blynk App** (iOS or Android)
2. **Create a new template/project**
3. Add **two Value Display widgets** for:
   - Latitude (V0)
   - Longitude (V1)
4. Copy your **Auth Token**
5. In `gps_tracking_ESP32.ino`, replace the following:
   ```cpp
   char auth[] = "YourAuthToken";
   char ssid[] = "YourWiFiSSID";
   char pass[] = "YourWiFiPassword";
   ```
6. Upload and open Serial Monitor to verify connection.
7. View live location data on Blynk!

---
## 📸 Images

![Hardware Setup](images/hardware_setup.jpg)

---

## 🚀 Features

- ✅ Real-time GPS data transmission to Blynk mobile dashboard
- 🌍 View live coordinates on your smartphone
- 🔔 Trigger events or location-based automation via Blynk

---

## 👤 Author

**Mayuri Motwani**  
🔗 [GitHub Profile](https://github.com/MayuriMotwani)

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).
```
