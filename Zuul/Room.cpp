#include <iostream>
#include <cstring>
#include <map>
#include "Room.h"

using namespace std;

static int directionToCode(const char* direction) {
    if (strcasecmp(direction, "east") == 0)  return 1;
    if (strcasecmp(direction, "west") == 0)  return 2;
    if (strcasecmp(direction, "north") == 0) return 3;
    if (strcasecmp(direction, "south") == 0) return 4;
    return -1;
}

void Room::setExits(const char* direction, Room* neighbor) {
  int dir = directionToCode(direction);
  if(dir!=-1) {
    exits[dir]=neighbor;
  }
}

Room* Room::getExits(const char* direction) {
  int dir = directionToCode(direction);
  if(dir != -1 && exits.count(dir)) {
    return exits[dir];
  }
  return nullptr;
}

char* Room::getDescription() {
  return description;
}

void Room::setDescription(const char* desc) {
  strcpy(description, desc);
}

void Room::setItem(const char* name) {
  
}
