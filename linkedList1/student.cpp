#include <cstring>
#include "student.h"

using namespace std;

void Student::setName(const char* input) {
  strcpy(name,input);
}

char* Student::getName() {
  return name;
}
