#include "display.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_ADDR 0x3C

DisplayManager::DisplayManager(int sda, int scl)
    : display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1), sdaPin(sda), sclPin(scl), I2CDisplay(TwoWire(0)){}

bool DisplayManager::begin(){
    // Start I2C
    Wire.begin(sdaPin, sclPin);
    Serial.println(sdaPin);

    // Initialize OLED
    
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) { // 0x3C is the default I2C address
    Serial.println(F("SSD1306 allocation failed"));
    return false;
  }

//   clear();
//   update();

  return true;

}

void DisplayManager::clear(){
    display.clearDisplay();
}

void DisplayManager::update(){
    display.display();           // Push buffer to screen
}

  // Serial.println("Starting OLED test...");

  // // Initialize OLED
  // if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C is the default I2C address
  //   Serial.println(F("SSD1306 allocation failed"));
  //   for (;;);
  // }

  // display.clearDisplay();
  // display.setTextSize(2);      // Text size multiplier
  // display.setTextColor(SSD1306_WHITE); // White text
  // display.setCursor(0, 10);    // x, y position
  // display.println(F("Hello!"));
  // display.display();           // Push buffer to screen

  // delay(2000);
  
  // // Update text dynamically
  // display.clearDisplay();
  // display.setTextSize(1);
  // display.setCursor(0, 0);
  // display.println("ESP32 OLED Demo");
  // display.println("Line 2 text");
  // display.println("Line 3 text");
  // display.display();
  

  void DisplayManager::pageLayout(){
    // create page here
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println("Time   WIFI   Battery");
    // display.println(" ");
    // display.println("Selected profile");
    // display.drawBitmap(10, 10, wifiIcon, 5, 5, SSD1306_WHITE);
    update();


  }

  void DisplayManager::drawBatteryIcon(int x, int y, int level) {
    const unsigned char* icon;

    switch (level) {
        case 0:
            icon = battery_empty;
            break;
        case 1:
            icon = battery_half;
            break;
        default:
            icon = battery_full;
            break;
    }

    // clear();
    display.drawBitmap(x, y, icon, 8, 8, SSD1306_WHITE);
    display.display();
}