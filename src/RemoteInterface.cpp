#include "RemoteInterface.h"
#include <IRremote.hpp>

// RemoteInterface::RemoteInterface(uint16_t txPin, uint16_t rxPin): irsend(txPin), irrecv(rxPin) {}
RemoteInterface::RemoteInterface(int txPin, int rxPin){
    this->txPin = txPin;
    this->rxPin = rxPin;
}

void RemoteInterface::begin(){
  IrReceiver.begin(this->rxPin, ENABLE_LED_FEEDBACK);
  IrSender.begin(this->txPin, ENABLE_LED_FEEDBACK);
  // IrReceiver.disableIRIn();
}

void RemoteInterface::receiver() {
  
    if (IrReceiver.decode()){
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
      IrReceiver.printIRResultShort(&Serial);
      IrReceiver.resume();
    } 
}

void RemoteInterface::sendVolumeUp(){
  //  sendSamsung(SAMSUNG_VOL_UP); 
  }

void RemoteInterface::sendVolumeDown(){
  //  sendSamsung(SAMSUNG_VOL_DOWN); 
  // Serial.println("Sending msg");
  // IrSender.sendSamsung(0x7, 0x07, 0);
  IrSender.sendSAMSUNG(0xE0E0E01F, 32);
  }

void RemoteInterface::sendPower(){
  //  sendSamsung(SAMSUNG_POWER);
  }

