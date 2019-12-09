#include <iostream>
#include <cstring>
#include "Quit.h"

Quit::Quit(char* newDesc) : Command(newDesc){

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
