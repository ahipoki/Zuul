#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"

class Room
{
 public:
  Room(char*, char*, std::vector<Item*>*, std::map<char*, char*>*);
  char getTitle();
  char* getDescription();
  std::vector<Item*>* getItem();
  std::map<char*, char*>* getExit();
  Room* getExitRoom();
  void setDescription(char*);
  void setExit(char*, char*);
  void addItem(char*);
 private:
  char* title;
  char* description;
  std::vector<Item*>* item;
  std::map<char*, char*>* exit;
};

#endif
