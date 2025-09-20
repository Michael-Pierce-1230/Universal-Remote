#include "RemoteInterface.h"
#include <IRremote.hpp>
// #include <map>
// #include <string>
// #include "ButtonMap.cpp"

// RemoteInterface::RemoteInterface(uint16_t txPin, uint16_t rxPin): irsend(txPin), irrecv(rxPin) {}
RemoteInterface::RemoteInterface(int txPin, int rxPin){
  // set tx and rx pins
    this->txPin = txPin;
    this->rxPin = rxPin;
    
    // setup sender 
    IrSender.begin(this->txPin, ENABLE_LED_FEEDBACK);

    // select first profile as a default
    this->currentProfile = this->profiles[0];
   
    
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
    this->currentProfile = this->profiles[select];
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
    IrSender.sendSAMSUNG(this->currentProfile.buttons["volumeUp"].rawData,
                        this->currentProfile.buttons["volumeUp"].bitLength); 
  }

void RemoteInterface::sendVolumeDown(){
  IrSender.sendSAMSUNG(this->currentProfile.buttons["volumeDown"].rawData,
                        this->currentProfile.buttons["volumeDown"].bitLength); 
}

void RemoteInterface::sendPower(){
  IrSender.sendSAMSUNG(this->currentProfile.buttons["power"].rawData,
                        this->currentProfile.buttons["power"].bitLength); 
}

void RemoteInterface::sendMute(){
  IrSender.sendSAMSUNG(this->currentProfile.buttons["mute"].rawData,
                        this->currentProfile.buttons["mute"].bitLength); 
}

