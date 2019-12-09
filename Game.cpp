#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <map>
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

int main(){
  
  //List of Visited Rooms (for Map)
  vector<char*> encRooms;
  vector<char*>* encRoomsptr = &encRooms;

  //List of Rooms
  map<char*, Room*>* rm = new map<char*, Room*>;
  
  //Adding all the Rooms! Desc can change with events
  buildRoom(rm, (char*)"Peter Pan's Jam", (char*)"Peter Pan is jamming with some songs + dance moves.");
  buildRoom(rm, (char*)"Peter Pan's Fam", (char*)"Peter Pan's Nan is there to cheer you on. It fills you with DETERMINATION.");
  buildRoom(rm, (char*)"Peter Pan's Clan", (char*)"Peter Pan's former clan is in tears after they heard about Peter Pan's fast departure.");
  buildRoom(rm, (char*)"Peter Pan's Madame Ma'am", (char*)"In front of you is a hearty little farm, with a tidy house and a large barn. On the front porch a woman sweeps the floor.");
  buildRoom(rm, (char*)"Peter Jin's North Berlin", (char*)"Tumbleweeds roll over houses and dush-filled wells... But the streets are far from deserted. You come across a gathering of around a hundred people clamoring over something...");
  buildRoom(rm, (char*)"Peter Puffin", (char*)"As you walk in a small pufferfish the size of a pea inflates into the size of two elephants. It stares you down with somewhat kind eyes...");
  buildRoom(rm, (char*)"Jin & Out Fanbase", (char*)"Out in the distance a big broccoli building with the shape of a fan stands firm on a hill, with so many thousands of people entering in and out of the building that you wonder if your eyes are playing tricks on you. But that's weird. Just a few days ago, wasn't there nothing? You spot a guy cooling himself off with a fan in the corner...");
  buildRoom(rm, (char*)"Jin & Out", (char*)"A building the size of a skyscraper towers over the middle of a densely populated city. Employees can be seen hurrying from floor to floor through the pristine glass windows. Then you look up, and see a column of black smoke rupturing from the top of the restraunt. A worker in red and yellow runs towards you.");
  buildRoom(rm, (char*)"Peter Jin's Inn", (char*)"In front of you stands a cozy chest-shaped inn frying buns and flipping prabby catties.");
  buildRoom(rm, (char*)"Peter Pan's Dam", (char*)"A huge dam divides the two rival kingdoms. But that's weird... There's no water flowing down! Could it be because of the clam flexing its tongue in the middle?");
  buildRoom(rm, (char*)"Peter Pan's Evil Twin", (char*)"The evil peanut butter swirls on top of Peter Jin's bread top hat. it's time.");
  buildRoom(rm, (char*)"Peter Pan's Milk Can", (char*)"But the legends... could it be? You could'nt possibly be at the illusive milk can house of Peter Pan!");
  buildRoom(rm, (char*)"Peter Jin's Tin Bin", (char*)"It's literally the basement of Jin & Out... molding burger wrappers and crumpled paper cups pile miles high into every direction... It's like Scrooge mcDuck's vault, except full of junk");
  buildRoom(rm, (char*)"Peter Jin's LITTI IN MY CITY", (char*)"An entire city seems to almost completely be out of power... except for a flickering lampost illuminating an old man sitting on a blue metal bench, reading a newspaper.");
  buildRoom(rm, (char*)"Peter Jin's South Berlin", (char*)"Seaweed rolls over houses and dry cracked wells... But the streets are far from deserted. You come across a gathering of around a hundred people clamoring over something...");
  //Adding all the Exits that the game starts out with (more added later in events)

  ((*rm)[(char*)"Peter Pan's Fam"])->setExit((char*)"WEST", (char*)"Peter Pan's Jam");
  ((*rm)[(char*)"Peter Pan's Fam"])->setExit((char*)"SOUTH", (char*)"Jin & Out Fanbase");
  ((*rm)[(char*)"Peter Pan's Fam"])->setExit((char*)"EAST", (char*)"Peter Pan's Clan");

  ((*rm)[(char*)"Peter Pan's Clan"])->setExit((char*)"EAST", (char*)"Peter Pan's Madame Ma'am");
  ((*rm)[(char*)"Peter Pan's Clan"])->setExit((char*)"SOUTH", (char*)"Jin & Out");
  ((*rm)[(char*)"Peter Pan's Clan"])->setExit((char*)"WEST", (char*)"Peter Pan's Fam");

  ((*rm)[(char*)"Peter Pan's Madame Ma'am"])->setExit((char*)"EAST", (char*)"Peter Jin's North Berlin");
  ((*rm)[(char*)"Peter Pan's Madame Ma'am"])->setExit((char*)"SOUTH", (char*)"Peter Jin's Inn");
  ((*rm)[(char*)"Peter Pan's Madame Ma'am"])->setExit((char*)"WEST", (char*)"Peter Pan's Clan");

  ((*rm)[(char*)"Peter Jin's North Berlin"])->setExit((char*)"SOUTH", (char*)"Peter Pan's Dam");
  ((*rm)[(char*)"Peter Jin's North Berlin"])->setExit((char*)"WEST", (char*)"Peter Pan's Madame Ma'am");
  
  ((*rm)[(char*)"Peter Puffin"])->setExit((char*)"NORTH", (char*)"Peter Pan's Jam");
  ((*rm)[(char*)"Peter Puffin"])->setExit((char*)"EAST", (char*)"Jin & Out Fanbase");

  ((*rm)[(char*)"Jin & Out Fanbase"])->setExit((char*)"NORTH", (char*)"Peter Pan's Fam");
  ((*rm)[(char*)"Jin & Out Fanbase"])->setExit((char*)"EAST", (char*)"Jin & Out");
  ((*rm)[(char*)"Jin & Out Fanbase"])->setExit((char*)"SOUTH", (char*)"Peter Pan's Milk Can");
  ((*rm)[(char*)"Jin & Out Fanbase"])->setExit((char*)"WEST", (char*)"Peter Puffin");

  ((*rm)[(char*)"Jin & Out"])->setExit((char*)"NORTH", (char*)"Peter Pan's Clan");
  ((*rm)[(char*)"Jin & Out"])->setExit((char*)"EAST", (char*)"Peter Jin's Inn");
  ((*rm)[(char*)"Jin & Out"])->setExit((char*)"SOUTH", (char*)"Peter Jin's Tin Bin");
  ((*rm)[(char*)"Jin & Out"])->setExit((char*)"WEST", (char*)"Jin & Out Fanbase");

  ((*rm)[(char*)"Peter Jin's Inn"])->setExit((char*)"NORTH", (char*)"Peter Pan's Madame Ma'am");
  ((*rm)[(char*)"Peter Jin's Inn"])->setExit((char*)"EAST", (char*)"Peter Pan's Dam");
  ((*rm)[(char*)"Peter Jin's Inn"])->setExit((char*)"SOUTH", (char*)"Peter Jin's LITTI IN MY CITY");
  ((*rm)[(char*)"Peter Jin's Inn"])->setExit((char*)"WEST", (char*)"Jin & Out");

  ((*rm)[(char*)"Peter Pan's Dam"])->setExit((char*)"NORTH", (char*)"Peter Jin's North Berlin");
  ((*rm)[(char*)"Peter Pan's Dam"])->setExit((char*)"WEST", (char*)"Peter Jin's Inn");
  ((*rm)[(char*)"Peter Pan's Dam"])->setExit((char*)"SOUTH", (char*)"Peter Jin's South Berlin");

  ((*rm)[(char*)"Peter Pan's Evil Twin"])->setExit((char*)"EAST", (char*)"Peter Pan's Milk Can");
  ((*rm)[(char*)"Peter Pan's Evil Twin"])->setExit((char*)"NORTH", (char*)"Peter Puffin");

  ((*rm)[(char*)"Peter Pan's Milk Can"])->setExit((char*)"EAST", (char*)"Peter Jin's Tin Bin");
  ((*rm)[(char*)"Peter Pan's Milk Can"])->setExit((char*)"NORTH", (char*)"Jin & Out Fanbase");

  ((*rm)[(char*)"Peter Jin's Tin Bin"])->setExit((char*)"EAST", (char*)"Peter Jin's LITTI IN MY CITY");
  ((*rm)[(char*)"Peter Jin's Tin Bin"])->setExit((char*)"NORTH", (char*)"Jin & Out");
  ((*rm)[(char*)"Peter Jin's Tin Bin"])->setExit((char*)"WEST", (char*)"Peter Pan's Milk Can");

  ((*rm)[(char*)"Peter Jin's LITTI IN MY CITY"])->setExit((char*)"EAST", (char*)"Peter Jin's South Berlin");
  ((*rm)[(char*)"Peter Jin's LITTI IN MY CITY"])->setExit((char*)"NORTH", (char*)"Peter Jin's Inn");
  ((*rm)[(char*)"Peter Jin's LITTI IN MY CITY"])->setExit((char*)"WEST", (char*)"Peter Jin's Tin Bin");
  
  ((*rm)[(char*)"Peter Jin's South Berlin"])->setExit((char*)"NORTH", (char*)"Peter Pan's Dam");
  ((*rm)[(char*)"Peter Jin's South Berlin"])->setExit((char*)"WEST", (char*)"Peter Jin's LITTI IN MY CITY");

  //Adding all the **starting** items (MANY more items are added as events play out)!
  ((*rm)[(char*)"Peter Jin's Tin Bin"])->addItem((char*)"Peter_Jin's_Safety_Pin");
  
  //Inventory
  vector<Item*> bag;
  vector<Item*>* bagptr = &bag;

  //List of Commands
  vector<Command*> commands;
  vector<Command*>* commandsptr = &commands;
  
  //Current Room
  Room* currentRoom;
  Room** currentRoomptr = &currentRoom;
  Room* lastRoom = ((*rm)[(char*)"Peter Pan's Jam"]);
  
  //Command string and Keyword string
  char commandsarr[99];
  char* commandstr = commandsarr;
  char keywordsarr[99];
  char* keywordstr = keywordsarr;
  
  //Initiating **starting** commands (more added later in events)
  commandsptr->push_back(new Help((char*)"HELP"));
  commandsptr->push_back(new Head((char*)"HEAD"));
  commandsptr->push_back(new Grab((char*)"GRAB"));
  commandsptr->push_back(new Toss((char*)"TOSS"));
  commandsptr->push_back(new Sack((char*)"SACK"));
  int* e = new int[15];
  for(int a = 0; a < 15; ++a){
    e[a] = 0;
  }
  commandsptr->push_back(new Talk((char*)"TALK", e));
  commandsptr->push_back(new Quit((char*)"QUIT"));

  //Setting running and current room to prepare for game start
  bool running = true;
  
  currentRoom = ((*rm)[(char*)"Peter Pan's Jam"]);

  cout << "Welcome to the world of Zuul! I'd like to thank my friend Peter Jin for making this game possible, and for helping me code. Peter Pan's Land is a world set in a dystopian future, where capitalism has led to the rise of Peter Jin & Peter Pan. Anyways, have fun playing!" << endl;
  
  printRoomString(currentRoom);
  
  //Print out long description of room.
  //Print out exits
  //Print out items
  //Then process commands
  while(running){
    //Basically add room to list of visited rooms if it isn't in there already
    vector<char*>::iterator i;
    bool found = false;
    for(i = encRooms.begin(); i != encRooms.end(); ++i){
      if(strcmp((*i), currentRoom->getTitle()) == 0){
	found = true;
      }
    }
    if(found == false){
      encRooms.push_back(currentRoom->getTitle());
    }
    if(lastRoom != currentRoom){
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
    if(currentRoom == (*rm)[(char*)"Peter Pan's Jam"]){
      if(ev[0] == true){
	((*rm)[(char*)"Peter Pan's Jam"])->setDesc((char*)"Peter Pan *was jamming with some songs + dance moves");
	
	((*rm)[(char*)"Peter Pan's Jam"])->setExit((char*)"EAST", (char*)"Peter Pan's Fam");
        ((*rm)[(char*)"Peter Pan's Jam"])->setExit((char*)"SOUTH", (char*)"Peter Puffin");

	((*rm)[(char*)"Peter Pan's Jam"])->addItem((char*)"Peter's_Jam");
	ev[0] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Pan's Fam"]){
      if(ev[1] == true){
	commandsptr->push_back(new Plot((char*)"PLOT"));

	((*rm)[(char*)"Peter Pan's Fam"])->addItem((char*)"Peter_Pan's_SPAM");
	
	ev[1] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Pan's Clan"]){
      if(ev[2] == true){
	((*rm)[(char*)"Peter Pan's Clan"])->addItem((char*)"Peter_Pan's_Saucepan");
	ev[2] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Pan's Madame Ma'am"]){
      if(ev[3] == true){
	((*rm)[(char*)"Peter Pan's Madame Ma'am"])->addItem((char*)"Peter_Pan's_Yam");
	ev[3] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Jin's North Berlin"]){
      if(ev[4] == true && strcmp(commandstr, "TALK") == 0){
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
	    ((*rm)[(char*)"Peter Jin's North Berlin"])->addItem((char*)"Peter_Pan's_Ram");

	    if(burgerYes){
	      cout << "The moment you pull out the burger, the lamb is instantly forgotten about, and the mob nearly rolls you over to get their hands on the burger. Satisfied, the mosh pit then slides south down the hill like the avalanche from a storm. All that's left is a ram. Wait, it wasn't a lamb?" << endl;
	    }else{
	      cout << "The moment you pull out the fries, the lamb is instantly forgotten about, and the mob nearly rolls you over to get their hands on the burger. Satisfied, the mosh pit then slides south down the hill like the avalanche from a storm. All that's left is a ram. Wait, it wasn't a lamb?" << endl;
	    }
	     
	    
	    ((*rm)[(char*)"Peter Jin's North Berlin"])->setDesc((char*)"Tumbleweeds roll over houses and dush-filled wells... But the streets are far from deserted. Just recently, a gathering of around a hundred people stormed south, leaving footprints randomly plastered about the ground...");
	    
	    ev[4] = 2;
	    printRoomString(currentRoom);
	  }else{
	    cout << "You decide to bide your time and wait for the oppurtune moment. Wait, did the cook just roll in a cast iron pot?" << endl;
	  }
	}
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Puffin"]){
      if(ev[5] == true){
	vector<Item*>::iterator bagIt;
	bool finYes = false;
	bool pinYes = false;
	for(bagIt = bag.begin(); bagIt != bag.end(); ++bagIt){
	  if(strcmp((*bagIt)->getName(), "Peter_Jin's_Fin") == 0){
	    finYes = true;
	  }else if(strcmp((*bagIt)->getName(), "Peter_Jin's_Safety_Pin") == 0){
	    pinYes = true;
	  }
	}
	char buffer[999] = "";
	if(finYes && pinYes){
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

	  ((*rm)[(char*)"Peter Puffin"])->setDesc((char*)"RIP Peter Puffin (2019-2019)");

	  
          ((*rm)[(char*)"Peter Puffin"])->addItem((char*)"Peter_Jin's_Mandarin");

	  printRoomString(currentRoom);
	  ev[5] = 2;
	}else if(finYes && pinYes == false){
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
    }else if(currentRoom == (*rm)[(char*)"Jin & Out Fanbase"]){
      if(ev[6] == true){
	
        ((*rm)[(char*)"Jin & Out Fanbase"])->addItem((char*)"Peter_Pan's_Fan");
	
	ev[6] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Jin & Out"]){
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

	    ((*rm)[(char*)"Jin & Out"])->setDesc((char*)"A building the size of a skyscraper towers over the middle of a densely populated city. Employees can be seen hurrying from floor to floor through the pristine glass windows. Then you look up, and no longer see a column of smoke erupting from the building.");
	    
	    ev[7] = 2;
	    printRoomString(currentRoom);
	  }else{
	    cout << "Oh that's too bad then...(The smoke continues to pour from the tower)" << endl;
	  }
	}
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Jin's Inn"]){
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
    }else if(currentRoom == (*rm)[(char*)"Peter Pan's Dam"]){
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

	  ((*rm)[(char*)"Peter Pan's Dam"])->setDesc((char*)"Birds chirp and fish splash as the water flows through the dam, as smooth as silk!");

	((*rm)[(char*)"Peter Jin's LITTI IN MY CITY"])->setDesc((char*)"Peter Jin's LITTI IN MY CITY looks beautiful when lit up at night, looming palaces overlooking serene lakes, and elegant lampposts blazing on every street...");
	
	  printRoomString(currentRoom);
        }
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Pan's Evil Twin"]){
      if(ev[10] == true){
	ev[10] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Pan's Milk Can"]){
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
    }else if(currentRoom == (*rm)[(char*)"Peter Jin's Tin Bin"]){
      if(ev[12] == true){
	ev[12] = 2;
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Jin's LITTI IN MY CITY"]){
      if(ev[13] == 2){
	printRoomString(currentRoom);
      }
    }else if(currentRoom == (*rm)[(char*)"Peter Jin's South Berlin"]){
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
	    
	    ((*rm)[(char*)"Peter Jin's South Berlin"])->setDesc((char*)"Seaweed rolls over houses and dry cracked wells... But the streets are far from deserted. Just recently, a gathering of around a hundred people stormed south, leaving footprints randomly plastered about the ground...");
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
void buildRoom (map<char*,Room*>* rm, char* rmTitle, char* rmDesc) {
  (*rm)[rmTitle] = new Room(rmTitle, rmDesc, new vector<Item*>, new map<char*,char*>);
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
      for(int a = 0; a < strlen(in); ++a){
      in[a] = toupper(in[a]);
        if(in[a] == ' '){
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
      if(strcmp((*commandsIt)->getDesc(), commandstr) == 0){
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
      case GRAB_TYPE:
	if(strcmp(keywordstr,"") != 0){
	  ((Grab*)(*commandsIt))->take(currentRoomptr, bagptr, keywordstr);
	}else{
	  cout << ((Grab*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      case TOSS_TYPE:
	if(strcmp(keywordstr,"") != 0){
	  ((Toss*)(*commandsIt))->drop(currentRoomptr, bagptr, keywordstr);
	}else{
	  cout << ((Toss*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      case SACK_TYPE:
	if(strcmp(keywordstr,"") == 0){
	  ((Sack*)(*commandsIt))->show(bagptr);
	}else{
	  cout << "You rummaged through your sack to find \"" << keywordstr << "\", but then you realized that \"sack\" is a one word command..." << endl;
	}
	break;
      case TALK_TYPE:
        if(strcmp(keywordstr,"") == 0){
	  ((Talk*)(*commandsIt))->act(rm, currentRoomptr, bagptr);
	}else{
	  cout << ((Talk*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      case HELP_TYPE:
        if(strcmp(keywordstr,"") == 0){
	  ((Help*)(*commandsIt))->printHelp(commands);
	}else{
	  cout << ((Help*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      case PLOT_TYPE:
        if(strcmp(keywordstr,"") == 0){
	  ((Plot*)(*commandsIt))->printMap(currentRoomptr, rm, encRoomsptr);
	}else{
	  cout << ((Plot*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      case QUIT_TYPE:
        if(strcmp(keywordstr,"") == 0){
	  ((Quit*)(*commandsIt))->getMeOut();
	}else{
	  cout << ((Quit*)(*commandsIt))->returnBurn() << endl;
	}
	break;
      }
      
   }
}

//Iterates through the exits of a room and prints
void printExitString(map<char*, char*>* exits){
  map<char*, char*>::iterator it;
  for(it = exits->begin(); it != exits->end(); ++it){
    cout << it->first << " ";
  }
  cout << endl;
}

//Iterates through the items of a room and prints
void printItemString(vector<Item*>* items){
  vector<Item*>::iterator iIt;
  for(iIt = items->begin(); iIt != items->end(); ++iIt){
    cout << (*iIt)->getName() << " ";
  }
  cout << endl;
}

//A nice package that gives the user all of the needed UI of exits, items, and currentRoom
void printRoomString(Room* currentRoom){
  cout << "You are at " << currentRoom->getTitle() << "!" << endl;
  cout << currentRoom->getDesc() << endl;
  cout << "Exits: ";
  printExitString(currentRoom->getExits());
  cout << "Items: ";
  printItemString(currentRoom->getItems());
}
