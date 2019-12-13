#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Printable 
{
  public:
    ~Printable();
    char* description;
    char* name;
    void print();
    void init(char const* name, char const* description);
};
