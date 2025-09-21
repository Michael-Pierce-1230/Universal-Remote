// #include <Arduino.h>
#include "RemoteInterface.h"
// #include <IRremote.hpp>
#include "ButtonMap.h"

const int TX_PIN = 16;
const int RX_PIN = 13;

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
  
}

void loop(){

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
  

  delay(1000);
  // yield();
}

//use code for debouncing buttons
//  ButtonMap& activeMap = remote.profiles[remote.currentProfileIndex];

//     for (const auto& pair : activeMap.buttons) {
//         int pin = pair.second.pin;
//         int state = digitalRead(pin);

//         if (state == LOW) { // assuming active-low button
//             unsigned long now = millis();

//             if (now - remote.lastPressTime[pin] > remote.debounceDelay) {
//                 remote.lastPressTime[pin] = now;

//                 String buttonName = remote.getButtonNameFromPin(pin).c_str();
//                 if (buttonName.length() > 0) {
//                     remote.sendButton(buttonName.c_str());
//                 }
//             }
//         }
//     }