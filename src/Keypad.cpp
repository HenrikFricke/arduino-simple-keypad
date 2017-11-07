#include <Arduino.h>
#include "Keypad.h"
#include "Key.h"

Keypad::Keypad(int pin_) : pin(pin_)
{
}

char Keypad::waitForKey()
{
  char pressedKey = NO_KEY;
  while ((pressedKey = getKey()) == NO_KEY)
  {
  }
  return pressedKey;
}

void Keypad::attachKey(Key *key)
{
  keys[numberOfKeys] = key;
  numberOfKeys++;
}

// private
char Keypad::getKey()
{
  const int voltage = analogRead(pin);

  char pressedButton = NO_KEY;
  char returnValue = NO_KEY;

  for (int i = 0; i < numberOfKeys; i++)
  {
    if (keys[i]->isKeyDown(voltage))
    {
      pressedButton = keys[i]->character;
    }
  }

  if (pressedButton != NO_KEY && keyDown == NO_KEY)
  {
    keyDown = pressedButton;
  }
  else if (pressedButton == NO_KEY && keyDown != NO_KEY)
  {
    returnValue = keyDown;
    keyDown = NO_KEY;
  }

  return returnValue;
}