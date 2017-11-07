#include <Arduino.h>
#include "Key.h"

Key::Key()
{
}

Key::Key(int minVoltage_, int maxVoltage_, char character_)
    : minVoltage(minVoltage_), maxVoltage(maxVoltage_), character(character_)
{
}

bool Key::isKeyDown(int voltage)
{
    return voltage >= minVoltage && voltage <= maxVoltage;
}