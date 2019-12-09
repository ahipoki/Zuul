//Toss is like any other command except the currentRoom, player inventory, and specified item drops are needed
#include <iostream>
#include <cstring>
#include <vector>
#include "Command.h"
#include "Item.h"
#include "Room.h"

class Drop : public Command {
 public:
  Drop(char*);
  int getType();
  char* returnBurn();
  void toss(Room**, vector<Item*>*, char*);
 private:

};
