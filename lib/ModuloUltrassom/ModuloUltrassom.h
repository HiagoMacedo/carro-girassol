#ifndef ModuloUltrassom_h
#define ModuloUltrassom_h

#include <Arduino.h>
#include "Ultrassonico.h"
#include "MeuServo.h"

class ModuloUltrassom
{
public:
  ModuloUltrassom();
  ModuloUltrassom(Ultrassonico& sensor);

private:
Ultrassonico _sensorUltrassom;
MeuServo _servo;
};


#endif