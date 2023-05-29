#include <Arduino.h>
#include <NewPing.h>
#include "Ultrassonico.h"

Ultrassonico::Ultrassonico() {}

Ultrassonico::Ultrassonico(byte pino_trigger, byte pino_echo, int distancia_max)
  : _pinoTrigger (pino_trigger)
  , _pinoEcho (pino_echo)
  , _velocidadeSom (0.0343)
{}


void Ultrassonico::init(byte pino_servo)
{
  // _sonar = new NewPing(_pinoTrigger, _pinoEcho, 300);
  pinMode(_pinoTrigger, OUTPUT);
  pinMode(_pinoEcho, INPUT);
  _servo.init(pino_servo);
}

/**
 * Parametro:  distanciaMax  A distancia maxima em cm
 */
bool Ultrassonico::checarObjeto(int distanciaMax)
{
  // _distanciaAtual = ping();
  return (ping() <= distanciaMax);
}

/**
 * @fn      ping
 * @result  Retorna a distancia do objeto em cm (Centimetro)
 */
float Ultrassonico::ping()
{
  digitalWrite(_pinoTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(_pinoTrigger, LOW);

  _duracao = pulseIn(_pinoEcho, HIGH);

  return (_duracao * 0.01715); // 0.01715 = Velocidade do som em cm/μs dividido por 2
}


int Ultrassonico::scannerArea(int distanciaMax)
{
  _servo.mover(0);
  if (!checarObjeto(distanciaMax)) {
    return 1;
  }

  _servo.mover(90);
  if (!checarObjeto(distanciaMax)) {
    return 2;
  }

  _servo.mover(180);
  if (!checarObjeto(distanciaMax)) {
    return 3;
  }

  return 0;
}
