/*
  Auther: Anish rao
  Date: 3/13
  Desc: A script that implements the Shunting Yard Algorithm and Expression Trees, these allow the conversion from infix, prefix, and postfix notations of mathmatical equations.
*/
#include <iostream>
#include <cstring>
#include <cctype>
#include "node.h"
#include "binarytree.h"

using namespace std;
//Stack functions
void push(node* &top, char data);
char pop(node* &top);
char peek(node* top);
//Queue functions
void enqueue(node* &front, node* &back, char data);
char dequeue(node* &front);
//LLL functions
void print(node* head);
//Conversion functions
treenode* shuntingyard(char* infix);
treenode* expressiontree(node* inputqueue);
//Precidence(redundent)
bool isoperator(char input);
int precidence(char input);
//Printing expression tree
void infixprint(treenode* root);
void postfixprint(treenode* root);
void prefixprint(treenode* root);

int main() {
  bool running = true;
  char input[10];
  treenode* expressiontree = NULL;
  cout << "Commands: quit, input, infix, postfix, prefix" << endl;
  while(running) {//Command loop
    cin >> input;
    if(strcmp(input, "quit") == 0){
      running = false;
    } else if(strcmp(input, "input") == 0) {
      cout << "Enter equation in standard(infix) notation:" << endl;
      char input2[30];
      cin.ignore();
      cin.getline(input2,30);
      expressiontree = shuntingyard(input2);//Converts the infix into postfix into an expression tree
    } else if(strcmp(input, "infix")==0) {
      infixprint(expressiontree);
      cout << endl;
    } else if(strcmp(input, "postfix")==0) {
      postfixprint(expressiontree);
      cout << endl;
    } else if(strcmp(input, "prefix")==0) {
      prefixprint(expressiontree);
      cout << endl;
    }
  }
}

void push(node* &top, char input) {
  node* newnode = new node(input);
  newnode->setNext(top);//Makes a new head(top) of the stack LLL
  top = newnode;
}


char pop(node* &top) {
  if(top == NULL) {
    return -1;
  }
  char c = top->getData();//Deletes and returns the charecter
  node* temp = top;
  top = top->getNext();
  delete temp;
  return c;
}

void pushtree(node* &top, treenode* input) {//Same thing but using tree node pointers
  node* newnode = new node(0);
  newnode->setTree(input);
  newnode->setNext(top);
  top = newnode;
}

treenode* poptree(node* &top) {
  if(top == NULL) {
    return NULL;
  }
  treenode* c = top->getTree();
  node* temp = top;
  top = top->getNext();
  delete temp;
  return c;
}

char peek(node* head) {
  if(head==NULL) {
    return -1;
  }
  return(head->getData());//Returns the top node
}

void enqueue(node* &front, node* &back, char input) {//Passes a front and back pointer for efficiency
  node* newnode = new node(input);
  if(front == NULL){//If empty
    front = newnode;
    back = newnode;
  } else {//Otherwise add it to the back
    back->setNext(newnode);
    back = newnode;
  }
}

char dequeue(node* &front) {
  if(front == NULL) {
    return -1;
  }
  char c = front->getData();//Deletes the first node and returns the data
  node* temp = front;
  front = front->getNext();
  delete temp;
  return c;
}

void print(node* head) {
  node* current = head;
  while(current != NULL) {
    cout << current->getData() << ' ';//Iterates through LLL
    current = current->getNext();
  }
  cout << endl;
}

treenode* shuntingyard(char* infix) {
  node* outputqueuef = NULL;//Outputqueue for final expression
  node* outputqueueb = NULL;
  node* operatorstack = NULL;//Stack where operators temp stay
  int opsize = 0;//Tally of size
  for(int i = 0; i < strlen(infix); i++) {//Iterates through input
    if(isdigit(infix[i])) {//If its a number then add it to output
      enqueue(outputqueuef, outputqueueb, infix[i]);
    }else if(isoperator(infix[i])){//If operator
      while(opsize!=0 && precidence(infix[i]) <= precidence(peek(operatorstack))){//Iterate through until all operators of lower precidence to to output
          enqueue(outputqueuef,outputqueueb, pop(operatorstack));
          opsize--;
      }
      push(operatorstack, infix[i]);//Adds the current
      opsize++;
    }
  }
  while(opsize!= 0) {//At the end pop all operators into the queue
    enqueue(outputqueuef, outputqueueb, pop(operatorstack));
    opsize--;
  }
  print(outputqueuef);
  return expressiontree(outputqueuef);//Convert to expression tree and return
}
treenode* expressiontree(node* inputqueue) {
    node* current = inputqueue;
    node* treestack = NULL;
    
    while (current != NULL) {
        char data = current->getData();

        if (isdigit(data)) {
            treenode* newNode = new treenode(data);
            pushtree(treestack, newNode);
            current = current->getNext();

        } else if (isoperator(data)) {
            treenode* opNode = new treenode(data);
            treenode* right = poptree(treestack);
            treenode* left  = poptree(treestack);

            opNode->setright(right);
            opNode->setleft(left);
            
            pushtree(treestack, opNode);
            current = current->getNext();

        } else {
          current = current->getNext();
        }
    }
    treenode* root = poptree(treestack);
    delete treestack;
    return root;
}
bool isoperator(char input) {
  switch (input) {
  case '+':
    return true;
  case '-':
    return true;
  case '*':
    return true;
  case '/':
    return true;
  case '^':
    return true;
  }
  return false;
}

int precidence(char input) {
  switch (input) {
  case '+':
    return 1;
  case '-':
    return 1;
  case '*':
    return 2;
  case '/':
    return 2;
  case '^':
    return 3;
  }
  return 0;
}

void infixprint(treenode* root) {
  if(root==NULL) {
    return;
  }
  infixprint(root->getleft());
  cout << (char)root->getdata()<< ' ';
  infixprint(root->getright());
}
void prefixprint(treenode* root) {
  if(root==NULL) {
    return;
  }
  cout << (char)root->getdata()<< ' ';
  prefixprint(root->getleft());
  prefixprint(root->getright());
}
void postfixprint(treenode* root) {
  if(root==NULL) {
    return;
  }
  postfixprint(root->getleft());
  postfixprint(root->getright());
  cout << (char)root->getdata() << ' ';
}
