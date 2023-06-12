#ifndef Rastreador_h
#define Rastreador_h

#include <Arduino.h>
#include <Servo.h>

class Rastreador : public Servo {
public:
  Rastreador();

  void begin();
  void update_posicao(const int& valor1, const int& valor2, int& posicao);
  void getValores();
  void readLDR(const int& ldrSuperior_D,const int& ldrSuperior_E, const int& ldrInferior_D, const int& ldrInferior_E);
  void girassol();
  
private:
  int readSuperior_D;
  int readSuperior_E;
  int readInferior_E;
  int readInferior_D;
  int posicao_x;
  int posicao_y;
};

#endif