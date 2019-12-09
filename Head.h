//Head is like anyother command but its move function requires a destination str, the map of rooms and titles, and the current room
#include <iostream>
#include <cstring>
#include <map>
#include "Command.h"
#include "Room.h"

class Head : public Command {
 public:
  Head(char*);
  int getType();
  char* returnBurn();
  void move(char*, map<char*, Room*>*, Room**);
 private:
};
