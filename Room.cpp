#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <map>
#include "Item.h"
#include "Room.h"

Room::Room(char* newTitle, char* newDescription, std::vector<Item*>* newItem, map<char*, char*>* newExit)
{
  title = newTitle;
  description = newDescription;
  item = newItem;
  exit = newExit;
}

char* Room::getTitle()
{
  return title;
}

char* Room::getDescription() 
{
  return description;
}

vector<Item*>* Room::getItem()
{
  return item;
}

map<char*, char*>* Room::getExit()
{
  return exit;
}

Room* Room::getExitRoom()
{
  //Hashmap Direction
}

void Room::setExit(char* direction, char* destination)
{
  (*exit)[direction] = destination;
}

void Room::addItem(char* itemName)
{
  item->push_back(new Item(itemName));
}
