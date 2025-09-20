// #include <Arduino.h>
#include "RemoteInterface.h"
// #include <IRremote.hpp>

const int TX_PIN = 16;
const int RX_PIN = 13;

void setup();
void loop();

RemoteInterface remote(TX_PIN, RX_PIN);


int main(){
  init();

  setup();

  loop();

  // while (true){
  //   // remote.receiver();
  //   // Serial.println("vs Code");
  //   remote.sendVolumeDown();
  //   remote.receiver();
  //   delay(1000);
  //   // yield();
  // }

  return 0;
}

void setup(){
  Serial.begin(115200);

  
  // remote.begin();
  
}

void loop(){
   // remote.receiver();
    // Serial.println("vs Code");
    remote.sendVolumeDown();
    remote.receiver();
    delay(1000);
    // yield();
}

// #include <IRremote.hpp>

// #include <IRremote.hpp>

// const int IR_RECEIVE_PIN = 7;

// void setup(){
//   Serial.begin(9600);
//   IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // start the receiver
// }

// void loop(){
//   if (IrReceiver.decode()){
//     Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
//     IrReceiver.printIRResultShort(&Serial);
//     IrReceiver.resume();
//   }
// }