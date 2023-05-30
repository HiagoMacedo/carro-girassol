#ifndef Rastreador_h
#define Rastreador_h

#include <Arduino.h>

class Rastreador {
public:
  Rastreador();
  Rastreador(byte ldrSuperior, byte ldrInferior);

  void init();
  void posicaoSol();

private:
  byte _ldrSuperior;
  byte _ldrInferior;
};

#endif