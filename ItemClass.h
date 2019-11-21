#include <iostream>
#include <cstring>

class Item
{
 public:
  Item(char*, char*);
  char* getName();
  char* getLocation();
 private:
  char* name;
  char* location;
};
