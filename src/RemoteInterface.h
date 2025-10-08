#ifndef REMOTEINTERFACE_H
#define REMOTEINTERFACE_H
#include <Arduino.h>
// #include <IRremote.hpp>
// #include <IRsend.h>
// #include <IRrecv.h>
// #include <IRutils.h>
#include "ButtonMap.cpp"
#include "string"

class RemoteInterface {
private:
  int txPin;
  int rxPin;
  static constexpr int numProfiles = 5;
  
  const unsigned long debounceDelay = 20;

  

  // bool isButtonPressed();

  // void handleButtonPress(const std::string &name, ButtonData &data);

public:
  int selectedProfile = 0;
  ButtonMap currentProfile;
    // static array of profiles
  ButtonMap profiles[numProfiles];

  // button used to cycle through profiles
  BaseButton profileMode = BaseButton(14);

  enum ButtonEvent {
    NONE,
    PRESSED,
    RELEASED
  };

  //remote constructor
  RemoteInterface(int txPin, int rxPin);
      // : txPin(txPin), rxPin(rxPin){
      //   currentProfile = &profiles[0];
      //   // currentProfile->profileName = "SAMSUNG PROFILE";

      // }

  void begin();

  void checkButtons();

  void IRReceiveState(bool state);

  void receiver();

  void ChangeProfile();
  
  void AssignButton(int button);

  std::string getButtonNameFromPin(int pin);

  void sender(const std::string &command, ButtonData &data);

  ButtonEvent ButtonDebounce(BaseButton &button);

};

#endif