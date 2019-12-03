#include <iostream>
#include <cstring>
#include "Item.h"

Item::Item(char* newName)
{
  name = newName;
}

char* Item::getName()
{
  return name;
}
