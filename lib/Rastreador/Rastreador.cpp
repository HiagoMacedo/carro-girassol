#include <Arduino.h>
#include "Rastreador.h"

Rastreador::Rastreador() {}

Rastreador::Rastreador(byte ldrSuperior, byte ldrInferior) 
: _ldrSuperior (ldrSuperior)
, _ldrInferior (ldrInferior) 
{}

void Rastreador::init()
{
  pinMode(_ldrSuperior, INPUT);
  pinMode(_ldrInferior, INPUT);
}

void Rastreador::posicaoSol()
{
  
}