#include <iostream>

using namespace std;

struct Student {
  char name[10];
  int id;
  float gpa;
};

int main() {
  Student george;
  cin >> george.name;
  george.gpa =3.0;
  cout << george.name << "ID:" << george.id << "GPA:";
  cout << george.gpa << endl;
  return 0;
}
