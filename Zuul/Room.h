#ifndef ROOM
#define ROOM
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

struct cmp_str {
  bool operator()(char const *a, char const *b) const {
    return strcmp(a,b) <0;
  }
};

class Room {
 public:
  void setExits(char* direction, Room* neighbor);
  Room* getExits();
  char* getDescription();
  void setDescription(char* desc);
 private:
  map<int,Room*> exits;
  char description[20]= "coolio";
};
#endif
