#include <MyWifiCentral.h>
/* 
 *  I keep the auth data out of the file, so I don't need to worry with them spilling on my github.
 *  Check this great example at:
 *  http://www.instructables.com/id/Build-a-Custom-ESP8266-Arduino-WiFi-Library/?ALLSTEPS
 */
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#define RightMotorSpeed 5
#define RightMotorDir 0
#define LeftMotorSpeed 4
#define LeftMotorDir 2
#define ECHO_PIN 12
#define TRIG_PIN 13
#define LED_PIN 16

MyWifiCentral myWifiCentral;
char* auth = myWifiCentral.auth();
char* ssid = myWifiCentral.ssid();
char* password = myWifiCentral.passcode();

SimpleTimer timer;
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, password);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(RightMotorSpeed, OUTPUT);
  pinMode(RightMotorDir, OUTPUT);
  pinMode(LeftMotorSpeed, OUTPUT);
  pinMode(LeftMotorDir, OUTPUT);
  timer.setInterval(500, sendDistanceData);
}

long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration/58.2;
}

void blink() {
  long distance = getDistance();
  digitalWrite(LED_PIN, HIGH);
  delay(distance * 10);
  digitalWrite(LED_PIN, LOW);
}

void sendDistanceData() {
  Blynk.virtualWrite(10, getDistance());
}

void loop()
{
  Blynk.run();
  timer.run();
}

void halt()
{
  digitalWrite(RightMotorSpeed, LOW);
  digitalWrite(LeftMotorSpeed, LOW);
}

void forward()
{
  digitalWrite(RightMotorDir, HIGH);
  digitalWrite(LeftMotorDir, HIGH);
  digitalWrite(RightMotorSpeed, HIGH);
  digitalWrite(LeftMotorSpeed, HIGH);
}

void reverse()
{
  digitalWrite(RightMotorDir, LOW);
  digitalWrite(LeftMotorDir, LOW);
  digitalWrite(RightMotorSpeed, HIGH);
  digitalWrite(LeftMotorSpeed, HIGH);
}

void right()
{
  digitalWrite(RightMotorDir, LOW);
  digitalWrite(LeftMotorDir, HIGH);
  digitalWrite(RightMotorSpeed, HIGH);
  digitalWrite(LeftMotorSpeed, HIGH);
}

void left()
{
  digitalWrite(RightMotorDir, HIGH);
  digitalWrite(LeftMotorDir, LOW);
  digitalWrite(RightMotorSpeed, HIGH);
  digitalWrite(LeftMotorSpeed, HIGH);
}

BLYNK_WRITE(V0)
{
  if (param[0]) {
    forward();
  }
  
  else {
    halt();
  }
  
}

BLYNK_WRITE(V1)
{
  if (param[0]) {
    reverse();
  }
  
  else {
    halt();
  }
}

BLYNK_WRITE(V2)
{
  if (param[0]) {
    right();
  }
  
  else {
    halt();
  }
}

BLYNK_WRITE(V3)
{
  if (param[0]) {
    left();
  }
  
  else {
    halt();
  }
  
}


