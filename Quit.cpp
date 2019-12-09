#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Quit.h"

Quit::Quit(char* newDescription) : Command(newDescription){

}

int Quit::getType(){
  return 9;
}

char* Quit::returnBurn(){
  return (char*)"Just quit, don't throw a fit! :)";
}

void Quit::getMeOut(){
  cout << "Thanks for playing!" << endl;
  exit(0);
}
