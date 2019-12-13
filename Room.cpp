#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

/* Finn McKinley
 * A simple Zuul project
 * 12/13/19
 */

Printable::~Printable()
{//Destructor
  delete[] this->description;
  delete[] this->name;
  //Delete the char arrays
}

void Printable::print()
{//Print
  cout << CC_BLD << CC_BLU << (this->name) << CC_CLR << endl;
  //Print out the name
  cout << (this->description) << endl;
  //Print out the description
}

void Printable::init(char const* name, char const* description)
{//Initialize
  this->description = new char[strlen(description) + 1];
  //New description
  this->name = new char[strlen(description) + 1];
  //New name
  strcpy(this->desription, description);
  //Copy the description to the new description
  strcpy(this->name, name);
  //Copy the name to the new name
}

void Room::deleteItem(Item* toDelete)
{//Delete item
  vector<Item*>::iterator it = this->items.begin();
  while (it != (this->items.end())) 
  {//Iterate through the items
    if ((*it) == toDelete) 
    {//If the item needs to be deleted
      this->items.erase(it);
      //Delete the item
      return;
    }
    it++;
  }
}
