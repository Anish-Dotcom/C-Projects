/*
Auther: Anish Rao
Date: 12/29
Description: This code allows for the creation of a student list(not stored in files), the structure is a linked list. All methods use recursion to iterate through the list.
 */
#include <iostream>
#include <cstring>
#include <iomanip> 
#include "Node.h"

using namespace std;

void add(Node** list, Student* student);
void print(Node** list);
void remove();
uint32_t hashfunction(uint32_t k,int m);



int main() {
  Node** list = new Node*[100];
  cout << fixed <<setprecision(2); //Sets precision to two decimal places
  cout << "Type ADD, PRINT, DELETE, QUIT, or AVERAGE" << endl << endl;
  char input[10];
  bool running = true;
  cout << hashfunction(234242,100) << endl;
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
      add(list,student);
      
      cout << "Added " << student->getFirstName() << " " << student->getLastName() << endl;
    }
    else if (strcmp(input, "PRINT") == 0){
      print(list);
    }
    
    else if (strcmp(input, "DELETE") == 0) {
      cout << "Enter ID of student: ";
      int id = 0;
      cin >> id;
      remove();
    }

    else if ( strcmp(input, "QUIT") == 0) {
      running = false;
    }
  }
  return 0;
}

void add(Node** list, Student* student) {
  uint32_t i = hashfunction((uint32_t)student->getId(), sizeof(list));
  cout << i<< endl;
  Node* node = new Node(student);
  if(list[i]!=nullptr) {
    
  }
  list[i] = node;
}

void print(Node** list) {
  for(int i = 0; i < sizeof(list); i++) {
    if(list[i]!= nullptr) {
      cout << list[i]->getStudent()->getFirstName() << endl;
    }
  }
}

void remove() {
  
}

uint32_t hashfunction(uint32_t k, int m) {
  k = (k^(k>>16)) * 2654435761u;
  return k%m;
}
