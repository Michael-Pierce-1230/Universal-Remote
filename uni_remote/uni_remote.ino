// #include <Arduino.h>
#include "RemoteInterface.h"
// #include <IRremote.hpp>

int TX_PIN = 7;
int RX_PIN = 8;

int main(){
  init();
  Serial.begin(9600);

  RemoteInterface remote(TX_PIN, RX_PIN);

  remote.begin();

  int i = 0;
  while (true){
    remote.receiver();
    // Serial.println("Receiving");
    delay(1000);
    // yield();
  }

  return 0;
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