#include <Arduino.h>
#include "Ultrassonico.h"
#include "Carro.h"
#include "MeuServo.h"
#include "Rastreador.h"

#define MOTOR_A_EN 5
#define MOTOR_A_1 6
#define MOTOR_A_2 7

#define MOTOR_B_1 8
#define MOTOR_B_2 9
#define MOTOR_B_EN 10

#define SERVO_ULTRASSOM 11
#define ECHO 4
#define TRIGGER 3

#define SERVO_NORTE_SUL 12
#define SERVO_LESTE_OESTE 13

#define MAX_DISTANCIA 25
#define VELOCIDADE 140
#define GIRAR_90 1400
#define GIRAR_45 700

Motor motorA(MOTOR_A_1, MOTOR_A_2, MOTOR_A_EN);
Motor motorB(MOTOR_B_1, MOTOR_B_2, MOTOR_B_EN);

Carro carro;

Ultrassonico sensorUltrassom(TRIGGER, ECHO, SERVO_ULTRASSOM);

void iniciar()
{
  carro.begin();
  sensorUltrassom.begin();
  
  delay(100);
}

void setup() 
{
  iniciar();

  delay(300);
}

void loop() 
{
  while(!sensorUltrassom.checarObjeto(MAX_DISTANCIA)) {
    carro.moverFrente(VELOCIDADE);
    // delay(200);
  }
  carro.parar();
  delay(100);
  switch (sensorUltrassom.checarArea(MAX_DISTANCIA)) {
  case 1: /* 1 grau */
    carro.girarDireita(1400);
    delay(400);
    break;
  case 2: /* 90 graus */
    carro.moverFrente(VELOCIDADE);
    delay(400);
    break;
  case 3: /* 180 graus */
    carro.girarEsquerda(1400);
    delay(400);
    break;
  default: /* dar uma volta */
    carro.moverTras(VELOCIDADE);
    delay(400);
    break;
  }
}