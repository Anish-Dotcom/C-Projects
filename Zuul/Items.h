#ifndef ITEMS
#define ITEMS
#include <iostream>
#include <cstring>

using namespace std;

class Items {
public://Func prototypes
  char*  getDescription();
  char* getName();
  void  setDescription(const char* desc);
  void setName(const char* I);
private://variables
  char name[30];
  char description[60];
};
#endif
