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
    root->color = 'b';
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
    newnode->parent = current;
    insert(current->left, newnode, ndata);
  } else {
    newnode->parent = current;
    insert(current->right, newnode, ndata);
  }
  insertfix(current);
}

void redBlackTree::print() {
  print(root, 0);
}

void redBlackTree::print(node* current, int depth) {
  if(current == NULL) return;
  print(current->right, depth+1);
  for(int i = 0; i < depth; i++) cout << "\t";
  cout << current->data << current->color << endl;
  print(current->left, depth+1);
}

node* sibling(node* current) {
  if(current == NULL || current->parent == NULL) return NULL;
  if(current == current->parent->left){
    return current->parent->right;
  } else {
    return current->parent->left;
  }
}
