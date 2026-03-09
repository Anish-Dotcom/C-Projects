#include <iostream>
#include <cstring>
#include <cctype>
#include "node.h"
#include "binarytree.h"

using namespace std;

void push(node* &top, int num);
int pop(node* &top);
int peek(node* top);

void enqueue(node* &front, node* &back, int num);
int dequeue(node* &front);

void print(node* head);

char* shuntingyard(char* infix);

int main() {
  node* top = NULL;
  node* qfront = NULL;
  node* qback = NULL;
  treenode* head = NULL;
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
      print(qfront);
    } else if(strcmp(input, "peek") == 0) {
      cout << peek(top) << endl;
    } else if(strcmp(input, "enq") == 0) {
      int num;
      cin >> num;
      enqueue(qfront,qback,num);
    } else if(strcmp(input, "deq") == 0) {
      cout << dequeue(qfront) << endl;;
    } else if(strcmp(input, "quit") == 0){
      running = false;
    } else if(strcmp(input, "inf-post") == 0) {
      cout << "enter string" << endl;
      char input2[30];
      cin.ignore();
      cin.getline(input2,30);
      shuntingyard(input2);
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
  int num = front->getNum();
  node* temp = front;
  front = front->getNext();
  delete temp;
  return num;
}

void print(node* head) {
  node* current = head;
  while(current != NULL) {
    cout << current->getNum() << endl;
    current = current->getNext();
  }
}

char* shuntingyard(char* infix) {
  node* outputqueue = NULL;
  node* operatorstack = NULL;
  for(int i = 0; i < strlen(infix); i++) {
    if(isdigit(infix[i])) {
      push(outputqueue, infix[i]);
    }else if{
      
    }
  }
  return NULL;
}

bool isoperator() {
  
}
