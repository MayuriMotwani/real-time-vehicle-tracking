#include <Wire.h>
#include "SSD1306.h" 
 
SSD1306  display(0x3c, 21, 22);
 
void setup() {
 
  display.init();
  display.drawString(0, 0, "This is an E-Learning");
  display.drawString(0, 12, "Organization.");
  display.drawString(0, 32, "The testing of OLED is");
  display.drawString(0, 44, "Successful.");
  display.display();
}
 
void loop() {}
