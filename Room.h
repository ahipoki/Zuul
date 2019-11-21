#include <iostream>
#include <cstring>

class Room
{
 public:
  Room(char*, char*);
  char* getDescription();
  char* getItem();
 private:
  char* description;
  char* item;
};
