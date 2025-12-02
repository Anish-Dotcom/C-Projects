#ifndef ROOM
#define ROOM
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class Room {
 public:
  void setExits(const char* direction, Room* neighbor);
  Room* getExits(const char* direction);
  char* getDescription();
  void setDescription(char* desc);
 private:
  map<int,Room*> exits;
  char description[20]= "coolio";
};
#endif
