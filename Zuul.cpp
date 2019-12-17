#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

/* Finn McKinley
 * A Zuul Project
 * 12/13/19
*/

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
      char scrollText[80];
      int eventCounter = 0;
      //Tracks the current event
      if (eventCounter == 0 && )
      {//If it's the first event
	//char* nameCompare = this->name();
	//if (strcmp(this->name(), "rd1") == 0)
	//{
	  cout << "Araragi: Well, I'll be going now." << endl;
	  cin.getline(scrollText, 80);
	      cin.ignore(999, '\n');
	  cout << "???: Hold on a second!" << endl;
	      cin.getline(scrollText, 80);
	      cin.ignore(999, '\n');
	  cout << "You start walking off and a girl starts chasing after you." << endl;
	      cin.getline(scrollText, 80);
	      cin.ignore(999, '\n');
	  cout << "Araragi: Why do you know my name?" << endl;
	  cin.getline(scrollText, 80);
	  cin.ignore(999, '\n');
	  cout << "???: What? Of course I'd know. We go to the same school. You're Araragi. Koyomi Araragi." << endl;
	      cin.getline(scrollText, 80);
	      cin.ignore(999, '\n');
	  cout << "Araragi: You are... Hanekawa. Tsubasa Hanekawa." << endl;
	      cin.getline(scrollText, 80);
	      cin.ignore(999, '\n');
	  cout << "Hanekawa: Wow. Amazing, you know the name of someone like me." << endl;
	      cin.getline(scrollText, 80);
	      cin.ignore(999, '\n');
	  cout << "Araragi: In the final exam of the first term of our second year, for all subjects including PE and Art, you were the only one who correctly answered every question except for one." << endl;
	  cin.getline(scrollText, 80);
	  //cin.ignore(999, '\n');
	  cout << "Hanekawa: Wait a minute. Oh dear, why do you know so much? Can it be that you're a stalker following me? Maybe that's going a little too far, huh?" << endl;
	      cin.getline(scrollText, 80);
	      cin.ignore(999, '\n');
	  cout << "Araragi: That's not it. I heard it from my alien friend." << endl;
	      cin.getline(scrollText, 80);
	      cin.ignore(999, '\n');
	  cout << "Hanekawa: What? You actually have friends?" << endl;
	      cin.getline(scrollText, 80);
	      cin.ignore(999, '\n');
	  cout << "Araragi: Ask whether or not there are aliens first!" << endl;
	      cin.getline(scrollText, 80);
	      cin.ignore(999, '\n');
	  cout << "Hanekawa: Well, my impression was that you were always alone, and kept to yourself." << endl;
	  cin.getline(scrollText, 80);
	  cout << "Araragi: Well, you were right. I admit I don't have any friends. Even a guy with no friends like me knows who you are. That means you're famous." << endl;
	      cin.getline(scrollText, 80);
	  cout << "Hanekawa: Don't say that. I don't like jokes like that very much. You know, Araragi... Araragi, do you believe that vampires exist?" << endl;
	      cin.getline(scrollText, 80);
	  cout << "Araragi: What about vampires?" << endl;
	      cin.getline(scrollText, 80);
	  cout << "Hanekawa: Recently, there's something of a rumor going around. That there's a vampire in town right now. So you shouldn't walk around alone at night." << endl;
	      cin.getline(scrollText, 80);
	  cout << "Araragi: So vague... And that rumor is completely lacking credibility." << endl;
	      cin.getline(scrollText, 80);
	  cout << "Hanekawa: They say the vampire is a very beautiful blonde woman who has eyes so cold it makes your spine freeze." << endl;
	  cin.getline(scrollText, 80);
	  cout << "Araragi: You couldn't tell whether or not she's a vampire just from that. Maybe she's just an ordinary citizen who stands out simply because she's blonde?" << endl;
	      cin.getline(scrollText, 80);
	  cout << "Hanekawa: But, while lit by a streetlight, despite her blonde hair being almost too bright to look at, she had no shadow, so they say." << endl;
	      cin.getline(scrollText, 80);
	  cout << "Araragi: But still, it was evening, it could be a mistake, even if she was lit by the streetlight, don't you think?" << endl;
	      cin.getline(scrollText, 80);
	  cout << "Hanekawa: Yeah, I also think it's a ridiculous rumor. However, if there actually was a vampire, I think I'd like to meet it. Something superior to humans like that... It'd be nice if it actually existed." << endl;
	  cin.getline(scrollText, 80);
	  cout << "Araragi: Superior to humans? You mean like a god or something?" << endl;
	      cin.getline(scrollText, 80);
	  cout << "Hanekawa: It doesn't necessarily have to be a god or anything. Because we aren't rewarded otherwise, right? Oops, I've said too much! Araragi, you're a much easier person to speak with than I expected. My tongue slipped, and I may have said something weird. If you're this easy to speak with, it's strange you have no friends. Why don't you make any friends?" << endl;
	      cin.getline(scrollText, 80);
	  cout << "Araragi: Because if I make friends, my strength as a human decreases." << endl;
	  cin.getline(scrollText, 80);
	  cout << "Hanekawa: What? I'm sorry. I don't quite understand what you mean." << endl;
	      cin.getline(scrollText, 80);
	  cout << "Araragi: Well, I put it... How do I put it... If I had friends, I'd have to look out for those friends, right? If my friends got hurt, I'd get hurt too. If my friend is sad, I'm also sad. In other words, I think it means you become more vulnerable. That's clearly being weakened as a human." << endl;
	      cin.getline(scrollText, 80);
	  cout << "Hanekawa: But, if your friend is having fun, you're having fun too and if your friend is happy, you're also happy. So it doesn't necessarily mean you're becoming weaker." << endl;
	  cin.getline(scrollText, 80);
	  cout << "Araragi: No. When my friend is having fun, I feel jealous, and when my friend is happy, I feel envious." << endl;
	      cin.getline(scrollText, 80);
	  cout << "Hanekawa: Jeez, you're so narrow minded." << endl;
	      cin.getline(scrollText, 80);
	  cout << "Araragi: Leave me alone." << endl;
	  cin.getline(scrollText, 80);
	  //cout << endl;
	  cout << "Hanekawa: I'm going to the library now. Araragi, would you like to come with me?" << endl;
	      cin.getline(scrollText, 80);
	  cout << "Araragi: Why? What would we do at the library?" << endl;
	      cin.getline(scrollText, 80);
	  cout << "Hanekawa: We'd study of course." << endl;
	      cin.getline(scrollText, 80);
	  cout << "Araragi: Of course? Unfortunately, I'm not so diligent that I'd voluntarily study during spring break when there's not any homework." << endl;
	      cin.getline(scrollText, 80);
	  cout << "Hanekawa: But next year, we'll have to study for college entrance exams, you know?" << endl;
	  cin.getline(scrollText, 80);
	  cout << "Araragi: Entrance exams or not...I don't even know if I'll graduate high school. No matter what I do now, I won't make it in time." << endl;
	      cin.getline(scrollText, 80);
	  cout << "Hanekawa: I see... Araragi, do you have a cellphone?" << endl;
	      cin.getline(scrollText, 80);
	  cout << "Araragi: Of course I do." << endl;
	      cin.getline(scrollText, 80);
	  cout << "Hanekawa: Give it." << endl;
	      cin.getline(scrollText, 80);
	  cout << CC_BLU << "You hand your phone over to her." << CC_CLR << endl;
	      cin.getline(scrollText, 80);
	  cout << "Hanekawa: Thanks. Here!" << endl;
	      cin.getline(scrollText, 80);
	  cout << CC_BLU << "She hands you back your phone after typing some stuff in. She then runs across the street as the crossing signal changes. She stops halfway across." << CC_CLR << endl;
	      cin.getline(scrollText, 80);
	  cout << "Hanekawa: I entered my phone number and emal address into it. How unfortunate! You just made a friend." << endl;
	      cin.getline(scrollText, 80);
	  cout << CC_BLU << "You stare in confusion while Hanekawa walks away and waves goodbye to you." << CC_CLR << endl;
	      cin.getline(scrollText, 80);
	  cout << "Araragi: What's with her?" << endl;
	      cin.getline(scrollText, 80);
	  eventCounter++;
	  //Move to the next event
	  //}
      }
      else if (eventCounter == 1)
      {//If it's the second event
	//if (strcmp(currentRoom, "araragiHouse") == 0)
	//{
	  cout << "You recount your encounter with Tsubasa Hanekawa earlier that day and the urgs become too much for you to handle." << endl;
	  //Events
	  //change color
	  eventCounter++; 
	  //Move to the third event
	  //}
      }
      else if (eventCounter == 2)
      {
	//if (strcmp(currentRoom, "bookStore") == 0) 
	//{
	  eventCounter++;
	  //}
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
  cramSchool->rooms[1] = rd4;
  cramSchool->rooms[2] = h1;
  cramSchool->rooms[3] = rd5;
  highSchool->rooms[1] = rd1;
  highSchool->rooms[2] = rd3;
  subwayStation->rooms[1] = rd5;
  subwayStation->rooms[3] = rd2;
  rooftop->rooms[3] = h2;
  stadium->rooms[3] = rd4;
  bookStore->rooms[0] = rd7;
  bookStore->rooms[2] = rd6;
  bookStore->rooms[1] = rd2;
  storageShed->rooms[1] = h2;
  storageShed->rooms[0] = h1;
  convenienceStore->rooms[0] = rd6;
  rd1->rooms[3] = highSchool;
  rd2->rooms[1] = subwayStation;
  rd2->rooms[3] = bookStore;
  rd3->rooms[2] = cramSchool;
  rd3->rooms[0] = highSchool;
  rd4->rooms[3] = cramSchool;
  rd4->rooms[1] = stadium;
  rd5->rooms[3] = subwayStation;
  rd5->rooms[1] = cramSchool;
  rd6->rooms[0] = bookStore;
  rd6->rooms[2] = convenienceStore;
  rd7->rooms[2] = bookStore;
  h1->rooms[0] = cramSchool;
  h1->rooms[2] = storageShed;
  h2->rooms[1] = rooftop;
  h2->rooms[3] = storageShed;

  //Items
  //A new item
  //Add the item's name and description
  //Add the item to the vector of items
  Item* magazine = new Item();
  magazine->init("Exciting_Magazine", "An exciting magazine.");
  bookStore->items.push_back(magazine);
  items.push_back(magazine);
  Item* rake = new Item();
  rake->init("Rake", "Use in your yard.");
  convenienceStore->items.push_back(rake);
  items.push_back(rake);
  Item* gc = new Item();
  gc->init("Gold_Coin", "A gold coin");
  rd7->items.push_back(gc);
  items.push_back(gc);
  Item* u = new Item();
  u->init("Unicorn", "What even?");
  h2->items.push_back(u);
  items.push_back(u);
  Item* hl = new Item();
  hl->init("Heart_Locket", "<3");
  stadium->items.push_back(hl);
  items.push_back(hl);

  return highSchool;
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
  {//Iterate through the items
    char* uppercaseName = new char[strlen((*it)->name)];
    strcpy(uppercaseName, (*it)->name);
    strupper(uppercaseName);
    //Check if it's a valid item
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
  {//Go through the items
    if(*it == item)
    {//If the item needs to be deleted
      deleteFrom->erase(it);
      //Delete the item
      return;
    }
    it++;
  }
}
