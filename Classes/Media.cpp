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

void Media::setTitle() {
  char setter[10];
  cout<<"Title: ";
  cin>>setter;
  strcpy(title, setter);
}

void Media::setYear() {
  int setter;
  cout<<"Year: ";
  cin>>setter;
  year = setter;
}
