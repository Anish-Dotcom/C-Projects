#include <iostream>
#include <cstring>
#include <cctype>


using namespace std;

int main() {
    cout << "Type a word and I will say if its a palindrome: ";
  char str[80];
  cin.get(str, 80);
  char fstr [80];
  int j=0;
  for(int i = 0; i < strlen(str); i++) {
    if(str[i] == ' '||str[i] == '.') {
      
    }else {
      fstr[j] = str[i];
      j++;
    }
  }
  for(int i = 0; i< strlen(fstr); i++) {
      fstr[i] = toupper(fstr[i]);
  }
  int k = strlen(fstr);
  int target = strlen(fstr)/2;
  int count =0;
  bool palindrome = false;
  for(int i = 0; i < strlen(fstr)/2; i++) 
    {
      k--;
      if(fstr[i] == fstr[k]) 
	{
	  count++;
	}
      if(count == target) 
	{
	   cout <<"Palindrome!"<<endl;
	   palindrome = true;
	   break;
	}
    }
    if(!palindrome) {
    cout<< "Not a palindrome";
    }
  
  
  
  return 0;
}
