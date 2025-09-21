#include "RemoteInterface.h"
#include <IRremote.hpp>


RemoteInterface::RemoteInterface(int txPin, int rxPin){
  // set tx and rx pins
    this->txPin = txPin;
    this->rxPin = rxPin;
    
    // select first profile as a default
    this->currentProfile = this->profiles[0];
}

void RemoteInterface::begin(){
    for (auto &pair : this->currentProfile.buttons){
      pinMode(pair.second.pin, INPUT_PULLUP);
    }
     // setup sender 
    IrSender.begin(this->txPin, ENABLE_LED_FEEDBACK);
}

void RemoteInterface::checkButtons(){
    for (auto &pair : this->currentProfile.buttons){
        const std::string &command = pair.first;
        ButtonData &data = pair.second;

        int state = digitalRead(data.pin);
        if (state == LOW) {
          sender(command, data);
        }
    }
}

void RemoteInterface::IRReceiveState(bool state){
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
  this->IRReceiveState(true);
}

void RemoteInterface::receiver() {
  
    if (IrReceiver.decode()){
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
      IrReceiver.printIRResultShort(&Serial);
      IrReceiver.resume();
    } 
}

void RemoteInterface::sender(const std::string &command, ButtonData &data){
    Serial.print("Button pressed: ");
    Serial.println(command.c_str());

    switch (data.protocol){
        case LG:
          IrSender.sendLGRaw(data.rawData, data.bitLength);
          break;

        case SAMSUNG:
          IrSender.sendSAMSUNG(data.rawData, data.bitLength);
          break;

        default:
            Serial.println("Unknown protocol, nothing sent.");
            break;
    }
}