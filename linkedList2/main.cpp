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

void add(Node* &head, Node* current, Node* next, Student* student);
void print(Node* current);
void remove(Node* &head, Node* current, int id);
void average(Node* current, float total, int tally);

int main() {
  Node* head = NULL;//Sets first node to NULL head is NULL when list is empty
  cout << fixed <<setprecision(2); //Sets precision to two decimal places
  
  cout << "Type ADD, PRINT, DELETE, QUIT, or AVERAGE" << endl << endl;;
  char input[10];
  bool running = true;
  
  while(running) {
    cin >> input;
    if(strcmp(input, "ADD") == 0) {
      char fname[20];
      char lname[20];
      int inId;
      float inGpa;

      cout << "First name: ";//User input is not in the function because of the recursion
      cin >> fname;
      cout << "Last name: ";
      cin >> lname;
      cout << "Id: ";
      cin >> inId;
      cout << "Gpa: ";
      cin >> inGpa;
  
      Student* student = new Student(fname,lname,inId,inGpa);//New student pointer based off inputs
      add(head, head, head,student);
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

    else if ( strcmp(input, "QUIT") == 0) {
      running = false;
    }

    else if( strcmp(input, "AVERAGE")==0) {
      average(head,0,0);
    }
  }
  return 0;
}

void add(Node* &head, Node* current, Node* next ,Student* student) {
  if(head == NULL) {//If the list is empty set the head to it.
    head =  new Node(student);
    return;
  }
  
  if(student->getId() < head->getStudent()->getId()) {//If the new students gpa is less than the head set the new student to the new head
    Node* temp = head;//Saves the old head
    head = new Node(student);//New head
    head->setNext(temp);//New head next is set to old head
    return;
  }

  if(next == NULL) {//Base case if the recursion reaches the end meaning that the new student is the biggest
    current->setNext(new Node(student));
    return;
  }

  if(student->getId() < next->getStudent()->getId()) {//If the new student has a smaller gpa then the next then the next make a new node in between
    current->setNext(new Node(student));//Current node next is the new node
    current->getNext()->setNext(next);//Makes the new node point to the next node
    return;
  }
  
  add(head, next, next->getNext(), student);//Recursive step to the next node
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

void average(Node* current, float total, int tally) {
  if(current == NULL) {//Base case of recursion
    if(tally!=0){//Prevents div by 0 error
      cout <<total/tally<< endl;
    }
    else{
      cout << "No students in list" << endl;
    }
    return;
  }

  total += current->getStudent()->getGpa();//Adds the current gpa to the total
  tally++;//Increases the tally
  
  average(current->getNext(), total, tally);//Recursive step passing the next node and current numbs
}
