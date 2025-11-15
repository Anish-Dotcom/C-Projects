#include <iostream>
#include <cstring>
#include <vector>
#include "VideoGames.h"
#include "Music.h"
#include "Movies.h"

using namespace std;
void add();

int main() {
  vector<Media*> Database;
  VideoGames* videogame = new VideoGames();
  Database.push_back(videogame);
  Database[0]->print();
}
