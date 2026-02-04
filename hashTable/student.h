#ifndef STUDENT
#define STUDENT

class Student{
 public:
  Student(char* fname, char* lname, int inId, float inGpa);
  char* getFirstName();
  char* getLastName();
  int getId();
  float getGpa();
 private:
  char firstName[20] = "Name";
  char lastName[20] = "Name";
  int id = 0;
  float gpa = 0;
};

#endif
