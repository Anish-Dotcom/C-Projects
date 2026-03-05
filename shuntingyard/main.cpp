#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void push(node* &top, int num);
int pop(node* &top);
int peek(node* top);

void enqueue(node* &front, node* &back, int num);
int dequque(node* &front);

void print(node* head);

int main() {
  node* top = NULL;
  node* qfront = NULL;
  node* qback = NULL;
  bool running = true;
  char input[10];
  while(running) {
    cin >> input;
    if(strcmp(input, "push") == 0) {
      int num;
      cin >> num;
      push(top, num);
    } else if(strcmp(input, "pop") == 0) {
      cout << pop(top) << endl;
    } else if(strcmp(input, "print") == 0) {
      print(qback);
    } else if(strcmp(input, "peek") == 0) {
      cout << peek(top) << endl;
    } else if(strcmp(input, "enq") == 0) {
      int num;
      cin >> num;
      enqueue(qfront,qback,num);
    } else if(strcmp(input, "deq") == 0) {
      dequeue(qfront);
    } else if(strcmp(input, "quit") == 0){
      running = false;
    } 
  }
}

void push(node* &top, int num) {
  node* newnode = new node(num);
  newnode->setNext(top);
  top = newnode;
}

int pop(node* &top) {
  if(top == NULL) {
    return -1;
  }
  int num = top->getNum();
  node* temp = top;
  top = top->getNext();
  delete temp;
  return num;
}

int peek(node* head) {
  return(head->getNum());
}

void enqueue(node* &front, node* &back, int num) {
  node* newnode = new node(num);
  if(front == NULL){
    front = newnode;
    back = newnode;
  } else {
    back->setNext(newnode);
    back = newnode;
  }
}

int dequeue(node* &front) {
  if(front == NULL) {
    return -1;
  }
  int num = front->getNum
  node* temp = front;
  delete temp;
}

void print(node* head) {
  node* current = head;
  while(current != NULL) {
    cout << current->getNum() << endl;
    current = current->getNext();
  }
}
