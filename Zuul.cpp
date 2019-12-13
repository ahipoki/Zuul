#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

//Method prototypes
void strupper(char* str);
void deleteItem(Item* itm, vector<Item*>* delFrom);
int directionToIndex(char* dir);
int wordlen(char*, int start);
Room* createRooms(vector<Room*> &rooms, vector<Item*> &items);
Item* findItem(char const* name, vector<Item*>* items);

int main()
{//Main method
  vector<Item*> items;
  //Vector of items
  vector<Room*> cleanRooms;
  //Vector of blank rooms
  vector<Item*> cleanItems;
  //Vector of blank items
  Room* currentRoom = createRooms(cleanRooms, cleanItems);
  //Current room is setting up the rooms and items
  bool playing = true;
  //Still playing
  char input[80];
  //User input
  cout << CC_GRN << "Find all the items!" << endl;
  //Tell the user to find all the items
  cout << CC_CYN << "Commands: QUIT, GO, PICKUP, DROP, INVENTORY, TALK, HELP" << endl;
  //Tell the user the list of commands
  cout << CC_BLU << "Commands are not case sensitive!" << CC_CLR << endl;
  //Tell the user the commands are not case sensitive
  currentRoom->print();
  //Print out the current room & description
  currentRoom->printItem();
  //Print out the items in the current room
  currentRoom->printext();
  //Print out the exits in the current room
  while(playing)
  {//While the user is still playing
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
    {//If the user enters the quit command
      playing = false;
      //Stop playing
    }
    else if(strcmp(command, "GO") == 0)
    {//Else if the user enters the move command
      //Get the direction
      int arglen = wordlen(input, commandlen + 1);
      char* direction = new char[arglen + 1];
      direction[arglen] = '\0';
      strncpy(direction, input + commandlen + 1, arglen);
      strupper(direction);
      //Check if it's a legal direction

      int dirI = directionToIndex(direction);
      if(dirI == -1)
      {//If it's not a direction
	cout << "That's not a direction." << endl;
	//Tell the user that's an invalid direction      
      }
      else if(currentRoom->rooms.count(dirI) == 0)
      {//If it is a direction but there is no exit there
	cout << "That's not an exit." << endl;
	//Tell the user there's no exit     
      }
      else
      {//Anything else
	currentRoom = currentRoom->rooms[dirI];
	//Move to that room      
	currentRoom->print();
	//Print out the room's details      
	currentRoom->printItem();
	//Print out the room's items
	currentRoom->printext();
	//Print out the current room's exits      
      }

      delete[] direction;
    }
    else if(strcmp(command, "PICKUP") == 0)
    {//Else if they enter the pickup command
      //Get the item name
      int arglen = wordlen(input, commandlen + 1);
      char* item = new char[arglen + 1];
      item[arglen] = '\0';
      strncpy(item, input + commandlen + 1, arglen);
      strupper(item);
      //Check if it's an actual item

      Item* topick = findItem(item, &(currentRoom->items));
      if(topick == NULL) 
      {//If it's not an item in the room
        cout << "No such item." << endl;
	//Tell the user that's not an item      
      }
      else
      {//If it is an item in the room
	//Pick up the item      
        items.push_back(topick);
        currentRoom->deleteItem(topick);
	//Remove the item from the room
        cout << "Picked Up " << topick->name << endl;
	//Tell the user they picked up that item
      }
      delete[] item;
    }
    else if(strcmp(command, "DROP") == 0)
    {//Else if they enter the drop command
      //Take in the item they want to drop
      int arglen = wordlen(input, commandlen + 1);
      char* item = new char[arglen + 1];
      item[arglen] = '\0';
      strncpy(item, input + commandlen + 1, arglen);
      strupper(item);
      //Check if that's a legal item

      Item* topick = findItem(item, &items);
      if(topick == NULL) 
      {//If it's not an item in their inventory
        cout << "No such item." << endl;
	//Tell the user that' not an item
      }
      else
      {//If it is an item in their inventory
	//Remove the item from their inventory and add it to the room
        currentRoom->items.push_back(topick);
        deleteItem(topick, &items);
        cout << "Dropped " << topick->name << endl;
	//Tell the user they dropped the item
      }
      delete[] item;
    }
    else if(strcmp(command, "INVENTORY") == 0)
    {//Else if they enter the inventory command
      cout << CC_GRN << "Inventory: " << CC_CLR;
      vector<Item*>::iterator it = items.begin();
      while(it != items.end())
      {//Go through their inventory
        cout << ((*it)->name) << " ";
        it++;
	//Print out the items in their inventory      
      }
      cout << endl;
    }
    else if (strcmp(command, "TALK") == 0)
    {//Else if they enter the talk command
      int eventCounter = 0;
      //Tracks the current event
      if (eventCounter == 0 && currentRoom == rd1)
      {//If it's the first event
        eventCount++;
	//Move to the next event      
      }
      else if (eventCount == 1 && currentRoom == araragiHouse)
      {//If it's the second event
        eventCounter++; 
	//Move to the third event
      }
    }
    else if(strcmp(command, "HELP") == 0)
    {//Else if they enter the help command
      cout << CC_GRN << "Find all the items!" << endl;
      //Tell the user they need to find all the items
      cout << CC_CYN << "Commands: QUIT, GO, PICKUP, DROP, INVENTORY, TALK, HELP" << endl;
      //Tell the user their commands
      cout << CC_BLU << "Commands are not case sensitive!" << CC_CLR << endl;
      //Tell the user that commands are not case sensitive
    }
    else
    {//Any other input
      cout << "Unrecognized Command." << endl;
      //Tell the user that's not a command
    }

    if(items.size() == 5)
    {//If they found all the items
      cout << CC_GRN << "You found all the \"Necessary Items\"! You Win!" << CC_CLR << endl;
      //Tell the user they won
      playing = false;
      //End the game
    }

    delete[] command;
  }

  for(vector<Room*>::iterator i = cleanRooms.begin(); i != cleanRooms.end(); i++)
  {//Reset rooms
    delete (*i);
  }

  for(vector<Item*>::iterator i = cleanItems.begin(); i != cleanItems.end(); i++)
  {//Reset the items
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
{//Get the direction
  strupper(direction);
  //Make the direction input all upper case
  for(int i = 0; i < 4; i ++)
  {//Loop through checking for if the inputted direction is an actual direction
    if(strcmp(direction, DIRS[i]) == 0) return i;
    //If the inputted direction is a direction, return whatever direction that it
  }
  return -1;
  //If it's not a direction, return -1
}

Room* createRooms(vector<Room*> &rooms, vector<Item*> &items)
{//Create rooms
  //A new room
  //Add the room's name and description
  //Add the room to the vector of rooms
  Room* araragiHouse = new Room();
  araragiHouse->init("The Araragi Residence", "The house of the player character, Koyomi Araragi.");
  rooms.push_back(araragiHouse);
  Room* cramSchool = new Room();
  cramSchool->init("Eikou Cram School", "A run down, abandoned cram school");
  rooms.push_back(cramSchool);
  Room* highSchool = new Room();
  highSchool->init("Naoetsu Private High School", "The high school you, Koyomi Araragi, attend");
  rooms.push_back(highSchool);
  Room* subwayStation = new Room();
  subwayStation->init("Subway Station", "A subway station");
  rooms.push_back(subwayStation);
  Room* rooftop = new Room();
  rooftop->init("Rooftop", "The roof of Eikou cram school");
  rooms.push_back(rooftop);
  Room* stadium = new Room();
  stadium->init("Tokyo Olympic Stadium", "The olympic stadium in Tokyo");
  rooms.push_back(stadium);
  Room* bookStore = new Room();
  bookStore->init("Haga Books", "A local book store");
  rooms.push_back(bookStore);
  Room* storageShed = new Room();
  storageShed->init("Storage Shed", "A storage shed in the abandoned cram school");
  rooms.push_back(storageShed);
  Room* convenienceStore = new Room();
  convenienceStore->init("Convenience Store", "A local convenience store");
  rooms.push_back(convenienceStore);
  Room* rd1 = new Room();
  rd1->init("A road between Naoetsu Private High School and the Araragi residence", "Just a road.");
  rooms.push_back(rd1);
  Room* rd2 = new Room();
  rd2->init("A road between Haga Books and the subway station", "Just a road.");
  rooms.push_back(rd2);
  Room* rd3 = new Room();
  rd3->init("A road between Eikou cram school and Naoetsu Private High School", "Just a road.");
  rooms.push_back(rd3);
  Room* rd4 = new Room();
  rd4->init("A road between Eikou cram school and the Tokyo Olympic stadium", "Just a road.");
  rooms.push_back(rd4);
  Room* rd5 = new Room();
  rd5->init("A road between Eikou cram school and the subway station", "Just a road.");
  rooms.push_back(rd5);
  Room* rd6 = new Room();
  rd6->init("A road between Haga Books and the convenience store", "Just a road.");
  rooms.push_back(rd6);
  Room* rd7 = new Room();
  rd7->init("A road between the Araragi Residence and Haga Books", "Just a road.");
  rooms.push_back(rd7);
  Room* h1 = new Room();
  h1->init("A hallway leading to a storage shed", "Just a hallway.");
  rooms.push_back(h1);
  Room* h2 = new Room();
  h2->init("A hallway leading to the rooftop", "Just a hallway.");
  rooms.push_back(h1);

  //Exits
  //0 = NORTH
  //1 = EAST
  //2 = SOUTH
  //3 = WEST
  araragiHouse->rooms[2] = rd7;
  rd7->rooms[0] = araragiHouse;
  araragiHouse->rooms[3] = rd1;
  rd1->rooms[1] = araragiHouse;
  cramSchool->rooms[0] = rd3;
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
  //A new item
  //Add the item's name and description
  //Add the item to the vector of items
  Item* magazine = new Item();
  riverRock->init("Exciting_Magazine", "An exciting magazine.");
  bookStore->items.push_back(magazine);
  items.push_back(magazine);
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
{//Word length
  int index = start;
  int length = strlen(array);
  while(index < length && array[index] != ' ')
  {
    index++;
  }
  return (index - start);
}

Item* findItem(char const* name, vector<Item*>* items)
{//Find item
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
{//Delete item
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
