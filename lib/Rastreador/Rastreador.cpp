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

typedef struct Luminosidade {
  unsigned int norte;
  unsigned int sul;
  unsigned int leste;
  unsigned int oeste;
} Luminosidade;

unsigned int lerLdr(byte pino_ldr) {
  int total = 0;
  int i;
  for (i = 0; i < 20; i++) { // checar 10 ou 20??
    total += analogRead(pino_ldr);
  }
  return (total / i);
}

byte Rastreador::posicaoSol()
{
  Luminosidade luminosidade;
  
  luminosidade.norte = lerLdr(_ldrSuperior);
  
  luminosidade.sul = lerLdr(_ldrInferior);

  if (luminosidade.norte > luminosidade.sul) { return 1; } 
  if (luminosidade.sul > luminosidade.norte) { return 2; }

  return -1;
}