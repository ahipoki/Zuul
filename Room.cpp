#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <map>
#include "Item.h"
#include "Room.h"

Room::Room(char* newTitle, char* newDescription, vector<Item*>* newItems, map<char*, char*>* newExits){
  title = newTitle;
  description = newDescription;
  items = newItems;
  exits = newExits;
}

char* Room::getTitle(){
  //cout << "???" << endl;
  return title;
}

char* Room::getDescription(){
  return description;
}

vector<Item*>* Room::getItems(){
  return items;
}

map<char*, char*>* Room::getExits(){
  //Need to get cardinal directions later
  return exits;
}

Room* Room::getExitRoom(){
  //Hashmap direction
}

void Room::setDescription(char* newDescription){
  description = newDescription;
}

void Room::setExit(char* direction, char* destination){
  (*exits)[direction] = destination; 
}

void Room::addItem(char* itemName){
  items->push_back(new Item(itemName));
}
