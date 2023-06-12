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
  // _distanciaAtual = ping();
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
  Serial.print("Distancia = ");
  Serial.println(total_ping/qtd_ping);
  Serial.println("");
  return (total_ping/qtd_ping);
}


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
// static float distanciaAtual;

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

// Distancia static d2;
// int Ultrassonico::scannerArea()
// {
//   distanciaMax = -1;
//   _servo.mover(180);
//   grauDistanciaMax = 180;
//   findDistanciaMax(&distanciaMax);
//   Serial.print("Distancia(180): ");
//   Serial.println(distanciaMax);

//   _servo.mover(90);
//   if (findDistanciaMax(&distanciaMax) == true) {
//     grauDistanciaMax = 90;
//   }
//   Serial.print("Distancia(90): ");
//   Serial.println(distanciaMax);

//   _servo.mover(1);
//   if (findDistanciaMax(&distanciaMax) == true) {
//     grauDistanciaMax = 1;
//   }
//   Serial.print("Distancia(1): ");
//   Serial.println(distanciaMax);
  
//   Serial.print("Grau Max: ");
//   Serial.println(grauDistanciaMax);
//   return grauDistanciaMax;
//   // return 0;
// }
