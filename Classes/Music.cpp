#include<iostream>
#include<cstring>
#include "Music.h"

using namespace std;

char* Music::getArtist() {
  return artist;
}

float Music::getDuration() {
  return duration;
}

void Music::print() const {
   cout << title<< " " << year<< " "<< artist <<" "<< duration << endl;
}
Music::~Music() {
  cout<<"Music class deleted" << endl;
}
