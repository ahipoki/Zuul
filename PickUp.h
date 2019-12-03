#include <cstring>
#include <iostream>
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
    void take(Room**, vector<Item*>*, char*);
  private:
}
