#include <iostream>
#include <cstring>
#include <map>
#include <iterator>
#include "Head.h"
#include "Room.h"

Head::Head(char* newDescription) : Command(newDescription) {
  
}

int Head::getType(){
  return 3;
}

char* Head::returnBurn(){
  return (char*) "You head in the clouds. (Input cardinal direction)";
}

//The move just takes in the userin destination and iterates through the exits to try and find an exit room to set the currentRoom to 
void Head::move(char* key, map<char*, Room*>* rm, Room **currentRoomptr){
  map<char*, char*>::iterator eIt;
  map<char*, char*>* exits = (*currentRoomptr)->getExits();
  bool found = false;
  for(eIt = exits->begin(); eIt != exits->end(); ++eIt){
    if(strcmp(eIt->first, key) == 0){
      (*currentRoomptr) = ((*rm)[eIt->second]);
      found = true;
    }
  }
  if(found == false){
    cout << "No direction found!" << endl;
  }
}
