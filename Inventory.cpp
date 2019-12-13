#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Inventory.h"
#include "Item.h"

Inventory::Inventory(char* newDescription) : Command(newDescription)
{

}

int Inventory::getType()
{
  return 6;
}

char* Inventory::returnBurn(char* key)
{
  return key;
}

void Inventory::show(vector<Item*>* bag)
{  
  vector<Item*>::iterator bagIt;
  if(bag->begin()!=bag->end()){
    for(bagIt = bag->begin(); bagIt != bag->end(); ++bagIt)
    {
      cout << (*bagIt)->getName() << " ";
    }
    cout << endl;
  }
  else
  {
    cout << "You don't have anything..." << endl;
  }
}
