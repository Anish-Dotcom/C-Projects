/*
Auther: Anish Rao
Date: 9/16/2025
Description: This is a program to tell if a word is a palindrome meaning it its spelled the same backword as it is forward.
*/

#include <iostream>
#include <cstring>
#include <cctype>


using namespace std;

int main() {
  cout << "Type a word and I will say if its a palindrome: ";// Gets the input
  char str[80];
  cin.get(str, 80);
  char fstr [80];
  int j=0;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] != ' ' && !ispunct(str[i])) {//If its not a space or punctuation add it to the main string 
      fstr[j] = str[i];
	j++;
    }
  }
  fstr[j] = '\0';//Adds null terminator to the end

  for(int i = 0; i< strlen(fstr); i++) {//Iterates through string and uppercases
      fstr[i] = toupper(fstr[i]);
  }
  int k = strlen(fstr);//Variable to represent the opposite side of string
  int count =0;
  bool palindrome = false;
  for(int i = 0; i < strlen(fstr)/2; i++) 
    {
      k--;
      if(fstr[i] == fstr[k]) //Compares the beginning to the end of a cstring
	{
	  count++;
	}
      if(count == strlen(fstr)/2) //If half or more chars are the same its a palindrome
	{
	   cout <<"Palindrome!"<<endl;
	   palindrome = true;
	   break;
	}
    }
    if(!palindrome) {
    cout<< "Not a palindrome!";
    }
  
  
  
  return 0;
}
