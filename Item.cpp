#include <iostream>
#include <cstring>
#include "Item.h"

Item::Item(char* newName, int newLocation)
{
  name = new char[strlen(newName)+1];
  strcpy(name, newName);
  location = newLocation;
}

char* Item::getName()
{
  return name;
}

int Item::getLocation()
{
  return location;
}
