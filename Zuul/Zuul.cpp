#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include "Room.h"

using namespace std;

Room* createRooms();
char* getInput();
void intro();
void help();

int main() {
  intro();
  Room* currentRoom = createRooms();
  vector<Items*> inventory;
  bool playing = true;
  char input[10];
  while(playing) {
    cin >> input;
    if(strcmp(input, "quit")==0){
      playing= false;
    }
    else if(strcmp(input, "east")==0||
	    strcmp(input, "west")==0||
	    strcmp(input, "north")==0||
	    strcmp(input, "south")==0)
      {
	Room* next = currentRoom->getExits(input);
	if(next!=nullptr) {
	  currentRoom = next;
	} else {
	  cout << "You can't go there"<< endl;
	}
      }
    else if(strcmp(input, "help")==0) {
	help();
      }
    else if(strcmp(input, "get")==0) {
	cout << "Item name: ";
	char itemName[50];
	cin >> itemName;

	Items* found = currentRoom->findItem(itemName);
	
	if(found!=nullptr) {
	  cout << "nullptr" << endl;
	  inventory.push_back(found);
	  cout << "Picked up " << found->getName() << endl;
	}else {
	  cout << "That's not in this room" << endl;
	}
      }
  }
  return 0;
}


Room* createRooms() {
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
  
  entrance->setName("Entrance");
  kitchen->setName("Kitchen");
  hallway->setName("Hallway");
  livingRoom->setName("Living Room");
  entrance->setDescription("Entrance of the haunted house, you hear a movie playing to your west");
  entrance->setExits("west", kitchen);
  entrance->setExits("north", hallway);
  entrance->setExits("east", livingRoom);

  return entrance;
}

void intro() {
  cout << endl;
  cout << "Welcome to the Haunted House game"<< endl;
  cout << "This is a spooky text adventure game" << endl;
  cout << "Type 'help' if you need help" << endl;
  cout << endl;
}

void help() {
  cout << endl;
  cout << "You are lost in a haunted house" << endl;
  cout << "Find 5 items and find the exit to leave";
  cout << endl;
  cout << "Type 'north', 'east', 'south', or 'west' to change rooms" << endl;
  cout << "Type 'inventory' to see your items" << endl;
  cout << "Type get 'name' or drop 'name 'to get or drop items" << endl;
  cout << "Type quit to quit the game" << endl;
  cout << endl;
}




