#include <iostream>
#include <cstring>
#include "Command.h"

Command::Command(char* newDescription)
{
  description = newDescription;
}

char* Command::getDescription()
{
  return description;
}

int Command::getType()
{

}

char* Command::returnBurn()
{

}
