#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Help.h"

Help::Help(char* newDescription) : Command (newDescription) {
  
}

int Help::getType(){
  return 2;
}

char* Help::returnBurn(){
  return (char*) "Just type \"Help\" lol";
}

void Help::printHelp(vector<Command*>* commands){
  vector<Command*>::iterator comIt;
  cout << "Your commands are: ";
  for(comIt = commands->begin(); comIt != commands->end(); ++comIt){
    cout << (*comIt)->getDesc() << " ";
  }
  cout << endl;
}
