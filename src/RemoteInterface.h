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


public:
    // static array of profiles
  ButtonMap profiles[3];

  ButtonMap currentProfile;
  //remote constructor
  RemoteInterface(int txPin, int rxPin);

  void IRReceive(bool state);

  void receiver();

  std::string SelectProfile(int select);
  void AssignButton(int button);
  std::string getButtonNameFromPin(int pin);

  // high level transmit commands
  void sender(std::string command);

};

#endif