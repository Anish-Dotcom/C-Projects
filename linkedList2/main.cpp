#include <iostream>
#include <cstring>
#include <iomanip> 
#include "Node.h"

using namespace std;

void add(Node* current, Student* student);
void print(Node* current);
void remove(Node* &head ,Node* current, int id);

int main() {
  Node* head = NULL;
  cout << fixed <<setprecision(2);
  
  cout << "Type ADD, PRINT, DELETE, QUIT, AVERAGE" << endl << endl;;
  char input[10];
  bool running = true;
  
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
      if(head == NULL) {
	head = new Node(student);
      }else {
	add(head, student);
      }
      cout << "Added " << student->getFirstName() << " " << student->getLastName() << endl;
    }
    else if (strcmp(input, "PRINT") == 0){
      print(head);
    }
    
    else if (strcmp(input, "DELETE") == 0) {
      cout << "Enter ID of student: ";
      int id = 0;
      cin >> id;
      remove(head, head, id);
    }
  }
  return 0;
}

void add(Node* current, Student* student) {
  if(current == NULL) {//Base case if the recusion reaches the end of list
    cout << "Added: "<< student->getFirstName()<< " " << student->getLastName()<<", " << student->getId()<< ", "<<student->getGpa() << endl;
    current = new Node(student);//Makes a new node with the student at the end
    return;
  }
  add(current->getNext(), student);//Recursive step to the next node
}

void print(Node* current) {
  if(current == NULL) {//Base case if the recursion reaches the end
    return;
  }
  cout << current->getStudent()->getFirstName()<< " "
       << current->getStudent()->getLastName()<<", "
       << current->getStudent()->getId()<< ", "
       << current->getStudent()->getGpa() << endl;
  
  print(current->getNext());//Recursive step to the next node
}

void remove(Node* &head, Node* current, int id) {
  if(head == NULL) {//Empty list, this is first to prevent seg faults
    cout << "Empty List" << endl;
    return;
  }
  
  if(head->getStudent()->getId() == id) {//Head case where the first is it
    Node* temp = head;// Temp variable for old head
    head = head->getNext();//Head moves to the nexr
    cout << "Deleted: " << temp->getStudent()->getFirstName() << " " << temp->getStudent()->getLastName() << endl;
    delete temp;//Deletes the old head
    return;
  }
  
  if(current == NULL || current->getNext() == NULL) {//Base case if the recursion reaches the end of the list also prevents seg faults
    cout << "No match" << endl;
    return;
  }
  
  if(current->getNext()->getStudent()->getId() == id) {//Main case where the node is found
    Node* temp = current->getNext();//Temp variable for the found node
    current->setNext(temp->getNext());//Sets the current node's next to the node after the found one
    cout << "Deleted: " << temp->getStudent()->getFirstName() << " " << temp->getStudent()->getLastName() << endl;
    delete temp;//Deletes the found node
    return;
  }
  
  remove(head,current->getNext(),id); //Recursive steps to the next node if nothing happens
}
