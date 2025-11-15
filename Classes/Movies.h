#ifndef MOVIES
#define MOVIES

#include <cstring>
#include "Media.h"

using namespace std;

class Movie : public Media {
 public:
  void print() const;
  ~Movie();
  char * getDirector();
  int getRating();
  void setDirector();
  void setRating();
 protected:
  char director[20];
  int rating = 10;
};
#endif
