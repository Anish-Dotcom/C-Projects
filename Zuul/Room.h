#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class Room {
 public:
  void setExits(const char* direction, Room* neighbor);
 private:
  map<char*,Room*>* exits = new map<char*, Room*>();
};
