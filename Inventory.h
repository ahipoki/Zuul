#include <cstring>
#include <iostream>
#include <vector>
#include "Command.h"
#include "Item.h"

class Inventory : public Command
{
  public:
    Inventory(char*);
    int getType();
    char* returnBurn(char*);
    void show(vector<Item*>*);
  private:
}
