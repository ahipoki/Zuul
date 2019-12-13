#pragma once
#include <vector>
#include <map>

#define CC_BLD "\033[1m"
#define CC_BLU "\033[34m"
#define CC_GRN "\033[32m"
#define CC_CLR "\033[0m"
#define CC_CYN "\033[36m"
//Colors

using namespace std;

const char* const DIRS[] = { "NORTH", "EAST", "SOUTH", "WEST" };
//Directions

class Printable
{//Printable class
  public:
   ~Printable();
   char* description;
   char* name;
   void print();
   void init(char const* name, char const* description);
};

class Item : public Printable
{//Item class

};

class Room : public Printable 
{//Room class
 public:
  void printext();
  void printItem();
  void deleteItem(Item* toDelete);
  map<char, Room*> rooms;
  vector<Item*> items;
};
