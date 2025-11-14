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
