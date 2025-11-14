#include <iostream>
#include <cstring>
#include "VideoGames.h"
#include "Music.h"

using namespace std;

int main() {
  //  Media* media = new Media();
  //  cout << media->getYear() << endl;
  VideoGames* game = new VideoGames();
  cout << game->getPublisher() << endl;
  cout << game->getYear() << endl;
  cout << game->getTitle() << endl;
  cout << game->getRating() << endl;
  Music* music  = new Music();
  cout << music ->getArtist() << endl;
  cout << music->getYear() << endl;
  cout << music->getTitle() << endl;
  cout << music->getDuration() << endl;
}
