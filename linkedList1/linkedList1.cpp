#include <iostream>
#include <cstring>
#include "node.h"


using namespace std;

int main() {
  Student* first = new Student("Anish");
  Node* head = new Node(first);
  Student* second = new Student("Yupe");
  Node* node = new Node(second);
  head->setNext(node);
  cout << head->getNext()->getStudent()->getName() << endl;
  delete head;
  delete node;
  return 0;
}
