#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <"PickUp.h"
#include "Item.h"
#include "Room.h"

PickUp::PickUp(char* newDescription) : Command(newDescription)
{

}

int PickUp::getType()
{
  return 4;
}

char* PickUp::returnBurn()
{
  return (char*) "There were no items to grab";
}

void PickUp::take(Room** currentRoomptr, vector<Item*>* bag, char* itemName)
{
  bool found = false;
  vector<Item*>::iterator roomIt;
  for (roomIt = ((*currentRoomptr)->getItem())->begin(); roomIt != ((*currentRoomptr)->getItem())->end(); )
  {
    char* inQ = (*roomIt)->getName();
    char temp[strlen(inQ)+1] = "";
    for (int a = 0; a < strlen(inQ); ++a)
    {
      temp[a] = tolower(inQ[a]);
    }
    if (strcmp((char*)temp, itemName) == 0)
    {
      bag->push_back(new Item(inQ));
      delete (*roomIt);
      roomIt = ((*currentRoomptr)->getItem())->erase(roomIt
    }
  }
}
