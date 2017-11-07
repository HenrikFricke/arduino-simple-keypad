#include "Key.h"

#ifndef Keypad_h
#define Keypad_h

#define MAX_KEYS 12

class Keypad
{
public:
  Keypad(int pin_);
  char waitForKey();
  void attachKey(Key *key);

private:
  const char NO_KEY = '#';

  int pin;
  char keyDown = NO_KEY;
  Key *keys[MAX_KEYS];
  int numberOfKeys = 0;

  char getKey();
};

#endif