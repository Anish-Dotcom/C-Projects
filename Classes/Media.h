//The parent Media header file
#ifndef MEDIA//Header guard to prevent redefinition of Media since all children are Media
#define MEDIA

#include <iostream>
#include <cstring>

using namespace std;

class Media {
 public:
  int getYear();//Function prototypes
  char* getTitle();
  virtual void print() const = 0;
  /*Creates a virtual function that the children can change this is useful because the children can modify it but it can still be called as print(). const = 0 allows the function to be considered pure virtual, meaning that Media is never called, Media is never instantaited on its own so this makes sense.*/
  virtual ~Media() = 0;// The virtual destructor prevents a memory leak when the object is deleted
  void setTitle();
  void setYear();
 protected:
  int year = 2020;//These things are shared between all children so they are defined in the parent
  char title[20];
};

#endif
