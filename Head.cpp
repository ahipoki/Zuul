#inlcude <iostream>
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

void Head::Move(char* key, map<char*, Room*>* room, Room **currentRoomptr)
{
  map<char*, char*>::iterator exIt;
  map<char*, char*>* exit = (*currentRoomptr)->getExit();
  bool found = false;
  for (exIt = exit->begin(); exIt != exit->end(); ++exIt)
  {
    if (strcmp(exIt->first, key) == 0)
    {
      (*currentRoomptr) = ((*room)[exIt->second]);
      found = true;
    }
  }
  if (found == false)
  {
    std::cout << "That's not a proper direction" << std::endl;
  }
}
