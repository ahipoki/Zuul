#include <iostream>
#include <cstring>
#include "Room.h"

Room::Room(char* newDescription, char* newItem)
{
  description = new char[strlen(newDescription)+1];
  strcpy(description, newDescription);
  item = new char[strlen(newItem)+1];
  strcpy(item, newItem);
}

char* Room::getDescription()
{
  return description;
}

char* Room::getItem()
{
  return item;
}
