#ifndef NODE
#define NODE
#include "student.h"

class Node {
 public:
  Node(Student*);
 private:
  Student* student = new Student();
};

#endif
