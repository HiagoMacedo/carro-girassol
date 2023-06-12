#include <Arduino.h>
#include "Rastreador.h"

#define TOLERANCIA 25
#define GRAU_MAX 180
#define GRAU_MIN 0

int static valorNorte, valorSul, valorLeste, valorOeste;

Rastreador::Rastreador() {}


void Rastreador::readLDR(const int& ldrSuperior_D,const int& ldrSuperior_E, const int& ldrInferior_D, const int& ldrInferior_E)
{
  readSuperior_D = analogRead(ldrSuperior_D);
  readSuperior_E = analogRead(ldrSuperior_E);
  readInferior_D = analogRead(ldrInferior_D);
  readInferior_E = analogRead(ldrInferior_E);
}

void Rastreador::getValores()
{
  valorNorte  = (readSuperior_D + readSuperior_D) / 2;
  valorSul    = (readInferior_D + readInferior_E) / 2;
  valorLeste  = (readInferior_D + readSuperior_D) / 2;
  valorOeste  = (readSuperior_E + readInferior_E) / 2;
}

void Rastreador::update_posicao(const int& valor1, const int& valor2, int& posicao)
{
  if (abs(valor1 - valor2) > TOLERANCIA) {
    if (valor1 > valor2 && posicao < GRAU_MAX) {
      posicao++;
    } 
    if (valor2 > valor1 && posicao > GRAU_MIN) {
      posicao--;
    }
  }
}

void Rastreador::girassol() {
  update_posicao(valorNorte, valorSul, posicao_y);
  update_posicao(valorLeste, valorOeste, posicao_x);

  write(posicao_y);
  write(posicao_x);
  
  delay(10);
}