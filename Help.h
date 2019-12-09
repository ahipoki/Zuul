#include <iostream>
#include <cstring>
#include <vector>
#include "Command.h"

class Help : public Command {
 public:
  Help(char*);
  int getType();
  char* returnBurn();
  void printHelp(vector<Command*>*);
};
