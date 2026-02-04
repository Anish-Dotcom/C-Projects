#include <cstring>
#include "student.h"

using namespace std;

Student::Student(char* fname, char* lname, int inId, float inGpa) {
  strcpy(firstName,fname);
  strcpy(lastName,lname);
  id = inId;
  gpa = inGpa;
}

char* Student::getFirstName() {
  return firstName;
}

char* Student::getLastName() {
  return lastName;
}

int Student::getId() {
  return id;
}
float Student::getGpa() {
  return gpa;
}
