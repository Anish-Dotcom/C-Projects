#ifndef MEDIA
#define MEDIA

#include <iostream>
#include <cstring>

using namespace std;

class Media {
 public:
  int getYear();
  char* getTitle();
 private:
  int year = 2020;
  char title[20] = "Halo";
};

#endif
