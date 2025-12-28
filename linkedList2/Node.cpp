#include "Node.h"

Node::Node(Student* s) {
  student = s;
  next = NULL;
}

Node::~Node() {
  cout << "Deleted " << student->getFirstName() << endl;
  delete student;
  next = NULL;
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
