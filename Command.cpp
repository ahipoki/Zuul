#include <iostream>
#include <cstring>
#include "Command.h"

using namespace std;

Command::Command(char* newDesc){
  desc = newDesc;
}

char* Command::getDesc(){
  return desc;
}

int Command::getType(){

}

char* Command::returnBurn(){

}
