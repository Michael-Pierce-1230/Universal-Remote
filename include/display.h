
#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



class DisplayManager{
private:
    Adafruit_SSD1306 display; // Create display object (I2C)
    TwoWire I2CDisplay;
    int sdaPin;
    int sclPin;

public:
    DisplayManager(int sda = 19, int scl = 22);

    bool begin();
    void clear();
    // void showText(const String &text, int textS);
    
    void update();

    void pageLayout();

    void drawBatteryIcon(int x, int y, int level);

};

#endif