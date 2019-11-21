#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Room.h"
using namespace std;

struct Item {
  char name[80];
  //char location[80];
};

int main() {
  vector<Item*> *vecI = new vector<Item*>;
  int pickUp = 0;
  char moveInput[80];
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
    //else if (strcmp(moveInput, "QUIT") == 0) {
    //running = false;
    //}
    else if (strcmp(moveInput, "INVENTORY") == 0) {
      for (vector<Item*>::iterator j = vecI->begin(); j != vecI->end(); j++) {
	std::cout << "Name: " << (*j)->name << std::endl;
      }
    }
    else if (strcmp(moveInput, "GRAB") == 0) {
      //std::cout << "You grabbed an item" << std::endl;
      vecI->push_back(new Item());
      std::cout << "Enter the item's name" << std::endl;
      std::cin.getline(vecI->at(vecI->size()-1)->name, 80);
      //std::cout << "Enter the item's location" << std::endl;
      //std::cin.getline(vecI->at(vecI->size()-1)->location, 80);
    }
    else {
      std::cout << "That's an invalid option" << std::endl;
    }
  }
}
