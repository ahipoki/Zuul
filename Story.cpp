#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Plot.h"
#include "Room.h"

Plot::Plot(char* newDesc) : Command(newDesc) {
  
}

int Plot::getType(){
  return 8;
}

char* Plot::returnBurn(){
  return (char*) "This ain't no treasure map!";
}

void Plot::printMap(Room** currentRoomptr, map<char*,Room*>* rm, vector<char*>* encRooms){
  vector<char*>::iterator enIt;
  map<char*,Room*>::iterator rmIt;

  int counter = 0;
  for(rmIt = rm->begin(); rmIt != rm->end(); ++rmIt){
    bool match = false;
    if(counter == 5 || counter == 10 || counter == 15){
	cout << endl;
    }
    for(enIt = encRooms->begin(); enIt != encRooms->end(); ++enIt){
      if(strcmp(rmIt->first, (*enIt)) == 0){
	  cout << rmIt->first;
	  if(strcmp(rmIt->first, (*currentRoomptr)->getTitle()) == 0){
	    cout << "(YOU)";
	  }
	  cout << "|";
	  match = true;
      }
    }
    if(match == false){
      cout << "***************|";
    }
    ++counter;
  }
 
}
