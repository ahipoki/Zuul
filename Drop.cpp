#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Drop.h"
#include "Item.h"
#include "Room.h"

Drop::Drop(char* newDescription) : Command(newDescription){

}

int Drop::getType(){
  return 5;
}

char* Drop::returnBurn(){
  return (char*) "You didn't toss anything! #TeamTrees!";
}

//Loop through current inventory items. If the name matches the Item name, create NEW item with desc in room item list, then DELETE the item from inventory.
void Drop::toss(Room** currentRoomptr, vector<Item*>* bag, char* itemName){
  bool found = false;
  vector<Item*>::iterator inIt;
  for(inIt = bag->begin(); inIt != bag->end(); ){
    char* inQ = (*inIt)->getName();
    char temp[strlen(inQ)+1] = "";
    for(int a = 0; a < strlen(inQ); ++a){
      temp[a] = toupper(inQ[a]);
    }
    if(strcmp((char*)temp, itemName) == 0){
      (*currentRoomptr)->addItem(inQ);
      delete (*inIt);
      inIt = bag->erase(inIt);
      cout << "Littered " << inQ << "!" << endl;
      found = true;
    }else{
      ++inIt;
    }
  }

  if(found == false){
    cout << "What are you aiming at!?!?" << endl;
  }
}
