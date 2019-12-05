#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <map>
#include "Item.h"
#include "Room.h"
#include "Command.h"
#include "Head.h"
#include "Drop.h"
#include "PickUp.h"
#include "Inventory.h"
#include "Talk.h"
#include "Help.h"
#include "Story.h"
#include "Quit.h"

#define HELP_TYPE 2
#define HEAD_TYPE 3
#define PICKUP_TYPE 4
#define DROP_TYPE 5
#define INVENTORY_TYPE 6
#define TALK_TYPE 7
#define STORY_TYPE 8
#define QUIT_TYPE 9

void createRoom(std::map<char*, Room*>*, char*, char*);
void processInput(char*, char*);
void processCommand(char*, char*, std::vector<Command*>*, std::map<char*, Room*>*, Room**, std::vector<Item*>*, std::vector<Command*>*, std::vector<char*>*);
void printExit(std::map<char*, char*>*);
void printItem(std::vector<Item*>*);
void printRoom(Room*);

int main()
{
  std::vector<char*> enRoom;
  std::vector<char*>* enRoomptr = &enRoom;
  std::map<char*, Room*>* rm = new std::map<char*, Room*>;
  createRoom(rm, (char*) "Test", (char*) "Description");

  ((*rm)[(char*)"Test"])->setExit((char*)"WEST", (char*)"2nd Room");

  ((*rm)[(char*)"Test"])->addItem((char*)"Item");

  std::vector<Item*> bag;
  std::vector<Item*>* bagptr = &bag;

  std::vector<Command*> commands;
  std::vector<Command*>* commandsptr = &commands;

  Room* currentRoom;
  Room** currentRoomptr = &currentRoom;
  Room* lastRoom = ((*rm)[(char*)"Last Room"]);
  
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
  currentRoom = ((*rm)[(char*)"Test"]);
  std::cout << "This is a zuul game and a placeholder" << std::endl;
  printRoom(currentRoom);
  while (running == true)
  {
    std::vector<char*>::iterator i;
    bool found = false;
    for (i = enRoom.begin(); i != enRoom.end(); ++i)
    {
      if (strcmp((*i)->getTitle(), currentRoom->getTitle()) == 0)
      {
        found = true;
      }
    }
    if (found == false)
    {
      enRoom.push_back(currentRoom->getTitle());
    }
    if (lastRoom != currentRoom)
    {
      printRoom(currentRoom);
      lastRoom = currentRoom;
    }
    processInput(commandsptr, keywordstr);
    processCommand(commandstr, keywordstr, commandsptr, rm, currentRoomptr, bagptr, commandsptr, enRoomptr);
    
    int* ev = ((Talk*)(commands.at(5)))->getEv();
    if (currentRoom == (*rm)[(char*)"Test"])
    {
      if (ev[0] == true)
      {
        ((*rm)[(char*)"Test"])->setDescription((char*)"Testing");
        ((*rm)[(char*)"Test"])->setExit((char*)"EAST", (char*)"2nd Room");
        ((*rm)[(char*)])->addItem((char*)"Item");
        ev[0] = 2;
        printRoom(currentRoom);
      }
    }
  }
}

void createRoom (std::map<char*, Room*>* room, char* roomTitle, char* roomDescription)
{
  (*rm)[roomTitle] = new Room(roomTitle, roomDescription, new std::vector<Item*>, new std::map<char*, char*>);
}

void processInput(char* commandstr, char* keywordstr)
{
  char input[80];
  while (true)
  {
    int spaces = 0;
    std::cin.getline(input, 80);
    std::cin.clear();
    std::cin.ignore(999, '\n');
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
        if (index != 0 && index != strlen(input)-1)
        {
          char first[index+1] = "";
          char second[(strlen(input)-index)] = "";
          for (int i = 0; i < index; ++i)
          {
            first[i] = input[i];
          }
          for (int i = index + 1; i < strlen(input); ++i)
          {
            second[i-index-1] = input[i];
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

void processCommand(char* commandstr, char* keywordstr, std::vector<Command*>* commandsptr, std::map<char*, Room*>* rm, Room** currentRoomptr, std::vector<Item*>* bagptr, std::vector<Command*>* commands, std::vector<char*>* enRoomptr)
{
  std::vector<Command*>::iterator commandIt;
  bool found = false;
  for (commandIt = commandsptr->begin(); commandIt != commandsptr->end(); ++commandIt)
  {
    if (strcmp((*commandIt)->getDescription(), commandstr) == 0)
    {
      found = true;
      break;
    }
  }
  if (found == false)
  {
    std::cout << "That's an invalid command" << std::endl;
  }
  else
  {
    int type = (*commandIt)->getType();
    switch (type)
    {
    case HEAD_TYPE:
      if (strcmp(keywordstr, "") != 0)
      {
	((Head*)(*commandIt))->move(keywordstr, rm, currentRoomptr);
      }
      else
      {
	std::cout << ((Head*)(*commandIt))->returnBurn() << std::endl;
      }
      break;
    case HELP_TYPE:
      if (strcmp(keywordstr, "") != 0)
      {
	((Help*)(*commandIt))->printHelp(commands);
      }
      else
      {
	std::cout << ((Help*)(*commandIt))->returnBurn() << std::endl;
      }
      break;
    case PICKUP_TYPE:
      if (strcmp(keywordstr, "") != 0)
      {
	((PickUp*)(*commandIt))->take(currentRoomptr, bagptr, keywordstr);
      }
      else
      {
	std::cout << ((PickUp*)(*commandIt))->returnBurn() << std::endl;
      }
      break;
    case DROP_TYPE:
      if (strcmp(keywordstr, "") != 0)
      {
	((*Drop)(*commandIt))->drop(currentRoomptr, bagptr, keywordstr);
      }
      else
      {
	std::cout << ((Drop*)(*commandIt))->returnBurn() << std::endl;
      }
      break;
    case INVENTORY_TYPE:
      if (strcmp(keywordstr, "") != 0)
      {
	((Inventory*)(*commandIt))->show(bagptr);
      }
      else
      {
	std::cout << "That's the wrong command" << std::endl;
      }
      break;
    case TALK_TYPE:
      if (strcmp(keywordstr, "") != 0)
      {
	((Talk*)(*commandIt))->act(rm, currentRoomptr, bagptr);
      }
      else
      {
	std::cout << ((Talk*)(*commandIt))->returnBurn();
      }
      break;
    case STORY_TYPE:
      if (strcmp(keywordstr, "") != 0)
      {
	((Story*)(*commandIt))->printMap(currentRoomptr, rm, enRoomptr);
      }
      else
      {
	std::cout << ((Story*)(*commandIt))->returnBurn() << std::endl;
      }
      break;
    case QUIT_TYPE:
      if (strcmp(keywordstr, "") != 0)
      {
	((Quit*)(*commandIt))->quit();
      }
      else
      {
	std::cout << ((Quit*)(*commandIt))->returnBurn() << std::endl;
      }
      break;
    }
  }
}

void printItem(std::vector<Item*>* item)
{
  std::vector<Item*>::iterator itemIt;
  for (itemIt = item->begin(); itemIt != item->end(); ++itemIt)
  {
    std::cout << (*itemIt)->getName() << " ";
  }
  std::cout << std::endl;
}

void printRoom(Room* currentRoom)
{
  std::cout << "Current Room: " << currentRoom << std::endl;
  std::cout << "Exits: ";
  printExit(currentRoom)->getExit();
  std::cout << "Items: ";
  printItem(currentRoom->getItem());
}
