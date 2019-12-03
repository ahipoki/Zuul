#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Toss.h"

Drop::Drop(char* newDescription) : Command(newDescription)
{
  
}

int Drop::getType()
{
  return 5;
}

char* Drop::returnBurn()
{
  return (char*) "You didn't drop any items";
}

void Drop::drop(Room** currentRoomptr, vector<Item*>* bag, char* itemName)
{
  bool found = false;
  vector<Item*>::iterator inIt;
  for(inIt = bag->begin(); inIt != bag->end(); ++inIt)
  {
    char* inQ = (*inIt)->getName();
    char temp[strlen(inQ)+1] = "";
    for (int i = 0; i < strlen(inQ); ++i)
    {
      temp[i] = tolower(inQ[i]);
    }
    if (strcmp((char*)temp, itemName) == 0)
    {
      (*currentRoomptr)->addItem(inQ);
      delete (*inIt);
      inIt = bag->erase(inIt);
      std::cout "You dropped " << inQ << std::endl;
      found = true;
    }
    else
    {
      ++inIt;
    }
  }
  if (found == false)
  {
    std::cout << "You didn't drop anything" << std::endl;
  }
}
