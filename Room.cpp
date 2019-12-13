#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

Printable::~Printable()
{
  delete[] this->description;
  delete[] this->name;
}

void Printable::print()
{
  cout << CC_BLD << CC_BLU << (this->name) << CC_CLR << endl;
  cout << (this->description) << endl;
}

void Printable::init(char const* name, char const* description)
{
  this->description = new char[strlen(description) + 1];
  this->name = new char[strlen(description) + 1];
  strcpy(this->desription, description);
  strcpy(this->name, name);
}

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
