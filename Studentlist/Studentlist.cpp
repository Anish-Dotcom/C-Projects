/*
Auther : Anish
Date : 10/28/25
Desc : Script that allows for the creation of studentlsts(not stored after the code is done)
 */  
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Student {//Creates the studentlist struct type
  char firstname[10];
  char lastname[20];
  int id;
  float gpa;
};

void add(vector<Student*>& Studentlist);
void remove(vector<Student*>& Studentlist);
void printStudents(vector<Student*>& Studentlist);

int main() {
  vector<Student*> Studentlist;//Initializes a vector of struct pointers
  while(true) {
    char input[25];
    cout<< "ADD, DELETE, or QUIT: ";// Gets the input from the user
    cin.get(input, 7);
    cin.ignore();//Removes the newline charecter
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
void add(vector<Student*>& Studentlist) {
  Student* s = new Student();//Gets a new student pointer
  cout << "First name: ";
  char name[20];
  cin.get(name,20);
  strcpy(s->firstname, name);// Dereferences the student pointer and copies the name into it
  cin.ignore();
  cout << "Last name: ";	 
  cin.get(name, 20);
  strcpy(s->lastname, name);// Same thing for last name
  cin.ignore();
  cout<< "Type id: ";
  cin >> s->id;//Dereferences then copies the id
  cout << "Type GPA: ";
  cin >> s->gpa;//Deref then copies the gpa.
  cin.ignore();
  Studentlist.push_back(s);//Adds the new student pointer to vector
}

void remove(vector<Student*>& Studentlist) {
  int id =0;
  cout << "Id: ";
  cin >> id;//Gets an id
  cin.ignore();
  for(auto it = Studentlist.begin(); it != Studentlist.end();) { //Creates an iterator that starts on the first starts 
    if((*it)-> id == id) {//Dereferences the iterator then dereferences again to compare the id.
      delete *it;//Deletes the student pointer that the iterator was pointing to
      Studentlist.erase(it);//Removes the pointer from the vector
      break;
    }else {
      ++it;//Moves to the next student
    }
  }
}

void printStudents(vector<Student*>& Studentlist) {
  cout << endl;
  for(auto s = Studentlist.begin(); s != Studentlist.end();) {//Iterates through vector
    cout << (*s)->firstname << ' ' << (*s)->lastname << ", " << (*s)->id << ", " << (*s)->gpa << endl;//Dereferences the iterator and dereferences again to print the students parts
      s++;
  }
}
