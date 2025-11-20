#ifndef ROOM
#define ROOM
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class Room {
 public:
  void setExits(const char* direction, Room* neighbor);
  Room* getExits();
  char* getDescription();
 private:
  map<const char*,Room*> exits;
  char description[20]= "coolio";
};
#endif
