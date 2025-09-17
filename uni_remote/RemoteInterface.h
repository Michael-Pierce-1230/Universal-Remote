#ifndef REMOTEINTERFACE_H
#define REMOTEINTERFACE_H
#include <Arduino.h>
// #include <IRremote.hpp>
// #include <IRsend.h>
// #include <IRrecv.h>
// #include <IRutils.h>

class RemoteInterface {
private:
  int txPin;
  int rxPin;

public:
  //remote constructor
  RemoteInterface(int txPin, int rxPin);

  void begin();
  void receiver();

  // high level transmit commands
  void sendVolumeUp();
  void sendVolumeDown();
  void sendPower();

};

#endif