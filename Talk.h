#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Command.h"
#include "Item.h"
#include "Room.h"

class Talk : public Command
{
 public:
  Talk(char*, int*);
  int getType();
  char* returnBurn();
  int* getEv();
  void act(std::map<char*, Room*>*, Room**, std::vector<Item*>*);
 private:
  int* ev;
};
