#ifndef Ultrassonico_h
#define Ultrassonico_h

#include <Arduino.h>
#include <NewPing.h>
#include "MeuServo.h"

class Ultrassonico 
{
public:
  Ultrassonico();
  Ultrassonico(byte pino_trigger, byte pino_echo);
  void init(byte pino_servo);
  bool checarObjeto(int distanciaMax);
  int ping();
  int scannerArea();

private:
  byte _pinoTrigger;
  byte _pinoEcho;
  float _duracao;
  float distancias[3];
  MeuServo _servo;
  // NewPing* _sonar;
};

#endif