//Comments are the same as Movies.cpp
#include <iostream>
#include <cstring>
#include "VideoGames.h"

using namespace std;

char* VideoGames::getPublisher() {
  return publisher;
}

int VideoGames::getRating() {
  return rating;
}
void VideoGames::print() const{
  cout <<"Title: "<< title<< ", Year: " << year<< ", Publisher: "<< publisher <<", Rating: "<< rating << endl;
}
VideoGames::~VideoGames() {
  cout << "Videogames removed" << endl;
}
void VideoGames::setPublisher() {
  char setter[10];
  cout<<"Publisher: ";
  cin>>setter;
  strcpy(publisher, setter);
}

void VideoGames::setRating() {
  int setter;
  cout<<"Rating: ";
  cin>>setter;
  rating = setter;
}

