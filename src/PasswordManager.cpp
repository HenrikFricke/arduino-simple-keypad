#include <Arduino.h>
#include "PasswordManager.h"

PasswordManager::PasswordManager(String password_) : password(password_)
{
}

void PasswordManager::appendCharacter(char character)
{
  userInput = String(userInput + character);
}

bool PasswordManager::confirmPassword()
{
  bool isValidPassword = userInput == password;
  userInput = "";

  return isValidPassword;
}