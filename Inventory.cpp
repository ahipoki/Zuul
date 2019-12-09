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
  char* getDesc();
  vector<Item*>* getItems();
  map<char*, char*>* getExits();
  Room* getExitRoom();
  void setDesc(char*);
  void setExit(char*, char*);
  void addItem(char*);
 private:
  char* title;
  char* desc;
  vector<Item*>* items;
  map<char*, char*>* exits;
};
#endif
