#include <iostream>
#include "redBlackTree.h"
using namespace std;

redBlackTree::redBlackTree() {
  node* root = NULL;
}

void redBlackTree::insert(int data) {
  node* newnode = new node;
  newnode->data = data;
  if(root == NULL) {
    root = newnode;
    return;
  }
  insert(root, newnode, data);				 
}

void redBlackTree::insert(node* &current, node* newnode, int ndata) {
  if(current == NULL) {
    current = newnode;
    return;
  }
  if(ndata < current->data) {
    insert(current->left, newnode, ndata);
  } else {
    insert(current->right, newnode, ndata);
  }
}

void redBlackTree::print() {
  print(root, 0);
}

void redBlackTree::print(node* current, int depth) {
  if(current == NULL) return;
  print(current->right, depth+1);
  for(int i = 0; i < depth; i++) cout << "\t";
  cout << current->data << endl;
  print(current->left, depth+1);
}
