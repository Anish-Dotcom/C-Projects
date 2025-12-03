#ifndef ROOM
#define ROOM
#include <iostream>
#include <cstring>
#include <map>
#include "Items.h"

using namespace std;

class Room {
 public:
  void setExits(const char* direction, Room* neighbor);
  Room* getExits(const char* direction);
  char* getDescription();
  void setDescription(const char* desc);
  void setItem(const char* desc);
private:
  map<int,Room*> exits;
  char description[20]= "coolio";
  
};
#endif
