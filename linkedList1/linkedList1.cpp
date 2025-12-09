#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

int main() {
  Student* student = new Student();
  student->setName("Anish");
  cout << student->getName() << endl;
  delete student;
  return 0;
}
