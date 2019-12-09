#include <iostream>
#include <cstring>
#include "Command.h"

class Quit : public Command {
 public:
  Quit(char*);
  int getType();
  char* returnBurn();
  void getMeOut();
 private:
};
