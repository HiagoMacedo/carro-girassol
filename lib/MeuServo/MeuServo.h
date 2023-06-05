#ifndef MeuServo_h
#define MeuServo_h

#include <Arduino.h>
#include <Servo.h>

class MeuServo : public Servo
{
public:
  MeuServo(byte pino_servo);
  void init();
  void mover(int graus);

private:
  byte _pinoServo;
  // int _posicao;
  // int _grauAtual;
};

#endif