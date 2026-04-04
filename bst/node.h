#ifndef NODE_H
#define NODE_H

#include <iostream> 

class node {
public://getters and setters
  node(int input);
  int getData();
  void setData(int value);
  void setLeft(node* input);
  node* &getLeft();
  void setRight(node* input);
  node* &getRight();
private://values
  int data;
  node* left;
  node* right;
};

#endif
