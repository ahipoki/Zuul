#include <iostream>
#include <cstring>
#include "Quit.h"

Quit::Quit(char* newDescription) : Command(newDescription)
{
  
}

int Quit::getType()
{
  return 9;
}

char* Quit::returnBurn()
{
  return (char*) "You missed quitting. Try again.";
}

void Quit::quit()
{
  std::cout << "You successfully quit" << std::endl;
  exit(0);
}
