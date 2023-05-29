#include <stdint.h>
#ifndef Carro_h
#define Carro_h

#include <Arduino.h>
#include "Motor.h"
#include "Ultrassonico.h"
#include "MeuServo.h"

class Carro
{
public:
  Carro();
  Carro(Motor& motorA, Motor& motorB);
  // Carro(Motor& motorA, Motor& motorB)

  void init();  /// Inicia os motores do carro
  void moverFrente(byte velocidade);
  void moverTras(byte velocidade);
  void parar(); /// para os motores do carro
  void girarDireita(unsigned int tempo_ms);  /// 1400ms = 90 graus | 700ms = 45 graus
  void girarEsquerda(unsigned int tempo_ms);

  // Motor getMotorA();
  // Motor getMotorB();

private:
  Motor _motorA;  // Direito
  Motor _motorB;  // Esquerdo
  MeuServo _servo;
  Ultrassonico _sensorUltrassom;
};

#endif