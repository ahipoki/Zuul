#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <map>
#include <stdlib.h>
#include "Item.h"
#include "Room.h"

//There are quite a few commands but all are based off of command class
//A command just needs a description, type, and something to return when the user types the command incorrectly
#include "Command.h"
#include "Head.h"
#include "PickUp.h"
#include "Drop.h"
//This command simply iterates through the players inventory of item vectors and displays their names.
#include "Inventory.h"
//This command is a major class that stores in an event array, which keeps tracks of which events have happened in what rooms. It also contains much of the standard talk reply of rooms.
#include "Talk.h"
//Prints list of commands
#include "Help.h"
//Prints a map that dynamically updates
#include "Story.h"
//Exits the program
#include "Quit.h"

#define HELP_TYPE 2
#define HEAD_TYPE 3
#define PICKUP_TYPE 4
#define DROP_TYPE 5
#define INVENTORY_TYPE 6
#define TALK_TYPE 7
#define STORY_TYPE 8
#define QUIT_TYPE 9

using namespace std;

//Function Prototypes
void buildRoom (map<char*,Room*>*, char*, char*);
void processInput(char*, char*);
void processCommand(char* , char* , vector<Command*>*, map<char*, Room*>*, Room**, vector<Item*>*, vector<Command*>*, vector<char*>*);
void printExitString(map<char*, char*>*);
void printItemString(vector<Item*>*);
void printRoomString(Room*);

