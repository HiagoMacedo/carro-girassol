#include <Arduino.h>
#include "Motor.h"

Motor::Motor() {}
Motor::Motor(byte pino1, byte pino2, byte pino_enable)
: _pino1 (pino1)
, _pino2 (pino2)
, _pinoEnable (pino_enable)
{}


void Motor::begin()
{
  pinMode(_pino1, OUTPUT);
  pinMode(_pino2, OUTPUT);
  pinMode(_pinoEnable, OUTPUT);
  analogWrite(_pinoEnable, 0);
}

void Motor::moverFrente(byte velocidade)
{
  analogWrite(this->_pinoEnable, velocidade);
  digitalWrite(this->_pino1, HIGH);
  digitalWrite(this->_pino2, LOW);
}

void Motor::moverTras(byte velocidade)
{
  analogWrite(this->_pinoEnable, velocidade);
  digitalWrite(this->_pino2, HIGH);
  digitalWrite(this->_pino1, LOW);
}

void Motor::parar()
{
  analogWrite(this->_pinoEnable, 0);
  digitalWrite(this->_pino1, LOW);
  digitalWrite(this->_pino2, LOW);
}

void Motor::setPino1(byte pino_1) { this->_pino1 = pino_1; }

void Motor::setPino2(byte pino_2) { this->_pino2 = pino_2; }

void Motor::setPinoEnable(byte pino_enable) { this->_pinoEnable = pino_enable; }

void Motor::setPinos(byte pino_1, byte pino_2, byte pino_enable)
{
  setPino1(pino_1);
  setPino2(pino_2);
  setPinoEnable(pino_enable);
}