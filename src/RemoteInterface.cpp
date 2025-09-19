#include "RemoteInterface.h"
#include <IRremote.hpp>
// #include <map>
// #include <string>
#include "ButtonMap.cpp"

// RemoteInterface::RemoteInterface(uint16_t txPin, uint16_t rxPin): irsend(txPin), irrecv(rxPin) {}
RemoteInterface::RemoteInterface(int txPin, int rxPin){
    this->txPin = txPin;
    this->rxPin = rxPin;

    IrSender.begin(this->txPin, ENABLE_LED_FEEDBACK);
   
    
}


void RemoteInterface::IRReceive(bool state){
  if(state){
    IrReceiver.begin(this->rxPin, ENABLE_LED_FEEDBACK);
  } else{
    IrReceiver.disableIRIn();
  }
  
}

// each method wil need to determine the type of protocol to use

void RemoteInterface::SelectProfile( int select){
    this->profileSelect = select;
}

void RemoteInterface::AssignButton(int button){
  this->IRReceive(true);
  

}

void RemoteInterface::receiver() {
  
    if (IrReceiver.decode()){
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
      IrReceiver.printIRResultShort(&Serial);
      IrReceiver.resume();

      
    } 
}

void RemoteInterface::sendVolumeUp(){
   IrSender.sendSAMSUNG(this->profiles[this->profileSelect].volumeUp, 32); 
  }

void RemoteInterface::sendVolumeDown(){
  //  sendSamsung(SAMSUNG_VOL_DOWN); 
  // Serial.println("Sending msg");
  // IrSender.sendSamsung(0x7, 0x07, 0);
  // IrSender.sendSAMSUNG(0xE0E0E01F, 32);
  IrSender.sendSAMSUNG(this->profiles[this->profileSelect].volumeDown, 32);
}

void RemoteInterface::sendPower(){
  IrSender.sendSAMSUNG(this->profiles[this->profileSelect].power, 32);
}

void RemoteInterface::sendMute(){
  IrSender.sendSAMSUNG(this->profiles[this->profileSelect].mute, 32);
}

