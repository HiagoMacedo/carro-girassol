#include <Arduino.h>
#include <Carro.h>
#include <Motor.h>


// Carro::Carro(Motor& motor) : Motor(motor) {}
Carro::Carro() {}

Carro::Carro(Motor& motorA, Motor& motorB) : _motorA (motorA), _motorB (motorB) {}


// Motor Carro::getMotorA() { return this->_motorA; }
// Motor Carro::getMotorB() { return this->_motorB; }

void Carro::init()
{
  _motorA.init();
  _motorB.init();
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
  _motorB.moverFrente(100);
  delay(tempo_ms);
}

void Carro::girarEsquerda(unsigned int tempo_ms)
{
  _motorB.parar();
  _motorA.moverFrente(100);
  delay(tempo_ms);
}