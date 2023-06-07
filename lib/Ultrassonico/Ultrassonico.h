#ifndef Ultrassonico_h
#define Ultrassonico_h

#include <Arduino.h>
#include <NewPing.h>
#include "MeuServo.h"

class Ultrassonico 
{
public:
  Ultrassonico();
  Ultrassonico(byte pino_trigger, byte pino_echo, byte pino_servo);
  void begin();
  bool checarObjeto(int distanciaMax);
  bool findDistanciaMax(int* distanciaMax);
  int ping();
  int checarArea(int distanciaMax);

private:
  byte _pinoTrigger;
  byte _pinoEcho;
  byte _pinoServo;
  MeuServo _servo;
};

#endif