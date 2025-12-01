#include <iostream>
#include <cstring>
#include <map>
#include "Room.h"

using namespace std;

void Room::setExits(char* direction, Room* neighbor) {
  if(strcmp(direction, "East") ==0){
    exits.insert({1, neighbor});
  } else if(strcmp(direction, "West") ==0){
    exits.insert({2, neighbor});
  }
}

Room* Room::getExits() {
  return exits[1];
}

char* Room::getDescription() {
  return description;
}

void Room::setDescription(char* desc) {
  strcpy(description, desc);
}
