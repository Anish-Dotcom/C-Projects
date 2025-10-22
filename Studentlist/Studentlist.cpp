#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Student {
  char firstname[10];
  char lastname[20];
  int id;
  float gpa;
};

void add(vector<Student*>& Studentlist);


int main() {
  vector<Student*> Studentlist;
  add(Studentlist);
  Student* s = Studentlist[0];
  cout << s->firstname << ' ' << s->lastname << ", " << s->id << ", " << s->gpa << endl;
  return 0;
}
void add(vector<Student*>& Studentlist) {
  Student* s = new Student();
  cout << "First name: ";
  char name[20];
  cin.get(name,20);
  strcpy(s->firstname, name);
  cin.ignore();
  cout << "Last name: ";	 
  cin.get(name, 20);
  strcpy(s->lastname, name);
  cin.ignore();
  cout<< "Type id: ";
  cin >> s->id;
  cout << "Type GPA: ";
  cin >> s->gpa;
  Studentlist.push_back(s);
}
