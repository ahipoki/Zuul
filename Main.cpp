#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Room.h"
#include "Item.h"
using namespace std;

int main() {
  vector<Room*> vecR;
  vector<Room*>*rvecR = &vecR;
  vector<Item*> vecI;
  vector<Item*>*ivecI = &vecI;
  int pickUp = 0;
  char moveInput[80];
  char dropInput[80];
  char grabInput[80];
  char tempName[80];
  int tempLocation;
  int currentLocation;
  vector<Item*>::iterator j;
  bool win = false;
  std::cout << "Your commands are NORTH, WEST, SOUTH, EAST, HELP, INVENTORY, or GRAB" << std::endl;
  while (win == false) {
    std::cout << "Do you want to move NORTH, WEST, SOUTH, or EAST?" << std::endl;
    std::cin.getline(moveInput, 80);
    for (int i = 0; i < strlen(moveInput); i++) {
      moveInput[i] = toupper(moveInput[i]);
    }
    if (strcmp(moveInput, "NORTH") == 0) {
      std::cout << "You moved north" << std::endl;
    }
    else if (strcmp(moveInput, "WEST") == 0) {
      std::cout << "You moved west" << std::endl;
    }
    else if (strcmp(moveInput, "SOUTH") == 0) {
      std::cout << "You moved south" << std::endl;
    }
    else if (strcmp(moveInput, "EAST") == 0) {
      std::cout << "You moved east" << std::endl;
    }
    else if (strcmp(moveInput, "HELP") == 0) {
      std::cout << "Your commands are NORTH, WEST, SOUTH, EAST, HELP, QUIT, or GRAB" << std::endl;
    }
    else if (strcmp(moveInput, "INVENTORY") == 0) {
      for (j = ivecI->begin(); j != ivecI->end(); j++) {
	std::cout << "Name: " << ((Item*)(*j))->name << std::endl;
      }
    }
    else if (strcmp(moveInput, "GRAB") == 0) {
      //std::cout << "You grabbed an item" << std::endl;
      //ivecI->push_back(new Item());
      std::cout << "Enter the item's name" << std::endl;
      //std::cin.getline(vecI->at(vecI->size()-1)->name, 80);
      cin.getline(tempName, 80);
      std::cout << "Enter the item's location" << std::endl;
      cin >> tempLocation;
      cin.clear();
      cin.ignore(999, '\n');
      ivecI->push_back(new Item(tempName, tempLocation));
    }
    else if (strcmp(moveInput, "DROP") == 0) {
      std::cout << "What item do you want to drop?" << std::endl;
      cin.getline(dropInput, 80);
      for (j = ivecI->begin(); j != ivecI->end(); ++j) {
        if (strcmp((*j)->getName(), dropInput) == 0) {
          std::cout << "You dropped" << dropInput << "in the room" << std::endl;
	  (*j)->location = currentLocation;
        }
      }
    }
    else {
      std::cout << "That's an invalid option" << std::endl;
    }
  }
}
