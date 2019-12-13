#include <iostream>
#include <cstring>
#include "Printable.h"

using namespace std;

Printable::~Printable()
{
  delete[] this->description;
  delete[] this->name;
}

void Printable::print()
{
  cout << CC_BLD << CC_BLU << (this->name) << CC_CLR << endl;
  cout << (this->description) << endl;
}

void Printable::init(char const* name, char const* description)
{
  this->description = new char[strlen(description) + 1];
  this->name = new char[strlen(name) + 1];
  strcpy(this->description, description);
  strcpy(this->name, name);
}
