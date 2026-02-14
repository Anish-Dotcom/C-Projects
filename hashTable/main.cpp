/*AA
Auther: Anish Rao
Date: 12/29
Description: This code allows for the creation of a student list(not stored in files), the structure is a linked list. All methods use recursion to iterate through the list.
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip> 
#include "Node.h"

using namespace std;
//Protoypes, total and tablesize are passed by ref for some functions
void add(Node** list, Student* student,int &total, int &tablesize);
void print(Node** list, int total, int tablesize);
void remove(Node** list, int id, int &total, int tablesize);
uint32_t hashfunction(uint32_t k,int m);
void addRandom(Node** list, int &total, int &tablesize);
void getNames(char firstNames[50][20], char lastNames[50][20]);
//void rehash(Node** list, int total ,int &tablesize);

int main() {
  Node** list = new Node*[100]();//Creates the table of linked lists
  cout << fixed <<setprecision(2); //Sets precision to two decimal places
  cout << "Commands: ADD  DELETE  RANDOM  PRINT  QUIT" << endl << endl;
  char input[10];
  bool running = true;
  int total = 0;//Total students
  int tablesize = 100;//Tablesize for rehashing
  srand(time(0));//Seeds the random number generator
  while(running) {
    cin >> input;
    if(strcmp(input, "ADD") == 0) {
      char fname[20];//Student inputs
      char lname[20];
      int id;
      float gpa;
      
      cout << "First name: ";
      cin >> fname;
      cout << "Last name: ";
      cin >> lname;
      cout << "Id: ";
      cin >> id;
      cout << "Gpa: ";
      cin >> gpa;
  
      Student* student = new Student(fname,lname, id, gpa);
      add(list, student ,total, tablesize);//Adds
    }
    else if (strcmp(input, "PRINT") == 0){
      print(list, total, tablesize);
    }
    
    else if (strcmp(input, "DELETE") == 0) {
      cout << "Enter ID of student: ";
      int id = 0;
      cin >> id;
      remove(list, id, total, tablesize);
    }

    else if(strcmp(input, "RANDOM") == 0) {
      cout << "Number of students: ";
      int inputInt;
      cin >> inputInt;
      for(int i = 0; i <inputInt; i++) {//Creates a random students with the amount based on input
        addRandom(list, total, tablesize);
      }
    }
    
    else if ( strcmp(input, "QUIT") == 0) {
      running = false;
    }
  }
  return 0;
}

void add(Node** list, Student* student, int &total, int &tablesize) {
  uint32_t i = hashfunction((uint32_t)(student->getId()), tablesize);//Gets index from hashfunction
  Node* node = new Node(student);
  Node* current = list[i];
  
  if(current==nullptr) {//If the index is empty
    list[i]=node;//Set that index to node
    total++;
    cout << student->getFirstName()  << " " << student->getLastName()  << " " << student->getId()  << " " << student->getGpa() << endl;
    return;
  }
  int collisions = 0;
  
  while(current->getNext()!=nullptr){//Iterate untill the last node
    if(collisions == 2) {//If there have been three collisions rehash it
      //    rehash(list, total, tablesize);
      //      cout << "Rehashed"<<tablesize<< endl;
    }
    current = current->getNext();//Otherwise iterate
    collisions++;
  }
  current->setNext(node);//Adds the
  total++;
  cout << student->getFirstName()  << " " << student->getLastName()  << " " << student->getId()  << " " << student->getGpa() << endl;
}

void print(Node** list, int total, int tablesize) {
  for(int i = 0; i < tablesize; i++) {//Iterates through all items
    Node* current = list[i];
    while(current!=nullptr) {//Iterates through linked list
      cout << current->getStudent()->getFirstName() << " " << current->getStudent()->getLastName()  << endl;
      current = current->getNext();
    }
  }
}


void remove(Node** list, int id, int &total, int tablesize) {
  int i = hashfunction((uint32_t)(id), tablesize);//Hashfunctions the given id to find the index to delete
  Node* current =  list [i];
  Node* previous = nullptr;
  
  while(current!=nullptr){//Iterates through the linked list
    if(current->getStudent()->getId() == id) {//If it finds the student in linked list then delete
      if(previous==nullptr) {//If its the first node then just set the first to the second
        list[i] = current->getNext();
      } else {
        previous->setNext(current->getNext());//Otherwise set the previous to the next
      }
      delete current;//Deletes the node
      total--;
      return;
    }
    previous = current;//Iterates through
    current = current->getNext();
  }
  cout << "No student found" << endl;//If nothing is found
}

uint32_t hashfunction(uint32_t k, int m) {//Hashfunction taken from stackoverflow
  k = (k^(k>>16)) * 2654435761u;
  return k%m;
}

void addRandom(Node** list, int &total, int &tablesize) {
  char firstNames[50][20];
  char lastNames[50][20];
  getNames(firstNames, lastNames);//Gets the array of names
  char fName[20];
  char lName[20];
  strcpy(fName, firstNames[rand() % 50]);//Sets the name to a random index from the array
  strcpy(lName, lastNames[rand() % 50]);
  int id = total+1;//Sets the id to the total plus one
  float gpa = ((float)(rand())/(float)(RAND_MAX/4));//Gets a random float 0-4
  Student* student = new Student(fName,lName,id,gpa);
  add(list, student , total, tablesize);//Adds random
}

void getNames(char firstNames[50][20], char lastNames[50][20]) {
  ifstream MyReadFile("Names.txt");//Gets the names file
  char input[20];
  for(int i = 0; i < 50; i++) {
    MyReadFile.getline(input,20);//Reads it and puts into input
    strcpy(firstNames[i], input);//Adds the name into the array
  }
  for(int i = 0; i < 50; i++) {
    MyReadFile.getline(input,20);
    strcpy(lastNames[i], input);
  }
  MyReadFile.close();
}
/*
void rehash(Node** list, int total, int &tablesize) {
  int oldsize = tablesize;
  tablesize *= 2;//Doubles size

  Node** newlist = new Node*[tablesize];//Makes a new table

  for(int i = 0; i < tablesize; i++) {
    newlist[i] = NULL;//Sets the tables indexes to NULL
  }

  for(int i = 0; i < oldsize; i++) {//Iterates through the oldsize and puts every node into the new one
    Node* current = list[i];
    while(current != NULL) {
      Student* student = current->getStudent();
      uint32_t j = hashfunction(student->getId(), tablesize);//Gets a new index

      Node* newNode = new Node(student);
      
      if(newlist[j] == NULL) {
        newlist[j] = newNode;
      } else {
        Node* temp = newlist[j];//Temp node at the index
        while(temp->getNext() != NULL) {//Iterates through end
          temp = temp->getNext();
        }
        temp->setNext(newNode);//Sets the next final node the new node.
      }

      current = current->getNext();//Otherwise iterate
    }
  }

  list = newlist;//Makes the old list the new.
}
*/
