#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Help.h"

Help::Help(char* newDescription) : Command(newDescription)
{
  
}

int Help::getType()
{
  return 2;
}

char* Help::returnBurn()
{
  return (char*) "Type \"Help\" to get help";
}

void Help::printHelp(vector<Command*>* commands)
{
  vector<Command*>::iterator coIt;
  std::cout << "Your commands are: ";
  for (coIt = commands->begin(); coIt != commands->end(); ++coIt)
  {
    std::cout << (*coIt)->getDescription() << " ";
  }
  std::cout << std::endl;
}
