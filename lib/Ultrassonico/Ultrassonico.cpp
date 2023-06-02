#include <Arduino.h>
#include <NewPing.h>
#include "Ultrassonico.h"

Ultrassonico::Ultrassonico() {}

Ultrassonico::Ultrassonico(byte pino_trigger, byte pino_echo)
  : _pinoTrigger (pino_trigger)
  , _pinoEcho (pino_echo)
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

float static total_ping;
int static qtd_ping;
int Ultrassonico::ping()
{
  total_ping = 0;
  for (qtd_ping = 0; qtd_ping < 5; qtd_ping++){
    digitalWrite(_pinoTrigger, LOW);
    delayMicroseconds(2);
    digitalWrite(_pinoTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(_pinoTrigger, LOW);

    _duracao = pulseIn(_pinoEcho, HIGH);
    total_ping += (_duracao * 0.01715); /* 0.01715 = Velocidade do som em cm/μs dividido por 2 */
  }
  return (total_ping/qtd_ping);
}


// int Ultrassonico::scannerArea(int distanciaMax)
// {
//   _servo.mover(0);
//   if (!checarObjeto(distanciaMax)) {
//     return 1;
//   }

//   _servo.mover(90);
//   if (!checarObjeto(distanciaMax)) {
//     return 2;
//   }

//   _servo.mover(180);
//   if (!checarObjeto(distanciaMax)) {
//     return 3;
//   }

//   return 0;
// }

typedef struct Distancia {
  unsigned int grau;
  float distancia;
} Distancia;
Distancia distancia[3];

static unsigned int grauDistanciaMax;
static float distanciaMax;
static float distanciaAtual;
// Distancia static d2;
int Ultrassonico::scannerArea()
{
  _servo.mover(0);
  grauDistanciaMax = 0;
  distanciaMax = ping();
  Serial.print("Distancia(0) = ");
  Serial.println(distanciaMax);
  // distancia[0].grau = 0;
  // distancia[0].distancia = ping();

  _servo.mover(90);
  // distancia[1].grau = 90;
  // distancia[1].distancia = ping();
  distanciaAtual = ping();
  Serial.print("Distancia(90) = ");
  Serial.println(distanciaAtual);
  if (distanciaAtual > distanciaMax) {
    distanciaMax = distanciaAtual;
    grauDistanciaMax = 90;
  }

  _servo.mover(180);
  // distancia[2].grau = 180;
  // distancia[2].distancia = ping();
  distanciaAtual = ping();
  Serial.print("Distancia(180) = ");
  Serial.println(distanciaAtual);
  if (distanciaAtual > distanciaMax) {
    distanciaMax = distanciaAtual;
    grauDistanciaMax = 180;
  }
  
  Serial.print("Grau: ");
  Serial.println(grauDistanciaMax);
  return grauDistanciaMax;
  // return 0;
}
