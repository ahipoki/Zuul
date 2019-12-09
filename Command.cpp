#include <iostream>
#include <cstring>
#include "Command.h"

using namespace std;

Command::Command(char* newDescription){
  description = newDescription;
}

char* Command::getDescription(){
  return description;
}

int Command::getType(){

}

char* Command::returnBurn(){

}
