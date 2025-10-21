#include "RemoteInterface.h"
// #include "ButtonMap.h"
#include "display.h"

const int TX_PIN = 17;
const int RX_PIN = 16;

void setup();
void loop();

// RemoteInterface remote(TX_PIN, RX_PIN);
RemoteInterface remote(TX_PIN, RX_PIN);

DisplayManager display;


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
  display.begin();
  display.clear();
  display.drawBatteryIcon(120, 0, 1);
  // display.pageLayout();
 
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
