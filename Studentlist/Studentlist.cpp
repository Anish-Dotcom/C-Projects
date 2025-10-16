#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Student {
  char name[10];
  int id;
  float gpa;
};

int main() {
  vector<Student> Studentlist;
  Student George;
  strcpy (George.name, "George");
  George.id = 123213;
  George.gpa = 4.23;
  Studentlist[0] = George;
  cout << Studentlist[0] << endl;
  return 0;
}
