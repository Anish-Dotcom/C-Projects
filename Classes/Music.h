#ifndef MUSIC
#define MUSIC

#include <iostream>
#include <cstring>
#include "Media.h"
  
using namespace std;

class Music : public Media {
   public:
  void print()const;
  ~Music();
    char* getArtist();
    float getDuration();
  void setArtist();
  void setDuration();
   protected:
  char artist[30];
  float duration;
};

#endif
