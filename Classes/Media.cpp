#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;


int Media::getYear() {
  return year;
}

char* Media::getTitle() {
  return title;
}

Media::~Media() {
  cout << "Base media deleted" << endl;
}
