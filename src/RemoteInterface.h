#ifndef REMOTEINTERFACE_H
#define REMOTEINTERFACE_H
#include <Arduino.h>
// #include <IRremote.hpp>
// #include <IRsend.h>
// #include <IRrecv.h>
// #include <IRutils.h>
#include "ButtonMap.cpp"

class RemoteInterface {
private:
  int txPin;
  int rxPin;
  int numProfiles = 3;
  // static array of profiles
  ButtonMap profiles[3];

  ButtonMap currentProfile;

public:
  //remote constructor
  RemoteInterface(int txPin, int rxPin);

  void IRReceive(bool state);

  void receiver();

  void SelectProfile(int select);
  void AssignButton(int button);

  // high level transmit commands
  void sendVolumeUp();
  void sendVolumeDown();
  void sendPower();
  void sendMute();

};

#endif