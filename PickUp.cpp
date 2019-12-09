#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Grab.h"
#include "Item.h"
#include "Room.h"

Grab::Grab(char* newDesc) : Command(newDesc){

}

int Grab::getType(){
  return 4;
}

char* Grab::returnBurn(){
  return (char*) "Congrats! You grabbed thin air!";
}

//Loop through current room items. If the name matches the Item name, create NEW item with desc in player inventory, then DELETE the item from the room.
void Grab::take(Room** currentRoomptr, vector<Item*>* bag, char* itemName){
  bool found = false;
  vector<Item*>::iterator rmIt;
  for(rmIt = ((*currentRoomptr)->getItems())->begin(); rmIt != ((*currentRoomptr)->getItems())->end(); ){
    char* inQ = (*rmIt)->getName();
    char temp[strlen(inQ)+1] = "";
    for(int a = 0; a < strlen(inQ); ++a){
      temp[a] = toupper(inQ[a]);
    }
    if(strcmp((char*)temp, itemName) == 0){
      bag->push_back(new Item(inQ));
      delete (*rmIt);
      rmIt = ((*currentRoomptr)->getItems())->erase(rmIt);
      cout << "Received " << inQ << "!" << endl;
      found = true;
    }else{
      ++rmIt;
    }
  }
  if(found == false){
    cout << "What are you grabbing at?" << endl;
  }
}
