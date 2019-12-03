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
    void Move(char*, map<char*, Room*>*, Room**);
  private:
}
