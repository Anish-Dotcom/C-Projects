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
  const char* getDescription();
 private:
  map<const char*,Room*> exits;
  const char description[20]= "coolio";
};
#endif
