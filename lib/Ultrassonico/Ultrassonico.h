#ifndef Ultrassonico_h
#define Ultrassonico_h

#include <Arduino.h>
#include <NewPing.h>
#include "MeuServo.h"

class Ultrassonico 
{
public:
  Ultrassonico();
  Ultrassonico(byte pino_trigger, byte pino_echo, int distancia_max);
  void init(byte pino_servo);
  bool checarObjeto(int distanciaMax);
  float ping();
  int scannerArea(int distanciaMax);

private:
  byte _pinoTrigger;
  byte _pinoEcho;
  // float _distanciaMax;  // Em centimetros
  float _distanciaAtual;
  float _duracao;
  float _velocidadeSom; // Em cm/μs (Centimetro por microsegundo)
  MeuServo _servo;
  // NewPing* _sonar;
};

#endif