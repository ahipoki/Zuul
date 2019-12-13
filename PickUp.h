//Grab is like anyother command but the player inventory, specified item to take, and the currentRoom are needed
#include <iostream>
#include <cstring>
#include <vector>
#include "Command.h"
#include "Item.h"
#include "Room.h"

class PickUp : public Command
{
 public:
  PickUp(char*);
  int getType();
  char* returnBurn();
  //Give: current room, player inventory, specified itemName 
  void take(Room**, vector<Item*>*, char*);
 private:
};
