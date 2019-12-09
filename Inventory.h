#include <iostream>
#include <cstring>
#include <vector>
#include "Command.h"
#include "Item.h"

class Sack : public Command {
 public:
  Sack(char*);
  int getType();
  char* returnBurn(char*);
  void show(vector<Item*>*);
 private:
};
