#include <Arduino.h>
#include <Servo.h>
#include "MeuServo.h"


MeuServo::MeuServo() {}
// MeuServo::MeuServo(byte pino_servo) : _pinoServo(pino_servo) {}

// void MeuServo::begin(byte pino_servo)
// {
//   attach(pino_servo);
//   mover(90);
// }

void MeuServo::mover(int graus)
{
  static int grauAtual;
  static int posicao = 0;
  if (posicao < graus) {
    for (grauAtual = posicao; grauAtual < graus; grauAtual++) {
      write(grauAtual);
    }
  } else {
    for (grauAtual = posicao; grauAtual > graus; grauAtual--) {
      write(grauAtual);
    }
  }
  posicao = grauAtual;
}