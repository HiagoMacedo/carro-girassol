#include <Arduino.h>
#include <Carro.h>
#include <Motor.h>
#include "Ultrassonico.h"


Carro::Carro() {}

Carro::Carro(Motor& motorA, Motor& motorB) : _motorA (motorA), _motorB (motorB) {}

void Carro::begin()
{
  _motorA.begin();
  _motorB.begin();
}

void Carro::moverFrente(byte velocidade)
{
  _motorA.moverFrente(velocidade);
  _motorB.moverFrente(velocidade);
}

void Carro::moverTras(byte velocidade)
{
  _motorA.moverTras(velocidade);
  _motorB.moverTras(velocidade); // Motor B precisa pelo menos 150 de velocidade (testar mais)
}

void Carro::parar()
{
  _motorA.parar();
  _motorB.parar();
}

void Carro::girarDireita(unsigned int tempo_ms)
{
  _motorA.parar();
  _motorB.moverFrente(140);
  delay(tempo_ms);
  parar();
}

void Carro::girarEsquerda(unsigned int tempo_ms)
{
  _motorB.parar();
  _motorA.moverFrente(140);
  delay(tempo_ms);
  parar();
}
