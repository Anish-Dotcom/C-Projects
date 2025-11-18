#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

void Room::setExits(const char* direction, Room* neighbor) {
  exits->insert({direction,neighbor});
}
