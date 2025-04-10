# 🚗 Real-Time Vehicle Tracking System using ESP32 and GPS

A compact Arduino-based system that tracks a vehicle's real-time GPS location using an ESP32 board and displays coordinates on an OLED screen. This project can be expanded to send data to the cloud for live tracking.

---

## 📦 Project Structure

real-time-vehicle-tracking/ │ ├── oled_display_test/ # Code for testing OLED display │ └── L11-SourceCodeTestingtheOLEDdisplay.ino │ ├── board_testing/ # Code to verify ESP32 board functionality │ └── board_testing.ino │ ├── gps_tracking/ # Main GPS tracking logic │ └── gps_tracking_ESP32.ino │ ├── images/ # Add hardware setup or output screenshots ├── README.md ├── LICENSE └── .gitignore

---

## 🧰 Components Used

- ESP32 Dev Board  
- GPS Module (e.g., NEO-6M)  
- OLED Display (0.96" I2C, SSD1306)  
- Breadboard and Jumper Wires  
- Optional: USB cable for power and Serial Monitor

---

## 🔧 Required Arduino Libraries

Install these libraries from the **Arduino Library Manager**:

- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)  
- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)  
- [TinyGPS++](https://github.com/mikalhart/TinyGPSPlus)

---

## 🛠️ Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/MayuriMotwani/real-time-vehicle-tracking.git
cd real-time-vehicle-tracking
2. Open .ino Files
Use the Arduino IDE and open one of the following:

For display testing: oled_display_test.ino

For board checking: board_testing.ino

For full GPS tracking: gps_tracking_ESP32.ino

3. Select Board & Port
Board: ESP32 Dev Module

Upload Speed: 115200

Port: As assigned by your OS

4. Upload & Monitor
Upload the code to your ESP32 board

Open the Serial Monitor at 115200 baud

Watch real-time GPS coordinates appear

🚀 Future Improvements
Send GPS coordinates to a cloud server or Firebase

Add SMS alerts using GSM

Display location on a mobile/web map using MQTT or HTTP

👤 Author
Mayuri Motwani
🔗 GitHub

📄 License
Licensed under the MIT License.
