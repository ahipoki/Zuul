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
  this->name = new char[strlen(name) + 1];
  //New name
  strcpy(this->description, description);
  //Copy the description to the new description
  strcpy(this->name, name);
  //Copy the name to the new name
}

Room::Room(char* newTitle)
{
  title = newTitle;
}

char* Room::getTitle()
{
  return title;
}

void Room::printext()
{
  cout << CC_GRN << "Exits: " << CC_CLR;
  for (int i = 0; i < 4; i++)
  {
    if (this->rooms.count(i) > 0)
    {
      cout << CC_CYN << (DIRS[i]) << CC_CLR << ": " << (this->rooms[i]->name) << " ";
    }
  }
  cout << endl;
}

void Room::printItem()
{
  cout << CC_GRN << "Items: " << CC_CLR;
  vector<Item*>::iterator it = this->items.begin();
  while (it != this->items.end())
  {
    cout << ((*it)->name) << " ";
    it++;
  }
  cout << endl;
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
