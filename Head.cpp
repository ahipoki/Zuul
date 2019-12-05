#include <iostream>
#include <cstring>
#include <map>
#include <iterator>
#include "Head.h"
#include "Room.h"

Head::Head(char* newDescription) : Command(newDescription)
{
  
}

int Head::getType()
{
  return 3;
}

char* Head::returnBurn()
{
  return (char*) "You move a direction. (Input your move)";
}

void Head::move(char* key, map<char*, Room*>* rm, Room **currentRoomptr)
{
  std::map<char*, char*>::iterator exitIt;
  map<char*, char*>* exit = (*currentRoomptr)->getExit();
  bool found = false;
  for (exitIt = exit->begin(); exitIt != exit->end(); ++exitIt)
  {
    if (strcmp(exitIt->first, key) == 0)
    {
      (*currentRoomptr) = ((*rm)[exitIt->second]);
      found = true;
    }
  }
  if (found == false)
  {
    std::cout << "That's not a proper direction" << std::endl;
  }
}
