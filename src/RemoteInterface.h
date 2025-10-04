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
  int numProfiles = 3;
  const unsigned long debounceDelay = 50;

  ButtonMap currentProfile;

  // bool isButtonPressed();

  // void handleButtonPress(const std::string &name, ButtonData &data);

public:
    // static array of profiles
  ButtonMap profiles[3];

  //remote constructor
  RemoteInterface(int txPin, int rxPin);

  void begin();

  void checkButtons();

  void IRReceiveState(bool state);

  void receiver();

  std::string SelectProfile(int select);
  
  void AssignButton(int button);

  std::string getButtonNameFromPin(int pin);

  void sender(const std::string &command, ButtonData &data);

};

#endif