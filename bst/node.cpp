#include <iostream>
#include "node.h"

using namespace std;

node::node(int input) {
  data = input;
}

int node::getData() {
  return data;
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
