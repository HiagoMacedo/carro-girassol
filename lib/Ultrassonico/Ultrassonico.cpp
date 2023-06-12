#include <Arduino.h>
#include <NewPing.h>
#include "Ultrassonico.h"

Ultrassonico::Ultrassonico() {}

Ultrassonico::Ultrassonico(byte pino_trigger, byte pino_echo, byte pino_servo)
  : _pinoTrigger (pino_trigger)
  , _pinoEcho (pino_echo)
  , _pinoServo (pino_servo)
{}


void Ultrassonico::begin()
{
  pinMode(_pinoTrigger, OUTPUT);
  pinMode(_pinoEcho, INPUT);
  _servo.attach(_pinoServo);
}


bool Ultrassonico::checarObjeto(int distanciaMax)
{
  return (ping() < distanciaMax);
}


int Ultrassonico::ping()
{
  int duracao;
  int qtd_ping;
  float total_ping;
  
  total_ping = 0;

  for (qtd_ping = 0; qtd_ping < 10; qtd_ping++){
    digitalWrite(_pinoTrigger, LOW);
    delayMicroseconds(10);
    digitalWrite(_pinoTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(_pinoTrigger, LOW);

    duracao = pulseIn(_pinoEcho, HIGH);
    total_ping += (duracao * 0.01715); /* 0.01715 = Velocidade do som em cm/μs dividido por 2 */
  }
  return (total_ping/qtd_ping);
}

struct Casa {

};

int Ultrassonico::checarArea(int distanciaMax)
{
  _servo.mover(1);
  if (!checarObjeto(distanciaMax)) {
    _servo.mover(90);
    return 1;
  }

  _servo.mover(90);
  if (!checarObjeto(distanciaMax)) {
    return 2;
  }

  _servo.mover(180);
  if (!checarObjeto(distanciaMax)) {
    _servo.mover(90);
    return 3;
  }
  _servo.mover(90);
  return 0;
}


static unsigned int grauDistanciaMax;
int distanciaMax;

bool Ultrassonico::findDistanciaMax(int* distanciaMax)
{
  static int distanciaAtual;

  delay(1000);
  distanciaAtual = ping();
  if (distanciaAtual >= *distanciaMax) {
    *distanciaMax = distanciaAtual;
    return true;
  }
  return false;
}
