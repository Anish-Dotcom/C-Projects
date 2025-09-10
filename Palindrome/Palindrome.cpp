#include <iostream>
#include <cstring>

using namespace std;

int main() {
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
  cout << fstr <<endl;
  int k = strlen(fstr);
  int target = strlen(fstr/2);
  for(int i = 0; i < strlen(fstr); i++) 
    {
      k--;
      cout <<fstr[i]<<endl;
      cout <<fstr[k]<<endl;
      if(fstr[i] == fstr[k]) 
	{
	  count++;
	  
	  cout <<"1"<<endl;
	  break;
	  
	}
      if(count == target) 
	{
	   cout <<"Palindrome!"<<endl;
	}
      
      
    }
  
  
  
  return 0;
}
