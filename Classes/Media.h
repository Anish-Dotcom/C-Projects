#ifndef MEDIA
#define MEDIA

#include <iostream>
#include <cstring>

using namespace std;

class Media {
 public:
  int getYear();
  char* getTitle();
  virtual void print() const = 0;
  virtual ~Media() = 0;
  void setTitle();
  void setYear();
 protected:
  int year = 2020;
  char title[20];
};

#endif
