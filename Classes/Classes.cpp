/*
Auther: Anish Rao
Date: 11/15/2025
Description: Code that allows for the creation of a media database(Not stored after running). The database contains Music, Videogames,
and Music. You are able to add, search, and delete from this database.
 */

#include <iostream>
#include <cstring>
#include <vector>
#include "VideoGames.h"//Links the header files
#include "Music.h"
#include "Movies.h"

using namespace std;
void add(vector<Media*>& database);//Function prototypes
void search(vector<Media*>& database);
void remove(vector<Media*>& database);

int main() {
  vector<Media*> Database;//Initializes a vector of Media parent pointers, the children are able to be added to this vector because of inheritance
  bool running = true;
  while(running) {
    cout <<"Add, Search, Delete, or Quit: ";//Asks what the user wants to do
    char input[10];
    cin>>input;
    if(strcmp(input, "Add")==0){
	add(Database);
    }
    else if (strcmp(input, "Search")==0) {
      search(Database);
    }
    else if(strcmp(input, "Delete")==0) {
      remove(Database);
    }
    else if(strcmp(input, "Quit")==0) {
      running = false;
    }else{
      cout << "Type a valid input" << endl;
   }
  }
}

void add(vector<Media*>& database) {//Adding function
  cout << "Type media kind: Music, Videogame, Movie: ";//Gets what type the user wants to add
  char input[10];
  cin >> input;
  cin.ignore();
  if(strcmp(input, "Music") ==0) {
    Music* music = new Music();//Allocates heap memory to the new variable
    music->setTitle();//Uses the inherited setTitle function to change the title, music inherits all methods of media  so this works 
    music->setYear();
    music->setArtist();//Sets artist using functions that the child has
    music->setDuration();
    cout << "Added: ";
    music->print();
    database.push_back(music);//Adds Music to the database
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
  cout << "Search by Title or Year: ";//Checks for title or year
   char input[10];
   cin >> input;
   if(strcmp(input, "Title") == 0 ){
     char title[20];
     cout << "Title: ";
     cin >> title;
     for(auto it = database.begin(); it != database.end(); ++it) {//Iterates through the database
       if(strcmp((*it)->getTitle(), title)==0) {
	 (*it)->print();//Prints if it input is equal to the title
       }
     }
   }else if(strcmp(input, "Year")==0) {
     int year;
     cout <<"Year: ";
     cin >> year;
     for(auto it = database.begin(); it != database.end(); ++it) {
       if((*it)->getYear() == year) {
	 (*it)->print();
       }
     }
   } else{
     cout << "Type a valid input" << endl;
   }
 }
 void remove(vector<Media*>& database){
   bool removed = false;
   cout << "Delete by Title or Year: ";
   char input[10];
   cin >> input;
   if(strcmp(input, "Title") == 0 ){
     char title[20];
     cout << "Title: ";
     cin >> title;
     for(auto it = database.begin(); it != database.end();) {//iterates through the database
       if(strcmp((*it)->getTitle(), title)==0&&removed == false) {
         char confirm;
	 cout<< "Confirm y/n:";//Confirms
	 cin>> confirm;
	 if(confirm == 'y') {
	   delete *it;//Deallocates the heap memory
	   it = database.erase(it);//Importantly sets the iterator to the next iterator so there is still a valid iterator
	   removed = true;
	 }else{
	   ++it;
	 }
       }else{
	 ++it;
       }
     }
   }else if(strcmp(input, "Year")==0) {
     int year;
     cout <<"Year: ";
     cin >> year;
     for(auto it = database.begin(); it != database.end();) {
       if((*it)->getYear() == year&&removed == false){
	 char confirm;
         cout<< "Confirm y/n:";
         cin>> confirm;
         if(confirm == 'y') {
           delete *it;
           it = database.erase(it);
	   removed = true;
         }else {
	   ++it;
	 }
       }else{
	 ++it;
       }
     }
   }else{
     cout << "Type a valid input" << endl;
   }

 }
