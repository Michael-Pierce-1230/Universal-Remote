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
std::string RemoteInterface::SelectProfile( int select){
    this->currentProfile = this->profiles[select];
    return this->currentProfile.profileName;
}

void RemoteInterface::AssignButton(int button){
  this->IRReceive(true);
}

std::string RemoteInterface::getButtonNameFromPin(int pin){

    for(const auto& pair : this->currentProfile.buttons){
      if(pair.second.pin == pin){
        return pair.first;
      }
    }
    return ""; // empty string means no  button found for this pin
}

void RemoteInterface::receiver() {
  
    if (IrReceiver.decode()){
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
      IrReceiver.printIRResultShort(&Serial);
      IrReceiver.resume();

      
    } 
}

void RemoteInterface::sender(std::string command){
    IrSender.sendSAMSUNG(this->currentProfile.buttons[command].rawData,
                        this->currentProfile.buttons[command].bitLength); 

}

