#ifndef ROOM
#define ROOM
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "Items.h"

using namespace std;

class Room {
public://Prototypes
  void setExits(const char* direction, Room* neighbor);
  Room* getExits(const char* direction);
  char* getDescription();
  void setDescription(const char* desc);
  void setItem(const char* name, const char*desc);
  Items* getItem(int numb);
  void setName(const char* inName);
  char* getName();
  Items* findItem(char* Name);
  void placeItem(Items* item);
  void printItems();
  void printExits();
  int getItemLength();
  void printDesc();
private:
  map<int,Room*> exits;//Map that takes int and Room and maps them together with int as a key
  char description[60];
  vector<Items*> itemList;//Ignore this the teacher knows why this is here but it is nessecsary only itemlist5 is used
  vector<Items*> itemList2;
  vector<Items*> itemList3;
  vector<Items*> itemList4;
  vector<Items*> itemList5;

  char name[10];
};
#endif

