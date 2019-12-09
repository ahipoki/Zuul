#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Command.h"
#include "Room.h"

class Story : public Command
{
  public:
    Story(char*);
    int getType();
    char* returnBurn();
    void printMap(Room**, std::map<char*, Room*>*, std::vector<char*>*);
};