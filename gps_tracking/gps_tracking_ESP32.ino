#define BLYNK_TEMPLATE_ID "Your Template ID"
#define BLYNK_DEVICE_NAME "Your Blynk Device Name"
#define BLYNK_AUTH_TOKEN "Your Blynk Authorization Token"

char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
char ssid[] = "Your WIFI Name";
char pass[] = "Your WIFI Password";

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include "SSD1306.h" 

//GPS Module Settings
#include <TinyGPS++.h> 
#define RXD2 16
#define TXD2 17
HardwareSerial neogps(2);
TinyGPSPlus gps;
BlynkTimer timer;
SSD1306  display(0x3c, 21, 22);

#define INTERVAL 1000L
/************************************************************************************
 *  This function sends Arduino's up time every second to Virtual Pin.
 *  In the app, Widget's reading frequency should be set to PUSH. This means
 *  that you define how often to send data to Blynk App.
 **********************************************************************************/
void sendGps()
{
  //-----------------------------------------------------------
  while(neogps.available())
  {
    if (gps.encode(neogps.read()))
    {
      break;
    }
  }
  //-----------------------------------------------------------
  if (!gps.location.isValid())
  {
    Serial.println("Please wait... Waiting for the GPS to connect.");
    //display.init();
    //display.clear();
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 0, "Please wait ....");
    display.drawString(0, 25, "Waiting for the");
    display.drawString(0, 45, "GPS to connect.");
    display.display();
    return;
  }
  
  //get latitude and longitude
  float latitude = gps.location.lat();
  float longitude = gps.location.lng();
  float speed = gps.speed.kmph();
  String  lati_str , longi_str, speed_track;
  
  //used for debugging in serial monitor
  Serial.print("Latitude:  ");
  Serial.println(latitude, 6);
  Serial.print("Longitude: ");
  Serial.println(longitude, 6);
  Serial.print("Speed: ");
  Serial.println(speed, 6);

// Prnting on the OLED display
  lati_str = String(latitude , 6);
  longi_str = String(longitude , 6);
  speed_track = String(speed,6);
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_16);
  display.drawString(0, 5, "LAT:");
  display.drawString(45, 5, lati_str);
  display.drawString(0, 25, "LON:");
  display.drawString(45, 25, longi_str);
  display.drawString(0, 45, "SPD:");
  display.drawString(45, 45, speed_track);
  display.display();

// Writing on cloud
  Blynk.virtualWrite(V1, String(latitude, 6));
  Blynk.virtualWrite(V2, String(longitude, 6));
  Blynk.virtualWrite(V0, String(speed));
}

void setup()
{
  //Debug console (Serial Monitor)
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  //Initializing the OLED display 
  display.init(); 

  //Set GPS module baud rate
  neogps.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial.println("neogps serial initialize");
  delay(10);
  
  // Setup a function to be called every second
  timer.setInterval(INTERVAL, sendGps);
}

void loop()
{
  Blynk.run();
  timer.run();
}