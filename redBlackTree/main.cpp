#include <iostream>
#include <fstream>
#include <cstring>
#include "redBlackTree.h"

using namespace std;

int main() {
  redBlackTree tree;
  bool run = true;
  char input[20];
  int num;
  cout << "Commands: file, type, print, remove, search, quit" << endl;
  while(run) {
    cin >> input;
    if(!strcmp(input, "file")) {
        cout << "Enter file name: ";
        cin >> input;
        ifstream file(input);
        while(file >> num) {
          tree.insert(num);
        }
    } else if (!strcmp(input, "type")) {
      cout << "Enter numbers: ";
      while(cin >> num) {
        tree.insert(num);
      }
    } else if (!strcmp(input, "print")) {
      tree.print();
    } else if(!strcmp(input, "quit")) {
      run = false;
    } else if(!strcmp(input, "remove")) {
      cout << "Enter number to remove: ";
      cin >> num;
      tree.remove(num);
    } else if(!strcmp(input, "search")){
      cout << "Enter number to check in tree: ";
      cin >> num;
      if(tree.search(num)){
        cout << "In list" << endl;
      } else {
        cout << "Not in list" << endl;
      }
    }else {
      cout << "invalid command" << endl;
    }
    cin.clear();
  }
  return 0;
}