int main()
{
  char saveInput[80];
  //List of Visited Rooms (for Map)
  vector<char*> encRooms;
  vector<char*>* encRoomsptr = &encRooms;

  //List of Rooms
  map<char*, Room*>* rm = new map<char*, Room*>;
  
  //Adding all the Rooms! Desc can change with events
  buildRoom(rm, (char*)"The Araragi Residence", (char*)"This is the house of our main character, Koyomi Araragi.");
  //Araragi's house
  buildRoom(rm, (char*)"Eikou Cram School", (char*)"Cram School.");
  //Cram School
  buildRoom(rm, (char*)"Naoetsu Private High School", (char*)"High School");
  //High School
  buildRoom(rm, (char*)"Subway Station", (char*)"Subway Station");
  //Subway station
  buildRoom(rm, (char*)"Rooftop", (char*)"Rooftop");
  //Rooftop
  buildRoom(rm, (char*)"Tokyo Olympic Stadium", (char*)"Stadium");
  //Stadium
  buildRoom(rm, (char*)"Haga Books", (char*)"Book Store");
  //Book store
  buildRoom(rm, (char*)"Storage Shed", (char*)"Storage shed");
  //Storage shed
  buildRoom(rm, (char*)"Convenience Store", (char*)"Convenience");
  //Convenience store
  buildRoom(rm, (char*)"High School -> Araragi House", (char*)"High School to Araragi House");
  //High school to book store
  buildRoom(rm, (char*)"Book Store -> Subway Station", (char*)"Book store to subway station");
  //Book store to subway
  buildRoom(rm, (char*)"Cram School -> High School", (char*)"Cram school to high school");
  //Cram school to high school
  buildRoom(rm, (char*)"Cram School -> Stadium", (char*)"Cram school to stadium");
  //Cram school to stadium
  buildRoom(rm, (char*)"Cram School -> Subway Station", (char*)"Cram school to subway station");
  //Cram school to subway
  buildRoom(rm, (char*)"Book Store -> Convenience Store", (char*)"Book store to convenience store");
  //Book store to convenience store
  buildRoom(rm, (char*)"Cram School -> Storage Shed", (char*)"Cram school to storage shed");
  //Cram school to storage shed
  buildRoom(rm, (char*)"Storage Shed -> Rooftop", (char*)"Storage shed to roof");
  //Storage shed to rooftop
  buildRoom(rm, (char*)"Araragi House -> Book Store", (char*)"Araragi's house to book store");
  //Adding all the Exits that the game starts out with (more added later in events)

  //((*rm)[(char*)"The Araragi Residence"])->setExit((char*)"NORTH", (char*)"Eikou Cram School");
  ((*rm)[(char*)"The Araragi Residence"])->setExit((char*)"SOUTH", (char*)"Araragi House -> Book Store");
  //((*rm)[(char*)"The Araragi Residence"])->setExit((char*)"EAST", (char*)"Namishiro Park");
  ((*rm)[(char*)"The Araragi Residence"])->setExit((char*)"WEST", (char*)"High School -> Araragi House");

  //((*rm)[(char*)"Eikou Cram School"])->setExit((char*)"NORTH", (char*)"Cram School -> High School");
  //((*rm)[(char*)"Eikou Cram School"])->setExit((char*)"SOUTH", (char*)"Cram School -> Storage Shed Hallway");
  //((*rm)[(char*)"Eikou Cram School"])->setExit((char*)"EAST", (char*)"Cram School -> Stadium");
  //((*rm)[(char*)"Eikou Cram School"])->setExit((char*)"WEST", (char*)"Cram School -> Subway Station");

  //((*rm)[(char*)"Subway Station"])->setExit((char*)"EAST", (char*)"Cram School -> Subway Station");
  ((*rm)[(char*)"Subway Station"])->setExit((char*)"WEST", (char*)"Book Store -> Subway Station");

  //((*rm)[(char*)"Naoetsu Private High School"])->setExit((char*)"SOUTH", (char*)"Cram School -> High School");
  ((*rm)[(char*)"Naoetsu Private High School"])->setExit((char*)"EAST", (char*)"High School -> Araragi House");
  
  ((*rm)[(char*)"Rooftop"])->setExit((char*)"WEST", (char*)"Storage Shed -> Rooftop");

  ((*rm)[(char*)"Tokyo Olympic Stadium"])->setExit((char*)"WEST", (char*)"Cram School -> Stadium");

  ((*rm)[(char*)"Haga Books"])->setExit((char*)"NORTH", (char*)"Araragi House -> Book Store");
  //((*rm)[(char*)"Haga Books"])->setExit((char*)"SOUTH", (char*)"Book Store -> Convenience Store");
  ((*rm)[(char*)"Haga Books"])->setExit((char*)"EAST", (char*)"Book Store -> Subway Station");

  //((*rm)[(char*)"Storage Shed"])->setExit((char*)"NORTH", (char*)"Cram School -> Storage Shed");
  ((*rm)[(char*)"Storage Shed"])->setExit((char*)"EAST", (char*)"Storage Shed -> Rooftop");

  //((*rm)[(char*)"Convenience Store"])->setExit((char*)"NORTH", (char*)"Book Store -> Convenience Store");

  ((*rm)[(char*)"High School -> Araragi House"])->setExit((char*)"EAST", (char*)"The Araragi Residence");
  ((*rm)[(char*)"High School -> Araragi House"])->setExit((char*)"WEST", (char*)"Naoetsu Private High School");

  ((*rm)[(char*)"Book Store -> Subway Station"])->setExit((char*)"EAST", (char*)"Subway Station");
  ((*rm)[(char*)"Book Store -> Subway Station"])->setExit((char*)"WEST", (char*)"Haga Books");

  ((*rm)[(char*)"Cram School -> High School"])->setExit((char*)"NORTH", (char*)"Naoetsu Private High School");
  ((*rm)[(char*)"Cram School -> High School"])->setExit((char*)"SOUTH", (char*)"Eikou Cram School");
	
  ((*rm)[(char*)"Cram School -> Stadium"])->setExit((char*)"EAST", (char*)"Tokyo Olympic Stadium");
  ((*rm)[(char*)"Cram School -> Stadium"])->setExit((char*)"WEST", (char*)"Eikou Cram School");
  
  ((*rm)[(char*)"Cram School -> Subway"])->setExit((char*)"EAST", (char*)"Eikou Cram School");
  ((*rm)[(char*)"Cram School -> Subway"])->setExit((char*)"WEST", (char*)"Subway Station");
	
  ((*rm)[(char*)"Book Store -> Convenience Store"])->setExit((char*)"NORTH", (char*)"Haga Books");
  ((*rm)[(char*)"Book Store -> Convenience Store"])->setExit((char*)"SOUTH", (char*)"Convenience Store");
	
  ((*rm)[(char*)"Cram School -> Storage Room"])->setExit((char*)"NORTH", (char*)"Eikou Cram School");
  ((*rm)[(char*)"Cram School -> Storage Room"])->setExit((char*)"SOUTH", (char*)"Storage Shed");
	
  ((*rm)[(char*)"Storage Shed -> Rooftop"])->setExit((char*)"EAST", (char*)"Rooftop");
  ((*rm)[(char*)"Storage Shed -> Rooftop"])->setExit((char*)"WEST", (char*)"Storage Shed");
	
  ((*rm)[(char*)"Araragi House -> Book Store"])->setExit((char*)"NORTH", (char*)"The Araragi Residence");
  ((*rm)[(char*)"Araragi House -> Book Store"])->setExit((char*)"SOUTH", (char*)"Haga Books");
	
  //Adding all the **starting** items (MANY more items are added as events play out)!
  ((*rm)[(char*)"Haga Books"])->addItem((char*)"Araragi's Exciting Magazine");
  
  //Inventory
  vector<Item*> bag;
  vector<Item*>* bagptr = &bag;

  //List of Commands
  vector<Command*> commands;
  vector<Command*>* commandsptr = &commands;
  
  //Current Room
  Room* currentRoom;
  Room** currentRoomptr = &currentRoom;
  Room* lastRoom = ((*rm)[(char*)"Rooftop"]);
  
  //Command string and Keyword string
  char commandsarr[99];
  char* commandstr = commandsarr;
  char keywordsarr[99];
  char* keywordstr = keywordsarr;
  
  //Initiating **starting** commands (more added later in events)
  commandsptr->push_back(new Help((char*)"HELP"));
  commandsptr->push_back(new Head((char*)"HEAD"));
  commandsptr->push_back(new PickUp((char*)"GRAB"));
  commandsptr->push_back(new Drop((char*)"DROP"));
  commandsptr->push_back(new Inventory((char*)"INVENTORY"));
  int* e = new int[15];
  for(int a = 0; a < 15; ++a)
  {
    e[a] = 0;
  }
  commandsptr->push_back(new Talk((char*)"TALK", e));
  commandsptr->push_back(new Quit((char*)"QUIT"));

  //Setting running and current room to prepare for game start
  bool running = true;
  
  currentRoom = ((*rm)[(char*)"Naoetsu Private High School"]);

  cout << "Welcome to my adaptation of Kizumonogatari as a Zuul game." << endl; 
  
  printRoomString(currentRoom);
  
  //Print out long description of room.
  //Print out exits
  //Print out items
  //Then process commands
  while(running)
  {
    //Basically add room to list of visited rooms if it isn't in there already
    vector<char*>::iterator i;
    bool found = false;
    for(i = encRooms.begin(); i != encRooms.end(); ++i)
    {
      if(strcmp((*i), currentRoom->getTitle()) == 0)
      {
	found = true;
      }
    }
    if(found == false)
    {
      encRooms.push_back(currentRoom->getTitle());
    }
    if(lastRoom != currentRoom)
    {
      printRoomString(currentRoom);
      lastRoom = currentRoom;
    }
    //Take in userin and try to translate that into a command
    processInput(commandstr, keywordstr);
    processCommand(commandstr, keywordstr, commandsptr, rm, currentRoomptr, bagptr, commandsptr, encRoomsptr);

    //We take the ev array that is stored in Talk to do all manner of events
    //The basis of activating an event is finding the current room, checking the event array connected to that room, then making another event based off of those qualities
    //The .png map contains all of the event method intents
    int* ev = ((Talk*)(commands.at(5)))->getEv();
    if(currentRoom == (*rm)[(char*)"Naoetsu Private High School"])
    {
      if(ev[0] == true)
      {
	((*rm)[(char*)"Naoetsu Private High School"])->setDescription((char*)"This is Naoetsu Private High School, the school that you, Koyomi Araragi, attend as a second year.");
	ev[0] = 2;
	printRoomString(currentRoom);
      }
    }
    else if(currentRoom == (*rm)[(char*)"High School -> Home"])
    {
      if(ev[1] == true)
      {
	commandsptr->push_back(new Story((char*)"STORY"));
	
	ev[1] = 2;
	printRoomString(currentRoom);
      }
    }
    else if(currentRoom == (*rm)[(char*)"Haga Books"])
    {
      if(ev[2] == true)
      {
	ev[2] = 2;
	printRoomString(currentRoom);
      }
    }
    else if(currentRoom == (*rm)[(char*)"Subway Station"])
    {
      if(ev[3] == true)
      {
	cout << "Do you want to save her?
	cin.getline(saveInput, 80);
	for (int i = 0; i < strlen(saveInput); i++)
	{
	  saveInput[i] = tolower(saveInput);
	}
	if (strcmp(saveInput, "yes")
	{
	  //Save her    
	}
	else if (strcmp(saveInput, "no")
	{
	  //Force the player to save her	 
	}
	ev[3] = 2;
	printRoomString(currentRoom);
      }
    }
    else if(currentRoom == (*rm)[(char*)"North Shirahebi Shrine"])
    {
      if(ev[4] == true)
      {
      ((*rm)[(char*)"North Shirahebi Shrine"])->addItem((char*)"Peter_Pan's_Ram");
      }
    }
    else if(currentRoom == (*rm)[(char*)"The Sengoku Residence"])
    {
      if(ev[5] == true)
      {
	vector<Item*>::iterator bagIt;
	bool finYes = false;
	bool pinYes = false;
	for(bagIt = bag.begin(); bagIt != bag.end(); ++bagIt)
	{
	  if(strcmp((*bagIt)->getName(), "Peter_Jin's_Fin") == 0)
	  {
	    finYes = true;
	  }
	  else if(strcmp((*bagIt)->getName(), "Peter_Jin's_Safety_Pin") == 0)
	  {
	    pinYes = true;
	  }
	}
	char buffer[999] = "";
	if(finYes && pinYes)
	{
	  cout << "Hey, that's my fin! Gimme!" << endl;
	  cin.get(buffer, 1);
	  cin.clear();
	  cin.ignore(999, '\n');
	  cout << "The pufferfish starts to expand at a rapid pace!" << endl;
	  cin.get(buffer, 1);
	  cin.clear();
	  cin.ignore(999, '\n');
	  cout << "Luckily, Peter Jin's Safety Pin was sticking out of your bag at just the right angle, and the pufferfish gets caught at the point and rapidly deflates." << endl;
	  cin.get(buffer, 1);
	  cin.clear();
	  cin.ignore(999, '\n');

	  cout << "The only trace of the once grandiose creature is a small but plump mandarin..." << endl;

	  ((*rm)[(char*)"Peter Puffin"])->setDescription((char*)"RIP Peter Puffin (2019-2019)");

	  
          ((*rm)[(char*)"Peter Puffin"])->addItem((char*)"Peter_Jin's_Mandarin");

	  printRoomString(currentRoom);
	  ev[5] = 2;
	}
	else if(finYes && pinYes == false)
	{
	  cout << "Hey, that's my fin! Gimme!" << endl;
	  cin.get(buffer, 1);
	  cin.clear();
	  cin.ignore(999, '\n');
	  cout << "The pufferfish starts to expand at a rapid pace!" << endl;
	  cin.get(buffer, 1);
	  cin.clear();
	  cin.ignore(999, '\n');
	  cout << "(You barely make it out of the room before you're impaled to the wall by poisonous spikes)" << endl;
	  cin.get(buffer, 1);
	  cin.clear();
	  cin.ignore(999, '\n');
	  
	  currentRoom = ((*rm)[(char*)"Peter Pan's Jam"]);
	}
      }
    }
    else if(currentRoom == (*rm)[(char*)"The Tsunade Residence"])
    {
      if(ev[6] == true)
      {
        ((*rm)[(char*)"The Tsunade Residence"])->addItem((char*)"Peter_Pan's_Fan");
	ev[6] = 2;
	printRoomString(currentRoom);
      }
    }
    else if(currentRoom == (*rm)[(char*)"Tamikura Apartments"])
    {
      if(ev[7] == true && strcmp(commandstr, "TALK") == 0){
	vector<Item*>::iterator bagIt;
	bool yamYes = false;
	bool spamYes = false;
	for(bagIt = bag.begin(); bagIt != bag.end(); ++bagIt){
	  if(strcmp((*bagIt)->getName(), "Peter_Pan's_Yam") == 0){
	    yamYes = true;
	  }else if(strcmp((*bagIt)->getName(), "Peter_Pan's_SPAM") == 0){
	    spamYes = true;
	  }
	}
	if(yamYes && spamYes){
	  cout << "Whoa, you have both! Could I take these to the kitchen? I'll pay you back a portion of this in fast food!" << endl;
	  cout << "Give Yam and Spam? (y/n)" << endl;

	  char buffer[3] = "";
	  
      	  cin.get(buffer, 3);
	  cin.clear();
	  cin.ignore(999, '\n');

	  buffer[0] = toupper(buffer[0]);
	  
	  if(buffer[0] == 'Y' && strlen(buffer) == 1){
	    for(bagIt = bag.begin(); bagIt != bag.end(); ){
	      if(strcmp((*bagIt)->getName(), "Peter_Pan's_Yam") == 0){
	        delete (*bagIt);
		bagIt = bag.erase(bagIt);
	      }else if(strcmp((*bagIt)->getName(), "Peter_Pan's_SPAM") == 0){
	        delete (*bagIt);
		bagIt = bag.erase(bagIt);
	      }else{
		++bagIt;
	      }
	    }
	    ((*rm)[(char*)"Jin & Out"])->addItem((char*)"Jin&Out_Burger");
	    ((*rm)[(char*)"Jin & Out"])->addItem((char*)"Jin&Out_Fries");

	    ((*rm)[(char*)"Jin & Out"])->setDescription((char*)"A building the size of a skyscraper towers over the middle of a densely populated city. Employees can be seen hurrying from floor to floor through the pristine glass windows. Then you look up, and no longer see a column of smoke erupting from the building.");
	    
	    ev[7] = 2;
	    printRoomString(currentRoom);
	  }else{
	    cout << "Oh that's too bad then...(The smoke continues to pour from the tower)" << endl;
	  }
	}
      }
    }else if(currentRoom == (*rm)[(char*)"The Hachikuji Residence"]){
      if(ev[8] == true){
	((*rm)[(char*)"Peter Jin's Inn"])->addItem((char*)"Peter_Jin's_Fin");
	ev[8] = 2;
	printRoomString(currentRoom);
      }else if(ev[8] == 2){
	char buffer [999] = "";
	vector<Item*>::iterator bagIt;
	bool mandYes = false;
	for(bagIt = bag.begin(); bagIt != bag.end(); ++bagIt){
	  if(strcmp((*bagIt)->getName(), "Peter_Jin's_Mandarin") == 0){
	    mandYes = true;
	    delete (*bagIt);
	    bagIt = bag.erase(bagIt);
	    break;
	  }
	}

	if(mandYes){
	  cout << "(Mr.sbarK is drawn out into the dining area by a citrus odor)" << endl;
	  cin.get(buffer, 1);
	  cin.clear();
	  cin.ignore(999,'\n');
	  cout << "Ooh, yummy orange! Gimme~" << endl;
	  cin.get(buffer, 1);
	  cin.clear();
	  cin.ignore(999,'\n');
	  cout << "(Mr.sbarK helps himself to Peter Jin's Mandarin)" << endl;
	  cin.get(buffer, 1);
	  cin.clear();
	  cin.ignore(999,'\n');
	  cout << "(Suddenly, Mr.s'sbarK leg grows back!)" << endl;
	  cin.get(buffer, 1);
	  cin.clear();
	  cin.ignore(999,'\n');
	  cout << "Ok wow, you beat the puffer, I owe great debt, you're so cool, etc. etc." << endl;
	  cin.get(buffer, 1);
	  cin.clear();
	  cin.ignore(999,'\n');
          cout << "Mr.sbarK has joined the party!" << endl;
	  ev[8] = 3;
	}
      }
    }else if(currentRoom == (*rm)[(char*)"The Hanekawa Residenece"]){
      if(ev[9] == true && strcmp(commandstr, "TALK") == 0){
	if(ev[4] == 2 && ev[14] == 2){
	  char scrollText[999] = "";
	  cout << "Huehuehuehuehuehu--" << endl;
	  cin.get(scrollText,1);
	  cin.clear();
	  cin.ignore(999, '\n');
	  cout << "PinkFluffyUnicornClam's evil laughter is cut short as two moshpits collide together on top of the clam." << endl;
	  cin.get(scrollText,1);
	  cin.clear();
	  cin.ignore(999, '\n');
	  cout << "As the unicorn clam shifts an inch, a resounding crack resonated throughout the dam, and the water began pouring forth." << endl;
	  cin.get(scrollText,1);
	  cin.clear();
	  cin.ignore(999, '\n');
	  cout << "Clam and human were flushed down the river...(safely), and a flickering could be heard in the distance..." << endl;
	  //Berlin
	  ev[4] = 3;
	  ev[14] = 3;
	  //Dam
	  ev[9] = 2;
	  //LITTI CITY
	  ev[13] = 2;

	  ((*rm)[(char*)"Peter Pan's Dam"])->setDescription((char*)"Birds chirp and fish splash as the water flows through the dam, as smooth as silk!");

	((*rm)[(char*)"Peter Jin's LITTI IN MY CITY"])->setDescription((char*)"Peter Jin's LITTI IN MY CITY looks beautiful when lit up at night, looming palaces overlooking serene lakes, and elegant lampposts blazing on every street...");
	
	  printRoomString(currentRoom);
        }
      }
    }else if(currentRoom == (*rm)[(char*)"Haruya Book Store"]){
      if(ev[10] == true){
	ev[10] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Nanahyakuichi Public Middle School"]){
      if(ev[11] == true){
	char scrollText [999] = "";
	vector<Item*>::iterator bagIt;
	bool ramYes = false;
	bool lambYes = false;
	bool fanYes = false;
	bool panYes = false;
	for(bagIt = bag.begin(); bagIt != bag.end(); ++bagIt){
	  if(strcmp((*bagIt)->getName(), "Peter_Pan's_Ram") == 0){
	    ramYes = true;
	  }else if(strcmp((*bagIt)->getName(), "Peter_Pan's_Lamb") == 0){
	    lambYes = true;
	  }else if(strcmp((*bagIt)->getName(), "Peter_Pan's_Fan") == 0){
	    fanYes = true;
	  }else if(strcmp((*bagIt)->getName(), "Peter_Pan's_Saucepan") == 0){
	    panYes = true;
	  }
	}

        if(ramYes && lambYes && fanYes && panYes && ev[8]==3){
	  cout << "You have all the requirements to begin cooking!" << endl;
	  cout << "Start? (y/n)" << endl;

	  char buffer[3] = "";
	  
      	  cin.get(buffer, 3);
	  cin.clear();
	  cin.ignore(999, '\n');

	  buffer[0] = toupper(buffer[0]);
	  
	  if(buffer[0] == 'Y' && strlen(buffer) == 1){
	    for(bagIt = bag.begin(); bagIt != bag.end(); ){
	      if(strcmp((*bagIt)->getName(), "Peter_Pan's_Ram") == 0){
	        delete (*bagIt);
		bagIt = bag.erase(bagIt);
	      }else if(strcmp((*bagIt)->getName(), "Peter_Pan's_Lamb") == 0){
	        delete (*bagIt);
		bagIt = bag.erase(bagIt);
	      }else if(strcmp((*bagIt)->getName(), "Peter_Jin's_Fan") == 0){
		delete (*bagIt);
		bagIt = bag.erase(bagIt);
	      }else if(strcmp((*bagIt)->getName(), "Peter_Jin's_Saucepan") == 0){
		delete (*bagIt);
		bagIt = bag.erase(bagIt);
	      }else{
		++bagIt;
	      }
	    }
	  ev[11] = 2;
	  cout << "Mr.sbarK helps you put the saucepan on the stove..." << endl;
	  cin.get(scrollText, 1);
	  cin.clear();
	  cin.ignore(999, '\n');
	  cout << "You snap the fan open and start to fan the fire... wait, is that even doing anything?" << endl;
	  cin.get(scrollText, 1);
	  cin.clear();
	  cin.ignore(999, '\n');
	  cout << "You take the WOOL from the lamb and ram, to use as all-natural protein, as to not offend PETA" << endl;
	  cin.get(scrollText, 1);
	  cin.clear();
	  cin.ignore(999, '\n');
	  cout << "Then you stir... and WA-LA! Peter Pan's Universal Flan appears in front of you!" << endl;
	  cin.get(scrollText, 1);
	  cin.clear();
	  cin.ignore(999, '\n');
	  cout << "It turns out that Mr.sbarK is actually Mr.Krabs from spongebob! Wow! He adds this recipe to his prabby catties, with a patent on it, and you live happily ever after, rich for the rest of your life! (Sorry, short on time, GGs tho! Thx for playing!" << endl;
	  exit(0);
	  
	  printRoomString(currentRoom);
	  }  
	  }
      }
    }else if(currentRoom == (*rm)[(char*)"The Oikura Residence"]){
      if(ev[12] == true){
	ev[12] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Mister Donut"]){
      if(ev[13] == 2){
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"The Kanbaru Residence"]){
      if(ev[14] == true && strcmp(commandstr, "TALK") == 0){
	vector<Item*>::iterator bagIt;
	bool friesYes = false;
	bool burgerYes = false;
	for(bagIt = bag.begin(); bagIt != bag.end(); ++bagIt){
	  if(strcmp((*bagIt)->getName(), "Jin&Out_Burger") == 0){
	    burgerYes = true;
	    break;
	  }else if(strcmp((*bagIt)->getName(), "Jin&Out_Fries") == 0){
	    friesYes = true;
	    break;
	  }
	}
	if(burgerYes || friesYes){
	  cout << "Looks like you could prevent the conflict with some food!" << endl;
	  if(burgerYes){
	    cout << "Offer Jin & Out Burger? (y/n)" << endl;
	  }else{
	    cout << "Offer Jin & Out Fries? (y/n)" << endl;
	  }

	  char buffer[3] = "";
	  
      	  cin.get(buffer, 3);
	  cin.clear();
	  cin.ignore(999, '\n');

	  buffer[0] = toupper(buffer[0]);
	  
	  if(buffer[0] == 'Y' && strlen(buffer) == 1){
	    for(bagIt = bag.begin(); bagIt != bag.end(); ){
	      if(burgerYes){
		if(strcmp((*bagIt)->getName(), "Jin&Out_Burger") == 0){
	          delete (*bagIt);
		  bagIt = bag.erase(bagIt);
		}else{
		  ++bagIt;
		}
	      }else{
		if(strcmp((*bagIt)->getName(), "Jin&Out_Fries") == 0){
	          delete (*bagIt);
		  bagIt = bag.erase(bagIt);
		}else{
		  ++bagIt;
		}
	      }
	    }
	    ((*rm)[(char*)"Peter Jin's South Berlin"])->addItem((char*)"Peter_Pan's_Lamb");

	    if(burgerYes){
	      cout << "The moment you pull out the burger, the ram is instantly forgotten about, and the mob nearly rolls you over to get their hands on the burger. Satisfied, the mosh pit then slides north down the hill like the avalanche from a storm. All that's left is a lamb. Wait, it wasn't a ram?" << endl;
	    }else{
	      cout << "The moment you pull out the fries, the ram is instantly forgotten about, and the mob nearly rolls you over to get their hands on the burger. Satisfied, the mosh pit then slides north down the hill like the avalanche from a storm. All that's left is a lamb. Wait, it wasn't a ram?" << endl;
	    }
	    
	    ((*rm)[(char*)"Peter Jin's South Berlin"])->setDescription((char*)"Seaweed rolls over houses and dry cracked wells... But the streets are far from deserted. Just recently, a gathering of around a hundred people stormed south, leaving footprints randomly plastered about the ground...");
	    ev[14] = 2;
	    printRoomString(currentRoom);
	  }else{
	    cout << "You decide to bide your time and wait for the oppurtune moment. Wait, did the cook just bring in salt and pepper shakers? And some ketchup?" << endl;
	  }
	}
      }
    }
  }
}

//Build room takes in title and desc, makes new rooom, then adds that to the map
void buildRoom (map<char*,Room*>* rm, char* rmTitle, char* rmDescription) {
  (*rm)[rmTitle] = new Room(rmTitle, rmDescription, new vector<Item*>, new map<char*,char*>);
}

//process userin, decide if it is one or two words, then return one or two words
void processInput(char* commandstr, char* keywordstr){
  char in[99];
  while(true){
    int spaces = 0;
    
    cin.get(in, 99);
    cin.clear();
    cin.ignore(999, '\n');
    
    if(strlen(in) != 0){
      for(int a = 0; a < strlen(in); ++a)
      {
      	in[a] = toupper(in[a]);
        if(in[a] == ' ')
	{
	  ++spaces;
        }
      }
      //If there are no spaces just return
      if(spaces == 0){
        strcpy(commandstr,in);
	strcpy(keywordstr,"");
	break;
	//If there is 1 space make sure that there are characters to the left and right of the space
      }else if(spaces == 1){
	int index;
	for(int a = 0; a < strlen(in); ++a){
	  if(in[a] == ' '){
	    index = a;
	    break;
	  }
	}
        if(index != 0 && index != strlen(in)-1){
	  //We add 1 more to the array length to hold the null terminating character
	  char first[index+1] = "";
	  char second[(strlen(in)-index)] = "";
	  
	  for(int a = 0; a < index; ++a){
	    first[a] = in[a];
	  }
	  for(int a = index + 1; a < strlen(in); ++a){
	    second[a-index-1] = in[a];
	  }
	  strcpy(commandstr,first);
	  strcpy(keywordstr,second);
	  break;
	}
      }
    }
    cout << "Invalid command. Make sure to type \"HELP\" if you need help!" << endl;
  }
}

//Process a command by checking if the commands list has this command, then passes that into the corresponding type
void processCommand(char* commandstr, char* keywordstr, vector<Command*>* commandsptr, map<char*, Room*>* rm, Room** currentRoomptr, vector<Item*>* bagptr, vector<Command*>* commands, vector<char*>* encRoomsptr){
  vector<Command*>::iterator commandsIt;
    bool found = false;
    for(commandsIt = commandsptr->begin(); commandsIt != commandsptr->end(); ++commandsIt){
      if(strcmp((*commandsIt)->getDescription(), commandstr) == 0){
	found = true;
	break;
      }
    }
    if(found == false){
      cout << "Sorry, but you entered an invalid command. Make sure to type \"HELP\" if you need help!" << endl;
    }else{
      int type = (*commandsIt)->getType();
      switch (type){
      case HEAD_TYPE:
	if(strcmp(keywordstr,"") != 0){
	  ((Head*)(*commandsIt))->move(keywordstr, rm, currentRoomptr);
	}else{
	  cout << ((Head*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      case PICKUP_TYPE:
	if(strcmp(keywordstr,"") != 0){
	  ((PickUp*)(*commandsIt))->take(currentRoomptr, bagptr, keywordstr);
	}else{
	  cout << ((PickUp*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      case DROP_TYPE:
	if(strcmp(keywordstr,"") != 0){
	  ((Drop*)(*commandsIt))->toss(currentRoomptr, bagptr, keywordstr);
	}else{
	  cout << ((Drop*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      case INVENTORY_TYPE:
	if(strcmp(keywordstr,"") == 0){
	  ((Inventory*)(*commandsIt))->show(bagptr);
	}else{
	  cout << "You rummaged through your inventory to find \"" << keywordstr << "\", but then you realized that \"inventory\" is a one word command..." << endl;
	}
	break;
      case TALK_TYPE:
        if(strcmp(keywordstr,"") == 0){
	  ((Talk*)(*commandsIt))->act(rm, currentRoomptr, bagptr);
	}
	else
	{
	  cout << ((Talk*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      case HELP_TYPE:
        if(strcmp(keywordstr,"") == 0)
	{
	  ((Help*)(*commandsIt))->printHelp(commands);
	}
	else
	{
	  cout << ((Help*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      case STORY_TYPE:
        if(strcmp(keywordstr,"") == 0)
	{
	  ((Story*)(*commandsIt))->printMap(currentRoomptr, rm, encRoomsptr);
	}
	else
	{
	  cout << ((Story*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      case QUIT_TYPE:
        if(strcmp(keywordstr,"") == 0)
	{
	  ((Quit*)(*commandsIt))->getMeOut();
	}
	else
	{
	  cout << ((Quit*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      }
      
   }
}

//Iterates through the exits of a room and prints
void printExitString(map<char*, char*>* exits)
{
  map<char*, char*>::iterator it;
  for(it = exits->begin(); it != exits->end(); ++it)
  {//Uses an iterator and goes through the exits
    cout << it->first << " ";
    //Prints out the exits of the room
  }
  cout << endl;
}

//Iterates through the items of a room and prints
void printItemString(vector<Item*>* items)
{
  vector<Item*>::iterator iIt;
  for(iIt = items->begin(); iIt != items->end(); ++iIt)
  {//Uses an iterator and goes through the items in the room
    cout << (*iIt)->getName() << " ";
    //Prints out the items
  }
  cout << endl;
}

//Gives the user the room's information
void printRoomString(Room* currentRoom)
{
  cout << "You are at " << currentRoom->getTitle() << "." << endl;
  //Tell the user the room they're in
  cout << currentRoom->getDescription() << endl;
  //Tell the user the room's description
  cout << "Exits: ";
  printExitString(currentRoom->getExits());
  //Tell the user the room's current exits
  cout << "Items: ";
  printItemString(currentRoom->getItems());
  //Tell the user the room's current items
}
