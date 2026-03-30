#ifndef NODE_H
#define NODE_H

#include <iostream> 

class node {
 public:
  node(int input);
  int getData();
  void setLeft(node* input);
  node* &getLeft();
  void setRight(node* input);
  node* &getRight();
 private:
  int data;
  node* left;
  node* right;
};

#endif
