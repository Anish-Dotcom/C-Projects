#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include "Room.h"

using namespace std;

int main() {
  Room* room = new Room();
  Room* room2 = new Room();
  room->setExits("East",room2);
  cout << room->getExits("East")->setDescription()<< endl;
  return 0;
}
