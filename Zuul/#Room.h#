#ifndef ROOM
#define ROOM
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "Items.h"

using namespace std;

class Room {
 public:
  void setExits(const char* direction, Room* neighbor);
  Room* getExits(const char* direction);
  char* getDescription();
  void setDescription(const char* desc);
  void setItem(const char* name, const char*desc);
  Items* getItem(int numb);
  void setName(const char* inName);
  char* getName();
  Items* findItem(char* Name);
private:
  map<int,Room*> exits;
  char description[50]="coolio";
  vector<Items*> itemList;
  vector<Items*> itemList2;
  char name[10];
};
#endif

