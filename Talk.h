#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Command.h"
#include "Item.h"
#include "Room.h"

class Talk : public Command {
 public:
  Talk(char*, int*);
  int getType();
  char* returnBurn();
  int* getEv();
  void act(map<char*, Room*>*, Room**, vector<Item*>*);
 private:
  int* ev;
};
