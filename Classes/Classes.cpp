#include <iostream>
#include <cstring>
#include <vector>
#include "VideoGames.h"
#include "Music.h"
#include "Movies.h"

using namespace std;
void add(vector<Media*>& database);
void search(vector<Media*>& database);
void remove(vector<Media*>& database);

int main() {
  vector<Media*> Database;
  bool running = true;
  while(running) {
    cout <<"ADD, SEARCH, OR, DELETE";
    char input[10];
    cin>>input;
    if(strcmp(input, "ADD")==0){
	add(Database);
      }
    else if (strcmp(input, "SEARCH")==0) {
      search(Database);
    }
    else if(strcmp(input, "DELETE"==0) {
	remove(Database);
      }
    running = false;
  }
}

void add(vector<Media*>& database) {
  cout << "Type media kind: Music, Videogame, Movie: ";
  char input[10];
  cin >> input;
  cin.ignore();
  if(strcmp(input, "Music") ==0) {
    Music* music = new Music();
    music->setTitle();
    music->setYear();
    music->setArtist();
    music->setDuration();
    cout << "Added: ";
    music->print();
    database.push_back(music);
  }else if(strcmp(input, "Videogame") ==0) {
    VideoGames* videogame = new VideoGames();
    videogame->setTitle();
    videogame->setYear();
    videogame->setPublisher();
    videogame->setRating();
    cout << "Added: ";
    videogame->print();
    database.push_back(videogame);
  } else if(strcmp(input, "Movie") ==0) {
    Movie* movie = new Movie();
    movie->setTitle();
    movie->setYear();
    movie->setDirector();
    movie->setRating();
    cout << "Added: ";
    movie->print();
    database.push_back(movie);
  } else {
    cout<<"Type a valid input"<<endl;
  }
}
 void search(vector<Media*>& database){
   cout << "Search by year : ";
   char input[];
   cin >> input;
   
 }
 void remove(vector<Media*>& database){

 }
