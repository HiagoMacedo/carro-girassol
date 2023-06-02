#include <Arduino.h>
#include <Carro.h>
#include <Motor.h>
#include "Ultrassonico.h"


// Carro::Carro(Motor& motor) : Motor(motor) {}
Carro::Carro() {}

Carro::Carro(Motor& motorA, Motor& motorB) : _motorA (motorA), _motorB (motorB) {}

// Carro(Motor& motorA, Motor& motorB, Ultrassonico& sensorUltrassom)
// : _motorA (motorA)
// , _motorB (motorB)
// , _sensorUltrassom (sensorUltrassom)
// {}

// Motor Carro::getMotorA() { return this->_motorA; }
// Motor Carro::getMotorB() { return this->_motorB; }

void Carro::init(Motor& motorA, Motor& motorB, Ultrassonico& sensorUltrassom, byte pino_servo)
{
  this->_motorA = motorA;
  this->_motorB = motorB;
  this->_sensorUltrassom = sensorUltrassom;
  _motorA.init();
  _motorB.init();
  _sensorUltrassom.init(pino_servo);
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

void Carro::decisao()
{
  switch(_sensorUltrassom.scannerArea()) {
    case 0:
      girarEsquerda(1400);
      moverFrente(140);
      break;
    case 90:
      moverFrente(140);
      break;
    case 180:
      girarDireita(1400);
      moverFrente(140);
      break;
  }
}