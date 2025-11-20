//Comments are the same as Movies.h
#ifndef VIDEOGAMES
#define VIDEOGAMES

#include <iostream>
#include <cstring>
#include "Media.h"
  
using namespace std;

class VideoGames : public Media {
 public:
  void print() const;
  ~VideoGames();
     char* getPublisher();
    int getRating();
  void setPublisher();
  void setRating();
 protected:
    char publisher[30];
    int rating;
};

#endif
