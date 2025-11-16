//The functions of Movies.h
#include <iostream>
#include <cstring>
#include "Movies.h"

using namespace std;

char* Movie::getDirector(){
  return director;
}

int Movie::getRating() {
  return rating;
}

void Movie::print() const  {//Overrides the parent print() with its own print
  cout <<"Title: "<< title<< ", Year: " << year<< ", Director: "<< director <<", Rating: "<< rating << endl;
}

Movie::~Movie() {
  cout << "Movie removed" << endl;
}

void Movie::setDirector() {//Consise code
  char setter[10];
  cout<<"Director: ";
  cin>>setter;
  strcpy(director, setter);
}

void Movie::setRating() {
  int setter;
  cout<<"Rating: ";
  cin>>setter;
  rating = setter;
}
