/*
Auther : Anish
Date : 10/28/25
Desc : 
 */  
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
void remove(vector<Student*>& Studentlist);
void printStudents(vector<Student*>& Studentlist);

int main() {
  Student* Studentlist[100];
  while(true) {
    char input[25];
    cout<< "ADD, DELETE, or QUIT: ";
    cin.get(input, 7);
    cin.ignore();
    if(strcmp (input, "ADD") ==0) {
      add(Studentlist);
      printStudents(Studentlist);
    } else if(strcmp (input, "DELETE") ==0) {
      remove(Studentlist);
      printStudents(Studentlist);
    } else if(strcmp(input, "QUIT") ==0 ){
	break;
      }
    cout << endl;
  }
  return 0;
}
void add(Student* (&Studentlist)[]) {
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
  cin.ignore();
  Studentlist.push_back(s);
}

void remove(vector<Student*>& Studentlist) {
  int id =0;
  cout << "Id: ";
  cin >> id;
  cin.ignore();
  for(auto it = Studentlist.begin(); it != Studentlist.end();) { 
    if((*it)-> id == id) {
      delete *it;
      Studentlist.erase(it);
      break;
    }else {
      ++it;
    }
  }
}

void printStudents(vector<Student*>& Studentlist) {
  cout << endl;
  for(auto s = Studentlist.begin(); s != Studentlist.end();) {
    cout << (*s)->firstname << ' ' << (*s)->lastname << ", " << (*s)->id << ", " << (*s)->gpa << endl;
      s++;
  }
}
