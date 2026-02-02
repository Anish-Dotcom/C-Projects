/*
Auther: Anish Rao
Date: 12/29
Description: This code allows for the creation of a student list(not stored in files), the structure is a linked list. All methods use recursion to iterate through the list.
 */
#include <iostream>
#include <cstring>
#include <iomanip> 
#include "student.h"

using namespace std;

void add();
void print();
void remove();
int hashfunction(int k,int m);

int main() {
  Student* list = new Student()[100];
  cout << fixed <<setprecision(2); //Sets precision to two decimal places
  cout << "Type ADD, PRINT, DELETE, QUIT, or AVERAGE" << endl << endl;
  char input[10];
  bool running = true;
  hashfunction(460470,100);
  while(running) {
    cin >> input;
    if(strcmp(input, "ADD") == 0) {
      char fname[20];
      char lname[20];
      int inId;
      float inGpa;

      cout << "First name: ";//User input is not in the function because of the recursion
      cin >> fname;
      cout << "Last name: ";
      cin >> lname;
      cout << "Id: ";
      cin >> inId;
      cout << "Gpa: ";
      cin >> inGpa;
  
      Student* student = new Student(fname,lname,inId,inGpa);//New student pointer based off inputs
      add();
      cout << "Added " << student->getFirstName() << " " << student->getLastName() << endl;
    }
    else if (strcmp(input, "PRINT") == 0){
      print();
    }
    
    else if (strcmp(input, "DELETE") == 0) {
      cout << "Enter ID of student: ";
      int id = 0;
      cin >> id;
      remove();
    }

    else if ( strcmp(input, "QUIT") == 0) {
      running = false;
    }
  }
  return 0;
}

void add() {
  
}

void print() {
}

void remove() {
}

int hashfunction(int k, int m) {
  k = (k^(k>>16)) * 2654435761u;
  return k%m;
}
