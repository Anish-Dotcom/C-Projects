#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include "Room.h"

using namespace std;

void createRooms();

int main() {
  createRooms();
  Room* currentRoom;

  bool playing = true;
  while(playing) {
    
  }
  return 0;
}

void createRooms() {
  Room* entrance = new Room();
  Room* kitchen = new Room();
  Room* diningRoom = new Room();
  Room* livingRoom = new Room();
  Room* hauntedHouse = new Room();
  Room* hallway = new Room();
  Room* hallway2 = new Room();
  Room* cemetary = new Room();
  Room* gym = new Room();
  Room* bedroom = new Room();
  Room* ghostRoom = new Room();
  Room* cellar = new Room();
  Room* spiderRoom = new Room();
  Room* attic = new Room();
  Room* exit = new Room();
  
  entrance->setName("Name");
  entrance->setDescription("Entrance of the haunted house, you hear a movie playing to your west");
  entrance->setExits("west", kitchen);
  entrance->setExits("north", hallway);
  entrance->setExits("east", livingRoom);
}
