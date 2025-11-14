#ifndef MUSIC
#define MUSIC

#include <iostream>
#include <cstring>
#include "Media.h"
  
using namespace std;

class Music : public Media {
   public:
    char* getArtist();
    float getDuration();
   protected:
    char artist[30] = "Microsoft";
    float duration = 9.19;
};

#endif
