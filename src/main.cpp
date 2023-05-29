#include <Arduino.h>
#include <avr8-stub.h>
#include <app_api.h>
#include "Ultrassonico.h"
#include "Carro.h"

#define DEBUG 1
#if DEBUG == 1
#include <avr8-stub.h>
#include <app_api.h>
#else
#define debug_init()
#endif

#define MOTOR_A_EN 5
#define MOTOR_A_1 6
#define MOTOR_A_2 7

#define MOTOR_B_EN 8
#define MOTOR_B_1 9
#define MOTOR_B_2 10

#define ECHO 12
#define TRIGGER 13
#define DIST_MAX 25
#define SERVO 11

Motor motorA(MOTOR_A_1, MOTOR_A_2, MOTOR_A_EN);
Motor motorB(MOTOR_B_1, MOTOR_B_2, MOTOR_B_EN);
Carro c(motorA, motorB);
Carro c2;


Ultrassonico sensorUltrassom(TRIGGER, ECHO, 22);
bool temObjeto;

void iniciar()
{
  c.init();

  // sensorUltrassom.init(SERVO);
  delay(100);
}

void setup() 
{
  debug_init(); 
  iniciar();

  delay(300);
}

void loop() 
{
  c.moverFrente(205);
  delay(1000);
  // c.parar();
  // delay(1000);
  // c.girarDireita(1400);
  // c.girarEsquerda(1400);
  c.moverTras(205);
  // motorB.moverTras(150);
  delay(1000);

  // c2.moverFrente(130);
  // delay(3000);
  // c2.parar();
  // delay(3000);
  // c2.girar(1400);

  // motorA.moverFrente(100);
  // motorB.moverFrente(100);
  // delay(3000);
  // motorA.parar();
  // motorB.parar();
  // delay(3000);
}
