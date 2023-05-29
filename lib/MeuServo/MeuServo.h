#ifndef MeuServo_h
#define MeuServo_h

#include <Arduino.h>
#include <Servo.h>

class MeuServo : public Servo
{
public:
  MeuServo();
  void init(byte pino_servo);
  void mover(int graus);

private:
  int _posicao;
  int _grauAtual;
};

#endif