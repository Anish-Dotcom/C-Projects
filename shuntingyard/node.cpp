#include <iostream>
#include "node.h"

node::node(int inum) {
  num = inum;
  next = NULL;
}
node::~node() { }
void node::setNext(node* node) {
  next = node;
}
node* node::getNext() {
  return next;
}
int node::getNum() {
  return num;
}
