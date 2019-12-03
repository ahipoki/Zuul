#include <iostream>
#include <cstring>
#include <vector>
#include "Command.h"
#include "Item.h"
#include "Room.h"

class Drop : public Command
{
 public:
  Drop(char*);
  int getType();
  char* returnBurn();
  void drop(Room**, vector<Item*>*, char*);
 private:
};
