#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <map>
#include "Item.h"
#inlcude "Room.h"
#include "Command.h"
#include "Head.h"
#include "Drop.h"
#include "PickUp.h"
#include "Inventory.h"
#include "Talk.h"
#include "Help.h"
#include "Story.h"

#define HELP_TYPE 2
#define HEAD_TYPE 3
#define PICKUP_TYPE 4
#define DROP_TYPE 5
#define INVENTORY_TYPE 6
#define TALK_TYPE 7
#define STORY_TYPE 8
#define QUIT_TYPE 9

void createRoom(map<char*, Room*>*, char*, char*);
void processInput(char*, char*);
void processCommand(char*, char*, vector<Commmand*>*, map<char*, Room*>*, Room**, vector<Item*>*, vector<Command*>*, vector<char*>*);
void printExit(map<char*>, char*>*);
void printItem(vector<Item*>*);
void printRoom(Room*);

int main()
{
  vector<char*> enRoom;
  vector<char*>* enRoomptr = &enRoom;
  map<char*, Room*>* room = new map<char*, Room*>;
  createRoom(Room, (char*) "Test", (char*) "Description");

  ((*Room)[(char*)"Test"])->setExit((char*)"WEST", (char*)"2nd Room");

  ((*Room)[(char*)"Test"])->addItem((char*)"Item");

  vector<Item*> bag;
  vector<Item*>* bagptr = &bag;

  vector<Command*> commands;
  vector<Command*>* commandsptr = &commands;

  Room* currentRoom;
  Room** currentRoomptr = &currentRoom;
}
