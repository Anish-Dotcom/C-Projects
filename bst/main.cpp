#include <iostream>
#include <cstring>
#include <fstream>
#include "node.h"

using namespace std;

void add(node* &current, int data);
void print(node* current, int depth);
int main() {
  node* root = NULL;
  /*
  add(root, 9);
  add(root, 8);
  add(root, 10);
  cout << root->getData() << endl;
  cout << root->getLeft()->getData() << endl;
  cout << root->getRight()->getData() << endl;
  */
  char input[20];
  cout << "Type file or console: ";
  cin >> input;
  if(strcmp(input, "file") == 0) {
    //cout << "Filename: ";
    //cin >> input;
    ifstream file("numbers.txt");
    int num;
    while(file >> num) {
      add(root, num);
    }
    file.close();
  }
  print(root);
  //cout << root->getData() << endl;
  //cout << root->getLeft()->getData() << endl;
  //cout << root->getRight()->getData() << endl;
  return 0;
}

void add(node* &current, int data) {
  if(current == NULL) {
    current = new node(data);
    return;
  }
  if(data < current->getData()) {
    add(current->getLeft(), data);
  } else {
    add(current->getRight(), data);
  }
}

void print(node* current, int depth) {
  if(current == NULL) {
    return;
  }
  print(current->getLeft());
  cout << current->getData() << " ";
  print(current->getRight());
}
