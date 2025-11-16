//This is the movies header file
#ifndef MOVIES//Header guard is still necessary on children
#define MOVIES

#include <cstring>
#include "Media.h"

using namespace std;

class Movie : public Media {
 public:
  void print() const;//Uses the virtual function print()
  ~Movie();
  char * getDirector();
  int getRating();
  void setDirector();
  void setRating();
 protected:
  char director[20];//These are what NOT shared
  int rating = 10;
};
#endif
