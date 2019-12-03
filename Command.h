#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <cstring>

class Command
{
  public:
    Command(char*);
    char* getDescription();
    virtual int getType();
    virtual char* returnBurn();
  private:
    char* description;
};

#endif
