#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Command.h"
#include "Room.h"

class Story : public Command {
 public:
  Plot(char*);
  int getType();
  char* returnBurn();
  void printMap(Room**, map<char*, Room*>*, vector<char*>*);
};
