#ifndef ITEMS
#define ITEMS
#include <iostream>
#include <cstring>

using namespace std;

class Items {
 public:
  char*  getDescription();
  char* getName();
  void  setDescription(const char* desc);
  void setName(const char* I);
 private:
  char name[20];
  char description[20];
};
#endif
