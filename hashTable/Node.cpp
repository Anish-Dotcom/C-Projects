#include "Node.h"

Node::Node(Student* s) {
  student = s;
  next = nullptr;
}

Node::~Node() {
  delete student;
  next = nullptr;
}

void Node::setNext(Node* n) {
  next = n;
}

Node* Node::getNext() {
  return next;
}

Student* Node::getStudent() {
  return student;
}
