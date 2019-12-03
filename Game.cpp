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
  Room* lastRoom = ((*room)[(char*)"Last Room"]);
  
  char commandsarray[80];
  char* commandstr = commandsarray;
  char keywordsarray[80];
  char* keywordstr = keywordsarray;
  
  commandsptr->push_back(new Help((char*)"help"));
  commandsptr->push_back(new Head((char*)"head"));
  commandsptr->push_back(new PickUp((char*)"pickup"));
  commandsptr->push_back(new Drop((char*)"drop"));
  commandsptr->push_back(new Inventory((char*)"inventory"));
  int* e = new int[15];
  for (int i = 0; i < 15; ++i)
  {
    e[i] = 0;
  }
  commandsptr->push_back(new Talk((char*)"talk", e));
  commandsptr->push_back(new Quit((char*)"quit"));
  
  bool running = true;
  currentRoom = ((*room)[(char*)"Test"]);
  std::cout << "This is a zuul game and a placeholder" << std::endl;
  printRoom(currentRoom);
  while (running == true)
  {
    vector<char*>::iterator i;
    bool found = false;
    for (i = enRooms.begin(); i != enRooms.end(); ++i)
    {
      if (strcmp((*i), currentRoom->getTitle()) == 0)
      {
        found = true;
      }
    }
    if (found == false)
    {
      enRooms.push_back(currentRoom->getTitle());
    }
    if (lastRoom != currentRoom)
    {
      printRoom(currentRoom);
      lastRoom = currentRoom;
    }
    processInput(commandsptr, keywordstr);
    processCommand(commandstr, keywordstr, commandsptr, room, currentRoomptr, bagptr, commandsptr, enRoomsptr);
    
    int* ev = ((Talk*)(commands.at(5)))->getEv();
    if (currentRoom == (*room)[(char*)"Test"])
    {
      if (ev[0] == true)
      {
        ((*room)[(char*)"Test"])->setDescription((char*)"Testing");
        ((*room)[(char*)"Test"])->setExit((char*)"EAST", (char*)"2nd Room");
        ((*room)[(char*)])->addItem((char*)"Item");
        ev[0] = 2;
        printRoom(currentRoom);
      }
    }
  }
}

void createRoom (map<char*, Room*>* room, char* roomTitle, char* roomDescription)
{
  (*room)[roomTitle] = new Room(roomTitle, roomDescription, new vector<Item*>, new map<char*, char*>);
}

void processInput(char* commandstr, char* keywordstr)
{
  char input[80];
  while (true)
  {
    int spaces = 0;
    cin.getline(input, 80);
    cin.clear();
    cin.ignore(999, '\n');
    if (strlen(input) != 0)
    {
      for (int i = 0; i < strlen(input); ++i)
      {
        input[i] = tolower(input[i]);
        if (input[i] == ' ')
        {
          ++spaces;
        }
      }
      if (spaces == 0)
      {
        strcpy(commandstr, input);
        strcpy(keywordstr, "");
        break;
      }
      else if (spaces == 1)
      {
        int index;
        for (int i = 0; i < strlen(input); ++i)
        {
          if (input[i] == ' ')
          {
            index = i;
            break;
          }
        }
        if (index != 0 && index != stlen(input)-1)
        {
          char first[index+1] == "";
          char second[(strlen(input)-index)] = "";
          for (int i = 0; i < index; ++i)
          {
            first[i] = input[i];
          }
          for (int i = index + 1; i < strlen(input); ++i)
          {
            second[a-index-1] = input[i];
          }
          strcpy(commandstr, first);
          strcpy(keywordstr, second);
          break;
        }
      }
    }
    std::cout << "That's an invalid command." << std::endl;
  }
}

void processCommand(char* commandstr, char* keywordstr, vector<Command*>* commandsptr, map<char*, Room*>* room, Room** currentRoomptr, vector<Item*>* bagptr, vector<Command*>* commands, vector<char*>* enRoomsptr)
{
  
}








