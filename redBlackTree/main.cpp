#include <iostream>
#include <fstream>
#include <cstring>
#include "redBlackTree.h"

using namespace std;

int main() {
  redBlackTree tree;
  bool run = true;
  char input[20];
  cout << "Commands: file, type, print, quit" << endl;
  while(run) {
    cin >> input;
    if(!strcmp(input, "file")) {
        cout << "Enter file name: ";
        cin >> input;
        ifstream file(input);
        int num;
        while(file >> num) {
          tree.insert(num);
        }
    } else if (!strcmp(input, "type")) {
      cout << "Enter numbers: ";
      int num;
      while(cin >> num) {
        tree.insert(num);
      }
    } else if (!strcmp(input, "print")) {
      tree.print();
    } else if(!strcmp(input, "quit")) {
      run = false;
    } else {
      cout << "invalid command" << endl;
    }
    cin.clear();
  }
  return 0;
}
