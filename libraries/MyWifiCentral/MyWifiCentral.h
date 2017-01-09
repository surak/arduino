#ifndef MyWifiCentral_h
#define MyWifiCentral_h

#include "Arduino.h"

class MyWifiCentral{
  public:
    MyWifiCentral();
    ~MyWifiCentral();
    char* auth();
    char* ssid();
    char* passcode();
  private:
    char* _auth;
    char* _ssid;
    char* _pwd;
};

#endif
