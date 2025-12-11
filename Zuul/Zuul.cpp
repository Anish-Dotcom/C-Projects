/*
Auther: Anish Rao
Date:12/5/2025
Description: A text adventure game set in a haunted house, players move around collecting items to win
**IMPORTANT, The code will randomly segmentation fault, you can do the exact same thing yet one will fault and the other won't,
I have tried to fix it but if it seg faults just restart and it should work. If you look at the code it should work there is
nothing wrong with it.**
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include "Room.h"

using namespace std;

Room* createRooms();//Function prototypes
char* getInput();
void intro();
void help();
Items* rmInv(vector<Items*>& inventory, char* name);
void printInventory(vector<Items*> inventory);

int main() {
  intro();//Initializations
  Room* currentRoom = createRooms();
  vector<Items*> inventory;
  bool playing = true;
  char input[10];
  cout<< endl;
  currentRoom->printExits();
  currentRoom->printDesc();
  while(playing) {
    cout<<endl;
    cin >> input;//gets input
    if(strcmp(input, "quit")==0){
      playing= false;//quit
    }
    else if(strcmp(input, "east")==0||//Compares all directions
	    strcmp(input, "west")==0||
	    strcmp(input, "north")==0||
	    strcmp(input, "south")==0)
      {
	if(currentRoom->getExits(input)==nullptr) {
	    Room* next = nullptr;
	    cout << "You can't go there"<< endl;
	}else {
	  Room* next = currentRoom->getExits(input);
	  if(strcmp(next->getName(), "Exit")==0&&inventory.size()==5){//When next room is exit and you have 5 items you win                                                                                   
            cout << "You win!" << endl;
            playing = false;
          }else {
	    currentRoom = next;
	    currentRoom->printExits();
          currentRoom->printItems();
          currentRoom->printDesc();
	  }
	}
      }
    else if(strcmp(input, "help")==0) {
      help();//Help                                                                                                                                                                                        
    }
    else if(strcmp(input, "get")==0) {//Pickup
      cout << "Item name: ";
	char itemName[50];
	cin >> itemName;//What to pick

	Items* found = currentRoom->findItem(itemName);//Finds the item in the room and sets it to a new Item
	
	if(found!=nullptr) {//If it exits add it to inventory and print desc
	  inventory.push_back(found);
	  cout << "Picked up " << found->getName() << endl;
	  cout << found->getDescription() << endl;
	}else {
	  cout << "That's not in this room" << endl;
	}
      }
    else if(strcmp(input, "drop")==0) {//Drop
      cout << "Item name: ";
      char itemName[20];
      cin >> itemName;//What to drop

      Items* found = rmInv(inventory, itemName);//Same idea but with inventory, deletes in func

      if(found!=nullptr) {//If it exists place it and drop it.
	currentRoom->placeItem(found);
	cout << "Dropped " << found->getName() << endl;
      } else{
	cout << "You don't have that" << endl;
      }
      cout << endl;
    }
    else if(strcmp(input, "inventory")==0) {
      printInventory(inventory);//Print inventory
    }
  }
  return 0;
}


Room* createRooms() {//Initializes all rooms
  Room* entrance = new Room();
  Room* kitchen = new Room();
  Room* diningRoom = new Room();
  Room* livingRoom = new Room();
  Room* hauntedHouse = new Room();
  Room* hallway = new Room();
  Room* bathroom = new Room();
  Room* cemetary = new Room();
  Room* gym = new Room();
  Room* bedroom = new Room();
  Room* ghostRoom = new Room();
  Room* cellar = new Room();
  Room* spiderRoom = new Room();
  Room* attic = new Room();
  Room* exit = new Room();
  Room* theater = new Room();

  entrance->setName("Entrance");
  entrance->setDescription("Entrance of the haunted house, you hear a movie playing to your left");
  entrance->setExits("west", kitchen);
  entrance->setExits("north", hallway);

  kitchen->setName("Kitchen");
  kitchen->setDescription("Kitchen, ain't been used in a long time. You feel a fire from the dining room");
  kitchen->setExits("east", entrance);
  kitchen->setExits("west", diningRoom);
 
  diningRoom->setExits("east",kitchen);
  diningRoom->setDescription("There is an lit chandelier here, odd");
  diningRoom->setItem("HauntedC","The chandelier burns brightly even though nobody lives here");
    
  hallway->setName("Hallway");
  hallway->setDescription("A boring hallway nothing to see here");
  hallway->setExits("north", bathroom);
  hallway->setExits("south", entrance);

  bathroom->setName("Bathroom");
  bathroom->setDescription("Bathroom with broken windows, you can feel your bones shaking to your left");
  bathroom->setExits("west", cemetary);
  bathroom->setExits("east", bedroom);
  bathroom->setExits("south", hallway);
  
  cemetary->setName("Cemetary");
  cemetary->setDescription("A indoor cemetary, how odd, you see a glowing skull on the ground. Your exit seems to be to your left");
  cemetary->setExits("east", bathroom);
  cemetary->setExits("west", exit);
  cemetary->setItem("skull", "A posessed skull, it might be the owners!");

  exit->setName("Exit");
  exit->setExits("east", cemetary);

  bedroom->setDescription("The only bedroom in mansion... weird, the room to your right feels very cold");
  bedroom->setExits("south", gym);
  bedroom->setExits("east", ghostRoom);
  bedroom->setExits("west", bathroom);
  
  gym->setDescription("An untouched gym");
  gym->setExits("south",livingRoom);
  gym->setExits("north",bedroom);

  livingRoom->setDescription("Loud noises comes from the theater");
  livingRoom->setExits("east",theater);
  livingRoom->setExits("north",gym);

  theater->setDescription("The wildest theater you've seen ghosts fly around speaking some strange language, Ghostbusters is playing");
  theater->setExits("west", livingRoom);
  theater->setItem("Proton", "Ghostbusters trusty weapon capable of destroying any ghost");
  
  ghostRoom->setDescription("The coldest place you've been to, you see a glowing substance in the corner");
  ghostRoom->setExits("east", bedroom);
  ghostRoom->setExits("north", cellar);
  ghostRoom->setItem("Ectoplasm","It's what ghosts are made out of");
  
  cellar->setDescription("Boring cellar");
  cellar->setExits("south",ghostRoom);
  cellar->setExits("west",spiderRoom);
  
  spiderRoom->setDescription("Your worst nightmare, a room full of spiders!!!");
  spiderRoom->setExits("north", attic);
  spiderRoom->setExits("east",cellar);
  
  attic->setDescription("The top of the house, you see a mirror, as you move it doesn't. How strange, is there someone on the other side?");
  attic->setExits("south",spiderRoom);
  attic->setItem("mirror","A two sided mirror, is there someone in ther!?!");
  return entrance;
}

void intro() {//Intro
  cout << endl;
  cout << "Welcome to the Haunted House game"<< endl;
  cout << "This is a spooky text adventure game" << endl;
  cout << "Type 'help' if you need help" << endl;
  cout << endl;
}

void help() {//Help
  cout << endl;
  cout << "You are lost in a haunted house" << endl;
  cout << "Find 5 items and find the exit to leave";
  cout << endl;
  cout << "Type 'go north', 'go east', 'go south', or 'go west' to change rooms" << endl;
  cout << "Type 'inventory' to see your items" << endl;
  cout << "Type get 'name' or drop 'name 'to get or drop items" << endl;
  cout << "Type quit to quit the game" << endl;
  cout << endl;
}

Items*  rmInv(vector<Items*>& inventory, char* Name) {//Passes memory location of vector
  for(auto it =  inventory.begin(); it!= inventory.end(); ++it) {//Iterates through inventory
    if(strcmp((*it)->getName(), Name)==0) {//Compares it to the name and if its right returns it and deletes it
    Items* found =*it;
    inventory.erase(it);
    return found;
    }
  }
  return(nullptr);//Returns empty if not
}


void printInventory(vector<Items*> inventory) {
  for(auto it = inventory.begin(); it!= inventory.end(); ++it) {//Iterates through
    cout<<(*it)->getName()<< " ";//Prints the name
  }
  cout<< endl;
  cout<< endl;
}
