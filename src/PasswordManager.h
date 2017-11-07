#include <Arduino.h>

#ifndef PasswordManager_h
#define PasswordManager_h

class PasswordManager
{
  public:
    PasswordManager(String password_);
    void appendCharacter(char character);
    bool confirmPassword();

  private:
    String password;
    String userInput;
};

#endif