#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

void strupper(char* str);
void deleteItem(Item* itm, vector<Item*>* delFrom);
int directionToIndex(char* dir);
int wordlen(char*, int start);
Room* createRooms(vector<Room*> &rooms, vector<Item*> &items);
Item* findItem(char const* name, vector<Item*>* items);

int main()
{
  vector<Item*> items;
  vector<Room*> cleanRooms;
  vector<Item*> cleanItems;
  Room* currentRoom = createRooms(cleanRooms, cleanItems);
  bool playing = true;
  char input[80];
  currentRoom->print();
  currentRoom->printItem();
  currentRoom->printext();
  while(playing)
  {
    while(cin.peek() == '\n')
    {
      cin.ignore();
    }
    cin.get(input, 100, '\n');

    //Parse command
    int commandlen = wordlen(input, 0);
    char* command = new char[commandlen + 1];
    command[commandlen] = '\0';
    strncpy(command, input, commandlen);
    strupper(command);


    if(strcmp(command, "QUIT") == 0)
    {
      playing = false;
    }
    else if(strcmp(command, "GO") == 0)
    {
      int arglen = wordlen(input, commandlen + 1);
      char* direction = new char[arglen + 1];
      direction[arglen] = '\0';
      strncpy(direction, input + commandlen + 1, arglen);
      strupper(direction);

      int dirI = directionToIndex(direction);
      if(dirI == -1)
      {
	cout << "That's not a direction." << endl;
      }
      else if(currentRoom->rooms.count(dirI) == 0)
      {
	cout << "That's not an exit." << endl;
      }
      else
      {
	currentRoom = currentRoom->rooms[dirI];
	currentRoom->print();
	currentRoom->printItem();
      }

      delete[] direction;
    }
    else if(strcmp(command, "ROOM") == 0)
    {
      currentRoom->print();
    }
    else if(strcmp(command, "ITEMS") == 0)
    {
      currentRoom->printItem();
    }
    else if(strcmp(command, "EXITS") == 0)
    {
      currentRoom->printext();
    }
    else if(strcmp(command, "PICKUP") == 0)
    {
      int arglen = wordlen(input, commandlen + 1);
      char* item = new char[arglen + 1];
      item[arglen] = '\0';
      strncpy(item, input + commandlen + 1, arglen);
      strupper(item);

      Item* topick = findItem(item, &(currentRoom->items));
      if(topick == NULL) cout << "No such item." << endl;
      else
      {
        items.push_back(topick);
        currentRoom->deleteItem(topick);
        cout << "Picked Up " << topick->name << endl;
      }
      delete[] item;
    }
    else if(strcmp(command, "DROP") == 0)
    {
      int arglen = wordlen(input, commandlen + 1);
      char* item = new char[arglen + 1];
      item[arglen] = '\0';
      strncpy(item, input + commandlen + 1, arglen);
      strupper(item);

      Item* topick = findItem(item, &items);
      if(topick == NULL) cout << "No such item." << endl;
      else
      {
        currentRoom->items.push_back(topick);
        deleteItem(topick, &items);
        cout << "Dropped " << topick->name << endl;
      }
      delete[] item;
    }
    else if(strcmp(command, "INSPECT") == 0)
    {
      int arglen = wordlen(input, commandlen + 1);
      char* item = new char[arglen + 1];
      item[arglen] = '\0';
      strncpy(item, input + commandlen + 1, arglen);
      strupper(item);

      Item* topick = findItem(item, &items);
      if(topick == NULL) cout << "No such item." << endl;
      else
      {
        topick->print();
      }
      delete[] item;
    }
    else if(strcmp(command, "INVENTORY") == 0)
    {
      cout << CC_GRN << "Inventory: " << CC_CLR;
      vector<Item*>::iterator it = items.begin();
      while(it != items.end())
      {
        cout << ((*it)->name) << " ";
        it++;
      }
      cout << endl;
    }
    else if(strcmp(command, "HELP") == 0)
    {
      cout << CC_GRN << "Find all the items!" << endl;
      cout << CC_CYN << "Commands: QUIT, GO, ROOM, ITEMS, EXITS, PICKUP, DROP, INSPECT, INVENTORY, HELP" << endl;
      cout << CC_BLU << "Commands are not case sensitive!" << CC_CLR << endl;
    }
    else
    {
      cout << "Unrecognized Command." << endl;
    }

    if(items.size() == 5)
    {
      cout << CC_GRN << "You found all the \"Necessary Items\"! You Win!" << CC_CLR << endl;
      cout << CC_BLU << "(I needed some way to end the game so..)" << CC_CLR << endl;
      playing = false;
    }

    delete[] command;
  }

  for(vector<Room*>::iterator i = cleanRooms.begin(); i != cleanRooms.end(); i++)
  {
    // cout << "[Cleanup] Deleting Room " << ((*i)->name) << endl;
    delete (*i);
  }

  for(vector<Item*>::iterator i = cleanItems.begin(); i != cleanItems.end(); i++)
  {
    // cout << "[Cleanup] Deleting Item " << ((*i)->name) << endl;
    delete (*i);
  }

  return 0;
}

void strupper(char* str)
{
  int len = strlen(str);
  for(int i = 0; i < len; i++){
    str[i] = toupper(str[i]);
  }
}

int directionToIndex(char* direction)
{
  strupper(direction);
  for(int i = 0; i < 4; i ++){
    if(strcmp(direction, DIRS[i]) == 0) return i;
  }
  return -1;
}

