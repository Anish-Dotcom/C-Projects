#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Student {
  char name[10];
  int id;
  float gpa;
};

void add(vector<Student*>& Studentlist);


int main() {
  vector<Student*> Studentlist;
  Student George;
  strcpy (George.name, "George");
  George.id = 123213;
  George.gpa = 4.23;
  add(Studentlist);
  Student* s = Studentlist[0];
  cout<< s->id << endl;
  cout<< s->gpa << endl;
  return 0;
}
void add(vector<Student*>& Studentlist) {
  Student* s = new Student();
  (*s).id = 123123;
  (*s).gpa = 4.12;
  strcpy((*s).name, "Name");
  Studentlist.push_back(s);
}
