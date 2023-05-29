#ifndef Bateria_h
#define Bateria_h

#include "Arduino.h"

class Bateria
{
  public:
  Bateria(byte pino_analogico);
  bool checarNivel();

  private:
  const byte _pinoBateria; // Pino ANALOG
  int _valorLido;
  float _tensaoBateria;
};

#endif