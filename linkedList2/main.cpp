#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void add(Node* &head);
void print(Node* &head ,Node* next);
void remove(Node* &head ,Node* next, int id);

int main() {
  Node* head = NULL;
  cout << "Type ADD, PRINT, DELETE, QUIT, AVERAGE" << endl << endl;;
  char input[10];
  bool running = true;
  while(running) {
    cin >> input;
    if(strcmp(input, "ADD") == 0) {
      add(head);
    }else if (strcmp(input, "PRINT") == 0){
      print(head, head);
    }else if (strcmp(input, "DELETE") == 0) {
      cout << "Enter ID of student: ";
      int id = 0;
      cin >> id;
      remove(head, head, id);
    }
  }
  return 0;
}

void add(Node* &head) {
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
  cout << "Added: "<< student->getFirstName()<< " " << student->getLastName()<<", " << student->getId()<< ", "<<student->getGpa() << endl;
  Node* current = head;
  if(current == NULL) {
    head = new Node(student);
  }
  else {
    while(current->getNext() != NULL) {
      current = current->getNext();
    }
    current->setNext(new Node(student));
  }
}

void print(Node* &head, Node* next) {
  if(next!=NULL) {
    cout << next->getStudent()->getFirstName()<< " " << next->getStudent()->getLastName()<<", " <<
      next->getStudent()->getId()<< ", "<< next->getStudent()->getGpa() << endl;
    print(head,next->getNext());
  }
}

void remove(Node* &head, Node* next, int id) {
  if(head == NULL) {
      cout << "Empty List" << endl;
  }else{
    if(next->getStudent()->getId() == id) {
      cout << "Match"<< endl;
    } else {
      cout << "No Match" << endl;
      if(next->getNext() != NULL) {
	cout <<"Next is not NULL" << endl;
	remove(head,next->getNext(),id);
      }
    }
  }
}
