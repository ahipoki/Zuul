#ifndef ADD_H
#define ADD_H

#include <iostream>
#include <cstring>

class Item
{
 public:
  Item(char*);
  char* getName();
 private:
  char* name;
};

#endif
