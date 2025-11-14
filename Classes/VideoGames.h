#ifndef VIDEOGAMES
#define VIDEOGAMES

#include <iostream>
#include <cstring>
#include "Media.h"
  
using namespace std;

class VideoGames : public Media {
 public:
     char* getPublisher();
    int getRating();
 protected:
    char title[20] = "Halo";
    char publisher[30] = "Microsoft";
    int rating = 9;
};

#endif
