#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "Room.h"

using namespace std;

static int directionToCode(const char* direction) {//Direction to int mapping
    if (strcasecmp(direction, "east") == 0)  return 1;
    if (strcasecmp(direction, "west") == 0)  return 2;
    if (strcasecmp(direction, "north") == 0) return 3;
    if (strcasecmp(direction, "south") == 0) return 4;
    return -1;
}

static const char* codeToDirection(int code) {//Int to direction mapping
    switch (code) {
        case 1: return "east";
        case 2: return "west";
        case 3: return "north";
        case 4: return "south";
    }
    return "UNKNOWN";
}


void Room::setExits(const char* direction, Room* neighbor) {//Set exits based on the key given from direction to code
  int dir = directionToCode(direction);
  if(dir!=-1) {
    exits[dir]=neighbor;
  }
}

Room* Room::getExits(const char* direction) {
  int dir = directionToCode(direction);//DirectionToCode
  if(dir != -1 && exits.count(dir)) {
    return exits[dir];//Returns the room that the key was mapped to
  }
  return nullptr;
}

char* Room::getDescription() {
  return description;
}

void Room::setDescription(const char* desc) {
  strcpy(description, desc);
}

void Room::setItem(const char* name, const char* desc) {//Creates an item and adds it to the list
  Items* item = new Items();
  item->setName(name);
  item->setDescription(desc);
  itemList5.push_back(item);
}

Items* Room::getItem(int numb) {
  return itemList5[numb];
}

void Room::setName(const char* inName) {
  strcpy(name, inName);
}

char* Room::getName() {
  return name;
}

Items* Room::findItem(char* Name) {//Iterates through the list
  for(auto it = itemList5.begin(); it!= itemList5.end();++it) {
    if(*it!=nullptr&&(*it)->getName()!=nullptr) {//Checks if it exists(I was having lots of issues with seg fault)
      if(strcmp((*it)->getName(),Name)==0) {//Checks if the name is equal
	  Items* found = *it;
	  itemList5.erase(it);//erases
	  return found;//returns the found Item
	}
      }
  }
  return(nullptr);
}

void Room::placeItem(Items* item) {
  itemList5.push_back(item);
}
void Room::printItems() {//Iterates through the items unless its empty because of cout
  if(itemList5.empty()!=true) {
    cout << "There is ";
    for(auto it = itemList5.begin(); it != itemList5.end(); ++it) {
      cout << (*it)->getName()<<" ";
    }
    cout << endl;
    cout << endl;
  }
}

void Room::printExits() {//Iterates through exits
    cout << "There are exits: ";

    for (auto it = exits.begin(); it != exits.end(); ++it) {
        cout << codeToDirection(it->first) << " ";
    }
    cout << endl;
    cout << endl;
}

int Room::getItemLength() {
  return itemList5.size();
}

void Room::printDesc() {
  cout << description << endl;
}
