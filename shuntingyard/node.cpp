#include <iostream>
#include "node.h"
//Getters, setters, and constructors
node::node(char input) {
  data = input;
  next = NULL;
  tree = NULL;
}
node::~node() {
  delete tree;//Tree deletion
}
void node::setNext(node* node) {
  next = node;
}
node* node::getNext() {
  return next;
}
char node::getData() {
  return data;
}
treenode* node::getTree() {
  return tree;
}
void node::setTree(treenode* itree) {
  tree = itree;
}
