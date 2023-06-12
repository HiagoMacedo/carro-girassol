#include <Arduino.h>
#include <Servo.h>
#include "MeuServo.h"


MeuServo::MeuServo() {}

void MeuServo::mover(int graus)
{
  static int grauAtual;
  if (_posicao < graus) {
    for (grauAtual = _posicao; grauAtual < graus; grauAtual++) {
      write(grauAtual);
    }
  } else {
    for (grauAtual = _posicao; grauAtual > graus; grauAtual--) {
      write(grauAtual);
    }
  }
  _posicao = grauAtual;
}