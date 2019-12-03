#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Talk.h"
#include "Room.h"
#include "Item.h"

Talk::Talk(char* newDescription, int newEv) : Command(newDescription)
{
  ev = newEv;
}

int Talk::getType()
{
  return 7;
}

char* Talk::returnBurn()
{
  return (char*) "That's an invalid option";
}

int Talk::getEv()
{
  return ev;
}

void Talk::act(map<char*, Room*>* room, Room** currentRoom, vector<Item*>* bag)
{
  char scrollText[80] = "";
  if (strcmp((*currentRoom)->getTitle(), "Test") == 0)
  {
    if (ev[0] == false)
    {
      std::cout << "Testing" << std::endl;
      cin.getline(scrollText, 80);
      cin.clear();
      cin.ignore(999, '\n');
      std::cout << "Done testing" << std::endl;
      ev[0] = true;
    }
    else
    {
      std::cout << "Incomplete testing" << std::endl;
    }
  }
  else if (strcmp((*currentRoom->getTitle(), "Second Room") == 0)
  {
    if (ev[1] == false)
    {
      std::cout << "This is the second room" << std::endl;
      cin.getline(scrollText, 80);
      cin.clear();
      cin.ignore(999, '\n');
      std::cout << "Testing again" << std::endl;
      cin.getline(scrollText, 80);
      cin.clear();
      cin.ignore(999, '\n');
      ev[1] = true;
    }
    else
    {
      std::cout << "Incomplete testing again" << std::endl;
    }
  }
}
