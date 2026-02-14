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

void add(Node** list, Student* student,int &total, int &tablesize);
void print(Node** list, int total, int tablesize);
void remove(Node** list, int id, int &total, int tablesize);
uint32_t hashfunction(uint32_t k,int m);
void addRandom(Node** list, int &total, int &tablesize);
void getNames(char firstNames[50][20], char lastNames[50][20]);
void rehash(Node** list, int total ,int &tablesize);

int main() {
  Node** list = new Node*[100]();
  for (int i = 0; i < 100; i++) {
    list[i] = nullptr;
  }
  cout << fixed <<setprecision(2); //Sets precision to two decimal places
  cout << "Commands: ADD  DELETE  RANDOM  PRINT  QUIT" << endl << endl;
  char input[10];
  bool running = true;
  int total = 0;
  int tablesize = 100;
  srand(time(0));
  while(running) {
    cin >> input;
    if(strcmp(input, "ADD") == 0) {
      char fname[20];
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
      add(list, student ,total, tablesize);
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
      for(int i = 0; i <inputInt; i++) {
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
  uint32_t i = hashfunction((uint32_t)(student->getId()), tablesize);
  Node* node = new Node(student);
  Node* current = list[i];
  
  if(current==nullptr) {
    list[i]=node;
    cout << student->getFirstName()  << " " << student->getLastName()  << " " << student->getId()  << " " << student->getGpa() << endl;
    return;
  }
  int collisions =0;
  
  while(current->getNext()!=nullptr){
    if(collisions == 2) {
      rehash(list, total, tablesize);
      cout << "Rehashed"<<tablesize<< endl;
    }
    current = current->getNext();
    collisions++;
  }
  current->setNext(node);
  total++;
  cout << student->getFirstName()  << " " << student->getLastName()  << " " << student->getId()  << " " << student->getGpa() << endl;
}

void print(Node** list, int total, int tablesize) {
  for(int i = 0; i < tablesize; i++) {
    Node* current = list[i];
    while(current!=nullptr) {
      cout << current->getStudent()->getFirstName() << " " << current->getStudent()->getLastName()  << endl;
      current = current->getNext();
    }
  }
}


void remove(Node** list, int id, int &total, int tablesize) {
  int i = hashfunction((uint32_t)(id), tablesize);
  Node* current =  list [i];
  Node* previous = nullptr;
  
  while(current!=nullptr){
    if(current->getStudent()->getId() == id) {
      if(previous==nullptr) {
        list[i] = current->getNext();
      } else {
        previous->setNext(current->getNext());
      }
      delete current;
      total--;
      return;
    }
    previous = current;
    current = current->getNext();
  }
  cout << "No student found" << endl;
}

uint32_t hashfunction(uint32_t k, int m) {
  k = (k^(k>>16)) * 2654435761u;
  return k%m;
}

void addRandom(Node** list, int &total, int &tablesize) {
  char firstNames[50][20];
  char lastNames[50][20];
  getNames(firstNames, lastNames);
  char fName[20];
  char lName[20];
  strcpy(fName, firstNames[rand() % 50]);
  strcpy(lName, lastNames[rand() % 50]);
  int id = total+1;
  float gpa = ((float)(rand())/(float)(RAND_MAX/4));
  Student* student = new Student(fName,lName,id,gpa);
  add(list, student , total, tablesize);
}

void getNames(char firstNames[50][20], char lastNames[50][20]) {
  ifstream MyReadFile("Names.txt");
  char input[20];
  for(int i = 0; i < 50; i++) {
    MyReadFile.getline(input,20);
    strcpy(firstNames[i], input);
  }
  for(int i = 0; i < 50; i++) {
    MyReadFile.getline(input,20);
    strcpy(lastNames[i], input);
  }
  MyReadFile.close();
}

void rehash(Node** list, int total, int &tablesize) {
  int oldsize = tablesize;
  tablesize *= 2;

  Node** newlist = new Node*[tablesize];

  for(int i = 0; i < tablesize; i++) {
    newlist[i] = NULL;
  }

  for(int i = 0; i < oldsize; i++) {
    Node* current = list[i];
    while(current != NULL) {
      Student* student = current->getStudent();
      uint32_t j = hashfunction(student->getId(), tablesize);

      Node* newNode = new Node(student);

      if(newlist[j] == NULL) {
        newlist[j] = newNode;
      } else {
        Node* temp = newlist[j];
        while(temp->getNext() != NULL) {
          temp = temp->getNext();
        }
        temp->setNext(newNode);
      }

      current = current->getNext();
    }
  }

  list = newlist;
}
 
