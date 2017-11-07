#include "Keypad.h"
#include "Key.h"
#include "PasswordManager.h"

const int greenPin = 13;
const int redPin = 12;

PasswordManager pm = PasswordManager("1324");
Keypad kpd = Keypad(A0);
Key keyOne = Key(5, 10, '1');
Key keyTwo = Key(505, 515, '2');
Key keyThree = Key(990, 1010, '3');
Key keyFour = Key(965, 980, '4');
Key confirmButton = Key(1023, 1023, '*');

void setup()
{
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);

  kpd.attachKey(&keyOne);
  kpd.attachKey(&keyTwo);
  kpd.attachKey(&keyThree);
  kpd.attachKey(&keyFour);
  kpd.attachKey(&confirmButton);

  digitalWrite(redPin, HIGH);
}

void loop()
{
  char key = kpd.waitForKey();

  if (key == '*')
  {
    if (pm.confirmPassword())
    {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);

      delay(5000);

      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
    }
    else
    {
      digitalWrite(redPin, LOW);
      delay(100);
      digitalWrite(redPin, HIGH);
    }
  }
  else
  {
    pm.appendCharacter(key);
  }

  delay(200);
}