#ifndef Motor_h
#define Motor_h

#include <Arduino.h>

class Motor
{
public:
  Motor();
  Motor(byte pino1, byte pino2, byte pino_enable);

  void begin();
  void moverFrente(int velocidade);
  void moverTras(int velocidade);
  void parar();

  void setPino1(byte pino_1);
  void setPino2(byte pino_2);
  void setPinoEnable(byte pino_enable);
  void setPinos(byte pino1, byte pino2, byte pino_enable);

private:
  byte _pino1;
  byte _pino2;
  byte _pinoEnable;
};

#endif