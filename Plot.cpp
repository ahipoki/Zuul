#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Plot.h"
#include "Room.h"

Plot::Plot(char* newDescription) : Command(newDescription)
{
  
}

int Plot::getType()
{
  return 8;
}

char* Plot::returnBurn()
{
  return (char*) "This is a story";
}

void Plot::printMap(Room** currentRoomptr, map<char*, Room*>* room, vector<char*>* eRooms)
{
  vector<char*>::iterator eIt;
  int counter = 0;
  for (roomIt = room->begin(); roomIt != room->end(); ++roomIt)
  {
    bool match = false;
    if (counter == 5 || counter == 10 || counter == 15)
    {
      std::cout << std::endl;
    }
    for (eIt = eRooms->begin(); eIt != eRooms->end(); ++eIt)
    {
      if (strcmp(roomIt->first, (*eIt)) == 0)
      {
        std::cout << roomIt->first();
        if (strcmp(roomIt->first, (*currentRoomptr)->getTitle()) == 0)
        {
          std::cout << "(You)";
        }
        std::cout << "|";
        match = true;
      }
    }
    if (match == false)
    {
      std::cout << "***";
    }
    ++counter;
  }
}
