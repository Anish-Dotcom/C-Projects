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

void Movie::print() const  {
  cout << title<< " " << year<< " "<< director <<" "<< rating << endl;
}

Movie::~Movie() {
  cout << "Movie destructor called" << endl;
}

void Movie::setDirector() {
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
