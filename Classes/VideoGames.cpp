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
  cout << title<< " " << year<< " "<< publisher <<" "<< rating << endl;
}
VideoGames::~VideoGames() {
  cout << "Videogames deleted" << endl;
}
