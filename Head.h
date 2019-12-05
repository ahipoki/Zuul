#include <iostream>
#include <cstring>
#include <map>
#include "Command.h"
#include "Room.h"

class Head : public Command
{
  public:
    Head(char*);
    int getType();
    char* returnBurn();
    void move(char*, std::map<char*, Room*>*, Room**);
    char* room;
  private:
};
