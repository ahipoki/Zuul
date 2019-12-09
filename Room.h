#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"

using namespace std;

class Room{
 public:
  Room(char*, char*, vector<Item*>*, map<char*, char*>*);
  char* getTitle();
  char* getDescription();
  vector<Item*>* getItems();
  map<char*, char*>* getExits();
  Room* getExitRoom();
  void setDescription(char*);
  void setExit(char*, char*);
  void addItem(char*);
 private:
  char* title;
  char* description;
  vector<Item*>* items;
  map<char*, char*>* exits;
};
#endif
