#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <stdlib.h>
#include "Talk.h"
#include "Item.h"
#include "Room.h"

Talk::Talk(char* newDescription, int* newEv) : Command(newDescription){
  ev = newEv;
}

int Talk::getType(){
  return 7;
}

char* Talk::returnBurn(){
  return (char*) "Unfortunately, you do not have the rights to free speech in this game.";
}


int* Talk::getEv(){
  return ev;
}

void Talk::act(map<char*, Room*>* rm, Room** currentRoom, vector<Item*>* bag){
  char scrollText[999] = ""; 
  if(strcmp((*currentRoom)->getTitle(), "The Araragi Residence") == 0){
    if(ev[0] == false){
      cout << "You try to jam along with Peter Pan. Suddenly, he is spirited away by some EVIL PEANUT BUTTER" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "All that remains is Peter's Jam. It fills you with DETERMINATION!" << endl;
      ev[0] = true;
    }else{
      cout << "There's no one to talk to ... maybe you should check in with Peter Pan's Fam to the East?" << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Eikou Cram School") == 0){
    if(ev[1] == false){
      cout << "Suddenly, a broad-shouldered handsome man stumbles into the room." << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "*sniff* I'm Peter Pan's Uncle Sam. *sniff* Here, take this map. I don't need it anymore." << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "You got the map! Type \"Plot\" to read it!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "*sniff* You look healthy... take some SPAM. (Not sponsored by SPAM)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[1] = true;
    }else{
      cout << "(*sniff*) No need to thank me (*sniff*)" << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Naoetsu Private High School") == 0){
    if(ev[2] == false){
      cout << "Wahhhhhh! It's not fair! He was too young! (Wails and Sobs drown you)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "But charleston, what are we going going to do with Peter Pan's Saucepan?" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Jacob, no one cares! Just throw it in the corner somewhere!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "(The crying continues)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[2] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Subway Station") == 0){
    if(ev[3] == false){
      cout << "I told that Peter Pan that he should've just stayed with his fam on the farm!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "That young man pan, not a wise man!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Here, take some yam" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "(Peter Pan's Yam drifts through the air and lands at your feet, as softly as if it were a feather)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[3] = true;
    }else{
      cout << "Nothing like some yam to cheer up your fam!" << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Rooftop") == 0){
    if(ev[4] == false){
      cout << "We want tasty lamb stew! We want tasty lamb stew!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "(In the corner, a small band of faithful Peter Pan Followers Huddle around ... a plump and tasty lamb...)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "(If only they had something that was cheap to eat, comes in large quantities, and can be prepared quickly)" << endl;
      ev[4] = true;
    }else if(ev[4] == true){
      cout << "(Something mass-produced and cheap...)" << endl;
    }else{
      cout << "Well, that was a natural phoenomenon" << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Tokyo Olympic Stadium") == 0){
    if(ev[5] == false){
      cout << "Hey there! Sorry, but I'll have to pass on letting you pass!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[5] = true;
    }else if(ev[5] == true){
      cout << "Hey there! Sorry, but I'll have to pass on letting you pass!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      //After it's gone
    }else{
      cout << "*blub* *blub*" << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Haga Books") == 0){
    if(ev[6] == false){
      cout << "Hey yo! Are you Peter Pan's Fan? Of course you are! (A folded fan slaps you right on the forhead)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Everyone is investing their stocks into the Peter Jin Bin Megacorp(tm) after Peter Pan's disappearance, but you better stay faithful! Ohohoho! (He struts away opening and closing his fan)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "(You really don't know what to say)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[6] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Storage Shed") == 0){
    if(ev[7] == false){
      cout << "Ah! Sorry, but by any chance, would you have some SPAM & Yam?" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Supplies are running low and uh..." << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "(Another column of dust erupts from the middle of the tower)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "...tensions are rising in the kitchen..." << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[7] = true;
      //Scan for stuff
    }else if(ev[7] == true){
      cout << "(Some Yam and Spam?...)" << endl;
    }else{
      cout << "Heehee, all thanks to you, the kitchens no longer on fire! There's still a lot of screaming and shouting tho... Anyway, I got some burgers and fries, if you need any!" << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Convenience Store") == 0){
    if(ev[8] == false){
      cout << "Hearing the bell attached to the door, someone walks out of the kitchen wearing blue jeans, a blue t-shirt, and a red carapace." << endl; 
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Hello! my name is Mr.sbarK, and I'm the owner of this inn! Sit down, sit down, I'll have you know that my burgers are the best around. This one's on the house!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "(Mr.sbarK talks for a looong time)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "(... A couple hours later?...)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "...and then this pink starfish wearing green pants comes along, only to tell me the time with a watch that he drew on his arm with permanent marker! Ehehehehe!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "No but really, thanks for listening to me! I've gotta attend to other affairs... " << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Just remember, there's a spiky yellow beast that roams the water around these parts that makes travelling an absolute pain!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "I tried to fight it when I was younger, but all I got to show for it was this wooden right leg and a piece of its fin that I clipped off." << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "But I'm old now, and that fin makes me grow weary at the sight of it. You can take it along if you want, but make sure you come back for a visit sometime! Farewell! (He saunters back into the kitchen)" << endl; 
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[8] = true;
      //do stuff
    }else if (ev[8] == true){
      cout << "(Mr.sbarK is still in the kitchen...)" << endl;
    }else{
      cout << "(Mr.sbarK is in the party!)" << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "High School -> Book Store") == 0){
    if(ev[9] == false){
      cout << "Muahahaha! Those foolish fools, as they squabble among themselves, I grow stronger by the minute from all this water!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "I, PinkFluffyUnicornClam, will exceed all expectations and make the world my oyster!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[9] = true;
    }else if(ev[9] == true){
      cout << "Ehehehehe~~" << endl;
    }else{
      cout << "Nuhuhuhuhu" << endl;
      cout << "Wait, is that coming from UNDERWATER?!" << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Pan's Evil Twin") == 0){
    if(ev[10] == false){
      //???
      cout << "YOU DIED" << endl;
      exit(0);
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[10] = true;
    }else{
      cout << "There's no one to talk to..." << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Pan's Milk Can") == 0){
    if(ev[11] == false){
      cout << "You ask if anyone is home, but no one replies." << endl; 
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Carefully, you tread inside the interior of the metal tank, footsteps echoing far up towards the immense arches of Peter Pan's humble abode." << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Suddenly, you are alarmed by two sights: the giant stove indiscriminately placed near the edge of the room, and a pot hole from which leaked p e a n u t b u t t e r, along with the offering tray on top of it. " << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "You inch closer to the pothole, until you realize that there is a small receipt-like slip of paper placed on top of the offering tray" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "It reads: (Not Peter Jin's Evil Twin) Hello, this is not Peter Jin's Evil Twin, and I am definitely not under this pothole that's leaking p e a n u t b u t t e r, and Peter Pan is definitely not next to me being forced to create a brand of peanut butter that will rival the Jam industry..." << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "...(anyways, e v i l p e a n u t b u t t e r told me not to tell anyone about what is happening under this pothole, but I've been craving some of Peter Pan's Universal Flan.." << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "I like mine with two servings of all-natural protein, cooked above some extra hot fire! If, by any chance, someone chances upon this note, make my flan, and I'll maybe consider being your friend! (P.S. An extra pair of hands might help, and any old pan will work! I heard something about fanning the fire too! THX XOXO <3)" << endl;  
      ev[11] = true;
    }else{
      cout << "(You read the note again) I like mine with two servings of all-natural protein, cooked above some extra hot fire! If by any chance, someone chances upon this note, make my flan, and I'll maybe consider being your friend! (P.S. An extra pair of hands might help, and any old pan will work! I heard something about fanning the fire too! THX XOXO <3)" << endl;  
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Jin's Tin Bin") == 0){
    if(ev[12] == false){
      cout << "The wind intensifies. Some tumbleweed appears out of nowhere and drifts across the room" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[12] = true;
    }else{
      cout << "Wooooooosh" << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Jin's LITTI IN MY CITY") == 0){
    if(ev[13] == false){
      cout << "Thanks to this blackout, my niece is finally in her room reading a book by candlelight!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Ha! If you ask me, that's what you Millenials get for \"Ok Boomer\"-ing me! No more socialist media, or what ever they call it, " << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "When I was you age, I had to trek 23 miles everyday on the way to-" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "(You leave to save yourself a few hours)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[13] = true;
    }else if (ev[13] == true){
      cout << "(The old man grumbles on...)" << endl;
    }else{
      cout << "Bah! Back in my day, we read books by candlelight!" << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Peter Jin's South Berlin") == 0){
    if(ev[14] == false){
      cout << "We want tasty ram stew! We want tasty ram stew!" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "(In the corner, a small band of faithful Peter Pan Followers Huddle around ... a plump and tasty ram...)" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      cout << "(If only they had something that was cheap to eat, comes in large quantities, and can be prepared quickly)" << endl;
      ev[14] = true;
    }else if(ev[14] == true){
      cout << "(Something mass-produced and cheap...)" << endl;
    }else{
      cout << "Well, that was a natural phoenomenon" << endl;
    }
  }
}
