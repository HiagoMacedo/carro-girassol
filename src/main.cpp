#include <Arduino.h>
#include <avr8-stub.h>
#include <app_api.h>
#include "Ultrassonico.h"
#include "Carro.h"
#include "MeuServo.h"

#define DEBUG 0
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

#define TRIGGER 10
#define ECHO 11
#define DIST_MAX 25
#define SERVO 9

Motor motorA(MOTOR_A_1, MOTOR_A_2, MOTOR_A_EN);
Motor motorB(MOTOR_B_1, MOTOR_B_2, MOTOR_B_EN);
// Carro c(motorA, motorB);
Carro c;
MeuServo servo;

Ultrassonico sensorUltrassom(TRIGGER, ECHO, SERVO);
bool temObjeto;

void iniciar()
{
  // c.init(motorA, motorB, sensorUltrassom, SERVO);
  Serial.begin(9600);
  // servo.attach(SERVO);
  sensorUltrassom.begin();
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
  Serial.print("checarArea = ");
  Serial.println(sensorUltrassom.checarArea(25));
  delay(3000);
  // Serial.print("Distancia = ");
  // Serial.print(sensorUltrassom.ping());
  // Serial.println("cm");
  // delay(100);
}
