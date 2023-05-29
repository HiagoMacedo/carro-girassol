#include <Arduino.h>
#include <Servo.h>
#include "MeuServo.h"

MeuServo::MeuServo() : _posicao(0) {}

void MeuServo::init(byte pino_servo)
{
  attach(pino_servo);
  mover(90);
}

void MeuServo::mover(int graus)
{
  if (_posicao < graus) {
    for (_grauAtual = _posicao; _grauAtual < graus; _grauAtual++) {
      write(_grauAtual);
    }
  } else {
    for (_grauAtual = _posicao; _grauAtual > graus; _grauAtual--) {
      write(_grauAtual);
    }
  }
  _posicao = _grauAtual;
}