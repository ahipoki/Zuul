#include <iostream>
#include <cstring>

class Item
{
 public:
  Item(char*, int);
  char* getName();
  int getLocation();
  char* name;
  int location;
 private:
  //int location;
};
