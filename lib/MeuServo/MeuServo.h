#ifndef MeuServo_h
#define MeuServo_h

#include <Arduino.h>
#include <Servo.h>

class MeuServo : public Servo
{
public:
  MeuServo();
  void mover(int graus);

private:
  int _posicao;
};

#endif