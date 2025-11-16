//All function definitions for Media.h
#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

//print() is not defined because its a pure virtual and is useless for Media

int Media::getYear() {//Allows Classes.cpp to access these variables
  return year;
}

char* Media::getTitle() {
  return title;
}

Media::~Media() {//Empty function its only use is for children
}

void Media::setTitle() {//This is here to provide consise code
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
