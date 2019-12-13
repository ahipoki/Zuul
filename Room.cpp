#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

void Room::deleteItem(Item* toDelete)
{
  vector<Item*>::iterator it = this->items.begin();
  while (it != (this->items.end())) {
    if ((*it) == toDelete) {
      this->items.erase(it);
      return;
    }
    it++;
  }
}
