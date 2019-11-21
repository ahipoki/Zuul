#include <iostream>
#include <cstring>
#include "Item.h"

Item::Item(char* newName, char* newLocation)
{
  name = new char[strlen(newName)+1];
  strcpy(name, newName);
  location = new char[strlen(newLocation)+1];
  strcpy(location, newLocation);
}

char* Item::getName()
{
  return name;
}

char* Item::getLocation()
{
  return location;
}

//Item name
//Location
