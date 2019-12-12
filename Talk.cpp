#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <stdlib.h>
#include "Talk.h"
#include "Item.h"
#include "Room.h"

Talk::Talk(char* newDescription, int* newEvent) : Command(newDescription)
{
  event = newEvent;
}

int Talk::getType()
{
  return 7;
}

char* Talk::returnBurn()
{
  return (char*) "Unfortunately, you do not have the rights to free speech in this game.";
}


int* Talk::getEv()
{
  return event;
}

void Talk::act(map<char*, Room*>* rm, Room** currentRoom, vector<Item*>* bag)
{
  char scrollText[80]; 
  if(strcmp((*currentRoom)->getTitle(), "High School -> Araragi House") == 0)
  {
    if(event[0] == false)
    {
      cout << "Araragi: Well, I'll be going now." << endl;
      cout << "???: Hold on a second!" << endl;
      cout << "You start walking off and Hanekawa chases after you to catch up." << endl;
      cout << "???: I finally caught up. You walk fast, don't you, Araragi?" << endl;
      cout << "You turn around in surprise after she says your name." << endl;
      cout << "Araragi: Why do you know my name?" << endl;
      cout << "???: What? Of course I'd know. We go to the same school. The \"small village\" radical and the \"ka\" from kanou. Double up on \"good\" as in \"a good child\". And write a \"ki\" as in \"tree\". That's \"Araragi\"." << endl;
      cout << "?: Your first name is the word for calendar... \"Koyomi\", right? So you're... \"Koyomi Araragi\"." << endl;
      cout << "Araragi: You are... Hanekawa. Tsubasa Hanekawa." << endl;
      cout << "Hanekawa: Wow. Amazing, you know the name of someone like me." << endl;
      cout << "Araragi: In the final exam of the first term of our second year, for all subjects including PE and Art, you were the one who correctly answered every question except for one." << endl;
      cout << "Hanekawa: Wait a minute. Oh dear, why do you know so much? Can it be that you're a stalker following me? Maybe that's going a little too far, huh?" << endl;
      cout << "Araragi: That's not it. I heard it from my alien friend." << endl;
      cout << "Hanekawa: What? You actually have friends?" << endl;
      cout << "Araragi: Ask whether or not there are aliens first!" << endl;
      cout << "Hanekawa: Well, my impression was that you were always alone, and kept to yourself." << endl;
      cout << "Araragi: Well, you were right. I admit I don't have any friends. Even a guy with no friends like me knows who you are. That means you're famous." << endl;
      cout << "Hanekawa: Don't say that. I don't like jokes like that very much. You know, Araragi... Araragi, do you believe that vampires exist?" << endl;
      cout << "Araragi: What about vampires?" << endl;
      cout << "Hanekawa: Recently, there's something of a rumor going around. That there's a vampire in town right now. So you shouldn't walk around alone at night." << endl;
      cout << "Araragi: So vague... And that rumor is completely lacking credibility." << endl;
      cout << "Hanekawa: They say the vampire is a very beautiful blonde woman who has eyes so cold it makes your spine freeze." << endl;
      cout << "Araragi: You couldn't tell whether or not she's a vampire just from that. Maybe she's just an ordinary citizen who stands out simply because she's blond?" << endl;
      cout << "Hanekawa: But, while lit by a streetlight, despite her blonds hair being almost too bright to look at, she had no shadow, so they say." << endl;
      cout << "Araragi: But still, it was evening, it could be a mistake, even if she was lit by the streetlight, don't you think?" << endl;
      cout << "Hanekawa: Yeah, I also think it's a ridiculous rumor. However, if there actually was a vampire, I think I'd like to meet it. Something superior to humans like that... It'd be nice if it actually existed." << endl;
      cout << "Araragi: Superior to humans? You mean like a god or something?" << endl;
      cout << "Hanekawa: It doesn't necessarily have to be a god or anything. Because we aren't rewarded otherwise, right? Oops, I've said too much! Araragi, you're a much easier person to speak with than I expected. My tongue slipped, and I may have said something weird. If you're this easy to speak with, it's strange you have no friends. Why don't you make any friends?" << endl;
      cout << "Araragi: Because if I make friends, my strength as a human decreases." << endl;
      cout << "Hanekawa: What? I'm sorry. I don't quite understand what you mean." << endl;
      cout << "Araragi: Well, I put it... How do I put it... If I had friends, I'd have to look out for those friends, right? If my friends got hurt, I'd get hurt too. If my friend is sad, I'm also sad. In other words, I think it meansyou become more vulnerable. That's clearly being weakened as a human." << endl;
      cout << "Hanekawa: But, if your friend is having fun, you're having fun too and if your friend is happy, you're also happy. So it doesn't necessarily mean you're becoming weaker." << endl;
      cout << "Araragi: No. When my friend is having fun, I feel jealous, and when my friend is happy, I feel envious." << endl;
      cout << "Hanekawa: Jeez, you're so narrow minded." << endl;
      cout << "Araragi: Leave me alone" << endl;
      cout << "Hanekawa: Anyways, I'm going to the library now. Araragi, would you like to come with me?" << endl;
      cout << "Araragi: Why? What would we do at the library?" << endl;
      cout << "Hanekawa: We'd study of course." << endl;
      cout << "Araragi: Of course? Unfortunately, I'm not so diligent that I'd voluntarily study during spring break when there's not any homework." << endl;
      cout << "Hanekawa: But next year, we'll have to study for college entrance exams, you know?" << endl;
      cout << "Araragi: Entrance exams or not... I don't even know if I'll be able to graduate high school. No matter what I do now, I won't make it in time." << endl;
      cout << "Hanekawa: I see... Araragi, do you have a cellphone?" << endl;
      cout << "Araragi: Of course I do." << endl;
      cout << "Hanekawa: Give it" << endl;
      cout << "You had Hanekawa your phone" << endl;
      cout << "Hanekawa: Thanks. Here!" << endl;
      cout << "She hands you back your phone after typing some stuff into it. She then runs across the street as the crossing signal changes. She stops halfway across." << endl;
      cout << "Hanekawa: I entered my phone number and email address into it. How unfortunate! You just made a friend." << endl;
      cout << "You stare in disbelief while she walks away and waves to you." << endl;
      cout << "Araragi: What's with her?"
      cin.get(scrollText, 80);
      cin.clear();
      cin.ignore(999, '\n');
      event[0] = true;
    }
    else
    {//Come back and change
      //cout << "There's no one to talk to ... maybe you should check in with Peter Pan's Fam to the East?" << endl;
    }
  }
  else if(strcmp((*currentRoom)->getTitle(), "The Araragi Residence") == 0)
  {
    if(event[1] == false)
    {
      cout << "Some time passes and you're sitting down on your bed thinking about Hanekawa and you suddenly start getting urges as you think about her." << endl;
      cin.get(scrollText, 80);
      cin.clear();
      cin.ignore(999, '\n');
      event[1] = true;
    }
    else
    {//Fix later
      //cout << "(*sniff*) No need to thank me (*sniff*)" << endl;
    }
  }
  //else if(strcmp((*currentRoom)->getTitle(), "Araragi House -> Book Store") == 0)
  //{
    //if(event[2] == false)
    //{
      //cout << "You head over to a section of the store to look for what you want." << endl;
      //cin.get(scrollText, 999);
      //cin.clear();
      //cin.ignore(999, '\n');
      //event[2] = true;
    //}
    //else
    //{Fix later
      //cout << "There's no one to talk to..." << endl;
    //}
  //}
  else if(strcmp((*currentRoom)->getTitle(), "Haga Books") == 0)
  {
    if(event[2] == false)
    {
      cout << "You head over to a section of the store to look for what you want." << endl;
      cin.get(scrollText, 80);
      cin.clear();
      cin.ignore(999, '\n');
      event[2] = true;
    }
    else
    {//Fix later
      //cout << "Nothing like some yam to cheer up your fam!" << endl;
    }
  }
  else if(strcmp((*currentRoom)->getTitle(), "Book Store -> Subway Station") == 0)
  {
    if(event[3] == false)
    {
      cout << "On your way home, suddenly, all of the city lights go off except one. The last one is flickering ominously. You find yourself at the entrance to a subway station where there is a trail of puddles of blood leading down into the transit center." << endl;
      cin.get(scrollText, 80);
      cin.clear();
      cin.ignore(999, '\n');
      event[3] = true;
    }
    else
    {//Fix
      //cout << "Well, that was a natural phoenomenon" << endl;
    }
  }
  else if(strcmp((*currentRoom)->getTitle(), "Subway Station") == 0)
  {
    if(event[4] == false)
    {
      cout << "You follow the blood trail further down into the subway station, leading you around corners and down staircases. You turn a corner and suddenly notice giant stains of blood splattered all across one wall. At this point, your breathing is getting heavier, and you start to move faster. Down, down, down you go, deeper into the catacombs of the subway station. You reach an escalator. As you reach the bottom of the escalator, you finall see what the trail of blood led you to. Your heart rate picks up even more and your breathing becomes more rapid as less than 15 feet in front of you is a woman. A woman in a bright red dress with blonde hair, laying on the ground in a pool of blood. She has lost both her arms and her legs and you can tell she must be on the verge of bleeding to death." << endl;
      cout << "???: You..." << endl;
      cout << "She lifts her head to look at you" << endl;
      cout << "???: I will allow you to save me." << endl;
      cout << "You're too freaked out to answer right away." << endl;
      cout << "???: Did you not hear me? I am saying that I will allow you to save me." << endl;
      cout << "Araragi: H-Hey..." << endl;
      cout << "You stumble towards her collapsing on the ground and start talking in a very panicky voice." << endl;
      cout << "Araragi: Are you alright? I-I'll call for an ambulance right a-" << endl;
      cout << "You get a better look at her and fully realize the troubling situation you've found yourself in and completely freak out as you scramble backwards. You fumble with your phone trying to call for an ambulance but to no surprise, you are still too shaken up to actually do it." << endl;
      cout << "???: An ambulance? I have no need for such a thing... So why don't you... Give me your blood." << endl;
      cout << "After you heard those words, you immediately thought back to your conversation with Hanekawa about vampires." << endl;
      cout << "Hanekawa: Araragi, do you believe that vampires exist? They say the vampire is a very beautiful woman who has eyes so cold it makes your spine freeze." << endl;
      cout << "Cutting back to you and the woman." << endl;
      cout << "Kiss-shot: My name is Kiss-shot Acerola-orion Heart-under-blade. I am the iron-blooded, hot-blooded, cold-blooded vampire. I will drink your blood and take it into my own flesh. So why don't you give me your blood." << endl;
      cout << "Araragi: If you're a vampire, aren't you supposed to be immortal?" << endl;
      cout << "Kiss-shot: I've lost too much blood, I can no longerregenerate or transform. At this rate... I will die. You're a lowly, insignificant human. You should be honored to become part of my flesh and blood." << endl;
      cout << "Araragi: You say you need blood? What about a blod transfusion? H-How much do you need?" << endl;
      cout << "Kiss-shot: If you give me all of your blood, that will be a stopgap." << endl;
      cout << "Araragi: I see, all of my blood..." << endl;
      cout << "The full impact of her words sets in as you decide whether to run away or help her." << endl;
      cout << "Do you want to save her or run away? (SAVE, RUN)" << endl;
      cin.get(scrollText, 80);
      cin.clear();
      cin.ignore(999, '\n');
      for (int i = 0; i < strlen(scrollText); i++)
      {
        scrollText[i] = toupper(scrollText[i]);
      }
      if (strcmp(scrollText, "SAVE") == 0)
      {
        cout << endl;
      }
      else if (strcmp(scrollText, "RUN) == 0)
      {
        
      }
      event[4] = true;
    }
    else if(event[4] == true)
    {//Fix
      //cout << "Hey there! Sorry, but I'll have to pass on letting you pass!" << endl;
      //cin.get(scrollText, 999);
      //cin.clear();
      //cin.ignore(999, '\n');
      //After it's gone
    }
    else
    {//Fix
      //cout << "*blub* *blub*" << endl;
    }
  }
  else if(strcmp((*currentRoom)->getTitle(), "Haga Books") == 0)
  {
    if(event[6] == false)
    {
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
      event[6] = true;
    }
    else
    {
      cout << "There's no one to talk to..." << endl;
    }
  }
  else if(strcmp((*currentRoom)->getTitle(), "Storage Shed") == 0)
  {
    if(event[7] == false)
    {
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
      event[7] = true;
      //Scan for stuff
    }
    else if(event[7] == true)
    {
      cout << "(Some Yam and Spam?...)" << endl;
    }
    else
    {
      cout << "Heehee, all thanks to you, the kitchens no longer on fire! There's still a lot of screaming and shouting tho... Anyway, I got some burgers and fries, if you need any!" << endl;
    }
  }
  else if(strcmp((*currentRoom)->getTitle(), "Convenience Store") == 0)
  {
    if(event[8] == false)
    {
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
  }else if(strcmp((*currentRoom)->getTitle(), "High School -> Home") == 0){
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
  }else if(strcmp((*currentRoom)->getTitle(), "Book Store -> Subway Station") == 0){
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
  }else if(strcmp((*currentRoom)->getTitle(), "Cram School -> High School") == 0){
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
  }else if(strcmp((*currentRoom)->getTitle(), "Cram School -> Stadium") == 0){
    if(ev[12] == false){
      cout << "The wind intensifies. Some tumbleweed appears out of nowhere and drifts across the room" << endl;
      cin.get(scrollText, 999);
      cin.clear();
      cin.ignore(999, '\n');
      ev[12] = true;
    }else{
      cout << "Wooooooosh" << endl;
    }
  }else if(strcmp((*currentRoom)->getTitle(), "Cram School -> Subway Station") == 0){
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
  }else if(strcmp((*currentRoom)->getTitle(), "Book Store -> Convenience Store") == 0){
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
    }else if(ev[14] == true)
    {
      cout << "(Something mass-produced and cheap...)" << endl;
    }
    else
    {
      cout << "Well, that was a natural phoenomenon" << endl;
    }
  }
  else if (strcmp((*currentRoom)->getTitle(), "Cram School -> Storage Shed") == 0)
  {
    
  }
  else if (strcmp((*currentRoom)->getTitle(), "Storage Shed -> Rooftop") == 0)
  {
    
  }
  else if (strcmp((*currentRoom)->getTitle(), "Home -> Book Store") == 0)
  {
    
  }
}
