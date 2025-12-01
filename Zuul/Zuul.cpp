#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include "Room.h"

using namespace std;

int main() {
  Room* room = new Room();
  char direction[10] ="East";
  Room* room2 = new Room();
  room->setExits(direction,room2);
  cout << room->getExits()->getDescription()<< endl;
  return 0;
}
