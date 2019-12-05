#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Inventory.h"
#include "Item.h"

/*
 *Method to check your inventory
 *.cpp file
 */

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
  std::vector<Item*>::iterator bagIt;
  if (bag->begin() != bag->end())
  {
    for (bagIt = bag->begin(); bagIt != bag->end(); ++bagIt)
    {
      std::cout << (*bagIt)->getName() << " " << std::endl;
    }
    std::cout << std::endl;
  }
  else
  {
    std::cout << "You don't have any items" << std::endl;
  }
}
