#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include "Room.h"

using namespace std;

int main() {
  Room* room = new Room();
  Room* room2 = new Room();
  room2->setDescription("Yes");
  room->setExits("East",room2);
  room->setItem("Ping","very good");
  
  cout << room->getExits("East")->getDescription()<< endl;
  return 0;
}
