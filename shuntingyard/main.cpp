#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void push(node* &head, int num);
void print(node* head);

int main() {
  node* stackhead = NULL;

  bool running = true;
  char input[10];
  while(running) {
    cin >> input;
    if(strcmp(input, "add") == 0) {
      int num;
      cin >> num;
      push(stackhead, num);
    } else if(strcmp(input, "QUIT") == 0){
      running = false;
    }
    print(stackhead);
  }
}

void push(node* &head, int num) {
  node* input = new node(num);
  if(head==NULL) {
    head = input;
    return;
  }
  
}

void print(node* head) {
  node* current = head;
  if(current != NULL) {
    cout << current->getNum() << endl;
  }
}
