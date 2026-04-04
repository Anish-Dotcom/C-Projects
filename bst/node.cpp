#include <iostream>
#include "node.h"

using namespace std;
//getters & setters
node::node(int input) {
  data = input;
  left = NULL;
  right = NULL;
}

int node::getData() {
  return data;
}

void node::setData(int value) {
  data = value;
}

void node::setLeft(node* input) {
  left = input;
}

node* &node::getLeft() {
  return left;
}

void node::setRight(node* input) {
  right = input;
}

node* &node::getRight() {
  return right;
}
