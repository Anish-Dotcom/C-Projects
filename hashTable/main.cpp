/*
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

void add(Node** list, Student* student, int &total);
void print(Node** list);
void remove(Node** list, int id, int &total);
uint32_t hashfunction(uint32_t k,int m);
void random(Node** list, int &total);
void getNames(char firstNames[50][20], char lastNames[50][20]);

int main() {
  Node** list = new Node*[100];
  cout << fixed <<setprecision(2); //Sets precision to two decimal places
  cout << "Commands: ADD  DELETE  RANDOM  PRINT  QUIT" << endl << endl;
  char input[10];
  bool running = true;
  int total = 0;
  srand(time(0));
  while(running) {
    cin >> input;
    if(strcmp(input, "ADD") == 0) {
      char fname[20];
      char lname[20];
      int inId;
      float inGpa;

      cout << "First name: ";
      cin >> fname;
      cout << "Last name: ";
      cin >> lname;
      cout << "Id: ";
      cin >> inId;
      cout << "Gpa: ";
      cin >> inGpa;
  
      Student* student = new Student(fname,lname,inId,inGpa);
      add(list, student, total);
      
      cout << "Added " << student->getFirstName() << " " << student->getLastName() << endl;
    }
    else if (strcmp(input, "PRINT") == 0){
      print(list);
    }
    
    else if (strcmp(input, "DELETE") == 0) {
      cout << "Enter ID of student: ";
      int id = 0;
      cin >> id;
      remove(list, id, total);
    }

    else if(strcmp(input, "RANDOM") == 0) {
      random(list, total);
    }
    
    else if ( strcmp(input, "QUIT") == 0) {
      running = false;
    }
  }
  return 0;
}

void add(Node** list, Student* student, int &total) {
  uint32_t i = hashfunction((uint32_t)student->getId(), sizeof(list));
  cout << i<< endl;
  Node* node = new Node(student);
    
  if(list[i]==NULL) {
    list[i] = node;
  }else if(list[i]->getNext() ==NULL){
    list[i]->setNext(node);
  } else if(list[i]->getNext()->getNext() == NULL) {
    list[i]->getNext()->setNext(node);
  } else {
    cout << "Three collisions" << endl;
  }
  total++;
}

void print(Node** list) {
  for(int i = 0; i < sizeof(list); i++) {
    if(list[i]!= NULL) {
      cout << list[i]->getStudent()->getFirstName() << endl;
      if(list[i]->getNext()!=NULL) {
	cout << list[i]->getNext()->getStudent()->getFirstName() << endl;
	if(list[i]->getNext()->getNext()!=NULL) {
	  cout << list[i]->getNext()->getNext()->getStudent()->getFirstName() << endl;
	}
      }
    }
  }
}

void remove(Node** list, int id, int &total) {
  int i = hashfunction((uint32_t)(id), sizeof(list));
  Node* current =  list [i];
  if(current==NULL){
    
  }
  /*
  for(int i = 0; i < sizeof(list); i++) {
    Node* current = list[i];
    while(current!=NULL) {
      if(current->getStudent()->getId()==id) {
	delete current;
	return;
      }else {
	current = current->getNext();
      }
    }
  }
  */
}

uint32_t hashfunction(uint32_t k, int m) {
  k = (k^(k>>16)) * 2654435761u;
  return k%m;
}

void random(Node** list, int &total) {
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
  add(list, student , total);
  cout << fName << lName << id << gpa << endl;
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
