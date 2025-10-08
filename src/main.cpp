#include "RemoteInterface.h"
#include "ButtonMap.h"
// OLED library
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

// Create display object (I2C)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Optional: custom I2C pins (uncomment if not using 21/22)
TwoWire I2CDisplay = TwoWire(0);


const int TX_PIN = 17;
const int RX_PIN = 16;

void setup();
void loop();

// RemoteInterface remote(TX_PIN, RX_PIN);
RemoteInterface remote(TX_PIN, RX_PIN);


int main(){
  init();

  setup();

  loop();

  return 0;
}

void setup(){
  Serial.begin(115200);
  // int numProfiles = sizeof(remote.profiles)/ sizeof(remote.profiles[0]);
  // setup ir transmitter
  remote.begin();
  // remote.IRReceiveState(true); //Enable to receive rx data
  Serial.println("Starting OLED test...");

  // Start I2C (default pins 21=SDA, 22=SCL)
  Wire.begin(19, 22);
  // Wire.begin(19, 18); // Example if you wanted to use other pins

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C is the default I2C address
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(2);      // Text size multiplier
  display.setTextColor(SSD1306_WHITE); // White text
  display.setCursor(0, 10);    // x, y position
  display.println(F("Hello!"));
  display.display();           // Push buffer to screen

  delay(2000);
  
  // Update text dynamically
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("ESP32 OLED Demo");
  display.println("Line 2 text");
  display.println("Line 3 text");
  display.display();
  
}

void loop(){
  // Serial.print("Check Buttons");
  remote.checkButtons();
  // check for for selected profile

  // for(const auto& buttonVal : activeMap.buttons){
  //     int pin = buttonVal.second.pin;
  //     if(digitalRead(pin) == LOW){
  //       std::string button = remote.getButtonNameFromPin(pin);
  //       if(!button.empty()){
  //         remote.sender(button);
  //       }
  //     }
  // }


  remote.receiver();

  

  // delay(100);
  // yield();
}
