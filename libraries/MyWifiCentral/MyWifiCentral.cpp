#include "Arduino.h"
#include "MyWifiCentral.h"

MyWifiCentral::MyWifiCentral(){
    _ssid="YOUR_SSID_HERE";
    _pwd="YOUR_WIFI_PASSWORD_HERE";
}
MyWifiCentral::~MyWifiCentral(){
  _auth="40f825582b1743468b3450547c543ac7";
  _ssid="ElkabongFonGanso";
  _pwd="kkkjihgfedcba";
}

char* MyWifiCentral::auth(){
  return _auth;
}

char* MyWifiCentral::ssid(){
  return _ssid;
}

char* MyWifiCentral::passcode(){
  return _pwd;
}
