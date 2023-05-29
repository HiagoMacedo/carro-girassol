#include "Arduino.h"
#include "Bateria.h"

Bateria::Bateria(byte pino_analogico)
  : _pinoBateria (pino_analogico)
  {}

bool Bateria::checarNivel() // NAO ESTA FUNCIONANDO!!!!!
{
  // https://en.wikipedia.org/wiki/Voltage_divider
  // analogReference(INTERNAL) ??? ou analogReference(DEFAULT) ???
  _valorLido = analogRead(_pinoBateria); // com 9v o valor seria por volta de 168~172
  _tensaoBateria = (_valorLido * 5.0) / 1024.0;
  _tensaoBateria = _tensaoBateria * (22e3 / (22e3 + 220e3));
  // Serial.println(_tensaoBateria);
  // delay(200);
  if (_tensaoBateria > 7.5) {
      return true;
  }
  return false;
}