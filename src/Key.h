#include <Arduino.h>

#ifndef Key_h
#define Key_h

class Key
{
public:
  Key();
  Key(int minVoltage, int maxVoltage, char character);
  bool isKeyDown(int voltage);
  char character;

private:
  int minVoltage;
  int maxVoltage;
};

#endif