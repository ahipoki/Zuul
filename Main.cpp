#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Room.h"
using namespace std;

struct Item {
  char name[80];
  int location;
};

int main() {
  vector<Item*> *vecI = new vector<Item*>;
  vector<Room*> *vecR = new vector<Room*>;
  int pickUp = 0;
  char moveInput[80];
  char dropInput[80];
  char grabInput[80];
  int currentLocation;
  vector<Item*>::iterator j;
  bool win = false;
  std::cout << "Your commands are NORTH, WEST, SOUTH, EAST, HELP, QUIT, INVENTORY, or GRAB" << std::endl;
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
      for (j = vecI->begin(); j != vecI->end(); j++) {
	std::cout << "Name: " << (*j)->name << std::endl;
      }
    }
    else if (strcmp(moveInput, "GRAB") == 0) {
      //std::cout << "You grabbed an item" << std::endl;
      vecI->push_back(new Item());
      std::cout << "Enter the item's name" << std::endl;
      std::cin.getline(vecI->at(vecI->size()-1)->name, 80);
    }
    else if (strcmp(moveInput, "DROP") == 0) {
      std::cout << "What item do you want to drop?" << std::endl;
      cin.getline(dropInput, 80);
      for (j = vecI->begin(); j != vecI->end(); ++j) {
        if (strcmp((*j)->name, dropInput) == 0) {
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
