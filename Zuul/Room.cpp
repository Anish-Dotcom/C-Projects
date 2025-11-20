#include <iostream>
#include <cstring>
#include <map>
#include "Room.h"

using namespace std;

void Room::setExits(const char* direction, Room* neighbor) {
  exits.insert(pair<const char*,Room*>(direction, neighbor));
}

Room* Room::getExits() {
  return exits.at("East");
}

char* getDescription() {
  return description;
}
