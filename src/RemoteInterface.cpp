#include "RemoteInterface.h"
#include <IRremote.hpp>


RemoteInterface::RemoteInterface(int txPin, int rxPin){
  // set tx and rx pins
    this->txPin = txPin;
    this->rxPin = rxPin;
    
    // select first profile as a default
    int i = 65;
    for (auto &profile : profiles){
      profile.profileName = static_cast<char>(i);
      i++;
    }
    // currentProfile = profiles[0];
    profiles[selectedProfile].profileName = "SAMSUNG PROFILE";
    profiles[selectedProfile].buttons["volumeUp"].rawData = 0xE0E0E01F;
    profiles[selectedProfile].buttons["volumeUp"].bitLength = 32;
    profiles[selectedProfile].buttons["volumeUp"].protocol = SAMSUNG;
    profiles[selectedProfile].buttons["volumeDown"].rawData = 0xE0E0D02F;
    profiles[selectedProfile].buttons["volumeDown"].bitLength = 32;
    profiles[selectedProfile].buttons["volumeDown"].protocol = SAMSUNG;
    
}

void RemoteInterface::begin(){
  for (auto &pair : profiles[selectedProfile].buttons){
    pinMode(pair.second.pin, INPUT_PULLUP);
  }
  pinMode(profileMode.pin, INPUT_PULLUP);
    // setup sender 
  IrSender.begin(this->txPin, ENABLE_LED_FEEDBACK);
}

void RemoteInterface::checkButtons(){
  
  for (auto &pair : profiles[selectedProfile].buttons){
    if(ButtonDebounce(pair.second) == PRESSED){
      std::string buttonName = pair.first;
      const std::string &command = pair.first;
      ButtonData &data = pair.second;
      sender(command, data);
    }
  }

  if(ButtonDebounce(profileMode) == PRESSED){
    ChangeProfile();
  }
  
}

void RemoteInterface::IRReceiveState(bool state){
  
  if(state){
    IrReceiver.begin(this->rxPin, ENABLE_LED_FEEDBACK);
  } else{
    IrReceiver.disableIRIn();
  }
}

// each method will need to determine the type of protocol to use
void RemoteInterface::ChangeProfile(){
  // (*this->currentProfile) = this->profiles[select];
  // return (*this->currentProfile).profileName;
  
  if(this->selectedProfile + 1 > (this->numProfiles - 1)){
    this->selectedProfile = 0;
  } else{
    this->selectedProfile++;
  }

  // currentProfile = this->profiles[this->selectedProfile];
  Serial.print("Changed profile: ");
  Serial.print(this->selectedProfile);
  Serial.print(" | ");
  Serial.println(profiles[selectedProfile].profileName.c_str());
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

RemoteInterface::ButtonEvent RemoteInterface::ButtonDebounce(BaseButton &button){
  // read state of pin
  bool pinState = digitalRead(button.pin);

  if(pinState != button.lastButtonState){
    // reset debounce time
    button.lastDebounceTime = millis();
  }

  if ((millis() - button.lastDebounceTime) >= debounceDelay){
    // only update stable state if it really changed
    if (pinState != button.buttonState){
      // this is the stable button state USE THIS
      button.buttonState = pinState;
      button.lastButtonState = pinState;
      return (pinState == LOW) ? PRESSED : RELEASED;
    }
  }

  button.lastButtonState = pinState;
  return NONE;
}