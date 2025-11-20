#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include "Room.h"

using namespace std;

int main() {
  Room* room = new Room();
  const char* direction ="East";
  Room* room2 = new Room();
  room->setExits(direction,room2);
  room->getExits()->getDescription();
  return 0;
}