Room* createRooms(vector<Room*> &rooms, vector<Item*> &items)
{
  Room* araragiHouse = new Room();
  araragiHouse->init("The Araragi Residence", "Oh so messy.");
  rooms.push_back(araragiHouse);
  Room* cramSchool = new Room();
  cramSchool->init("Eikou Cram School", "Why is it in your back yard?");
  rooms.push_back(cramSchool);
  Room* highSchool = new Room();
  highSchool->init("Naoetsu Private High School", "This one likes left twix");
  rooms.push_back(highSchool);
  Room* subwayStation = new Room();
  subwayStation->init("Subway Station", "This one likes right twix");
  rooms.push_back(subwayStation);
  Room* rooftop = new Room();
  rooftop->init("Rooftop", "It's a street. duh.");
  rooms.push_back(rooftop);
  Room* stadium = new Room();
  stadium->init("Tokyo Olympic Stadium", "It's a street. duh.");
  rooms.push_back(stadium);
  Room* bookStore = new Room();
  bookStore->init("Haga Books", "Stop using that term!");
  rooms.push_back(bookStore);
  Room* storageShed = new Room();
  storageShed->init("Storage Shed", "This map makes no sense!");
  rooms.push_back(storageShed);
  Room* convenienceStore = new Room();
  convenienceStore->init("Convenience Store", "A beautiful meadow.");
  rooms.push_back(convenienceStore);
  Room* rd1 = new Room();
  rd1->init("A road between Naoetsu Private High School and the Araragi residence", "He's feeling generous");
  rooms.push_back(rd1);
  Room* rd2 = new Room();
  rd2->init("A road between Haga Books and the subway station", "There's no pot of gold...");
  rooms.push_back(rd2);
  Room* rd3 = new Room();
  rd3->init("A road between Eikou cram school and Naoetsu Private High School", "Our map guy is drunk...");
  rooms.push_back(rd3);
  Room* rd4 = new Room();
  rd4->init("A road between Eikou cram school and the Tokyo Olympic stadium", "Our map guy is drunk...");
  rooms.push_back(rd4);
  Room* rd5 = new Room();
  rd5->init("A road between Eikou cram school and the subway station", "This one's also pretty.");
  rooms.push_back(rd5);
  Room* rd6 = new Room();
  rd6->init("A road between Haga Books and the convenience store", "Pretty");
  rooms.push_back(rd6);
  Room* rd7 = new Room();
  rd7->init("A road between the Araragi Residence and Haga Books", "EroBooks");
  rooms.push_back(rd7);

  //Exits
  //0 = NORTH
  //1 = EAST
  //2 = SOUTH
  //3 = WEST
  araragiHouse->rooms[2] = rd7;
  rd7->rooms[0] = araragiHouse;
  araragiHouse->rooms[3] = rd1;
  rd1->rooms[1] = araragiHouse;
  //str1->rooms[0] = str2;
  //str2->rooms[2] = str1;
  //str2->rooms[0] = bff;
  //bff->rooms[2] = str2;
  //bff->rooms[3] = bs;
  //bs->rooms[1] = bff;
  //str1->rooms[1] = md1;
  //md1->rooms[3] = str1;
  //md1->rooms[1] = tb;
  //tb->rooms[3] = md1;
  //tb->rooms[0] = uv;
  //uv->rooms[2] = tb;
  //tb->rooms[1] = er;
  //er->rooms[3] = tb;
  //er->rooms[0] = uv2;
  //uv2->rooms[2] = er;
  //uv2->rooms[0] = md3;
  //md3->rooms[2] = uv2;
  //uv2->rooms[3] = uv;
  //uv->rooms[1] = uv2;
  //uv->rooms[0] = md2;
  //md2->rooms[2] = uv;
  //md2->rooms[1] = md3;
  //md3->rooms[3] = md2;

  //Items
  Item* riverRock = new Item();
  riverRock->init("River_Rock", "A river rock.");
  araragiHouse->items.push_back(riverRock);
  items.push_back(riverRock);
  Item* rake = new Item();
  rake->init("Rake", "For your yard.");
  araragiHouse->items.push_back(rake);
  items.push_back(rake);
  Item* gc = new Item();
  gc->init("Gold_Coin", "The troll's charm.");
  araragiHouse->items.push_back(gc);
  items.push_back(gc);
  Item* u = new Item();
  u->init("Unicorn", "...Why?");
  araragiHouse->items.push_back(u);
  items.push_back(u);
  Item* hl = new Item();
  hl->init("Heart_Locket", "<3");
  araragiHouse->items.push_back(hl);
  items.push_back(hl);

  return araragiHouse;
}

int wordlen(char* array, int start)
{
  int index = start;
  int length = strlen(array);
  while(index < length && array[index] != ' ')
  {
    index++;
  }
  return (index - start);
}

Item* findItem(char const* name, vector<Item*>* items)
{
  vector<Item*>::iterator it = items->begin();
  while(it != (items->end()))
  {
    char* uppercaseName = new char[strlen((*it)->name)];
    strcpy(uppercaseName, (*it)->name);
    strupper(uppercaseName);
    if(strcmp(uppercaseName, name) == 0)
    {
      delete[] uppercaseName;
      return (*it);
    }
    delete[] uppercaseName;
    it++;
  }
  return NULL;
}

void deleteItem(Item* item, vector<Item*>* deleteFrom)
{
  vector<Item*>::iterator it = deleteFrom->begin();
  while(it != deleteFrom->end())
  {
    if(*it == item)
    {
      deleteFrom->erase(it);
      return;
    }
    it++;
  }
}
