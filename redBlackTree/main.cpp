#include <iostream>
#include <fstream>
#include "redBlackTree.h"

using namespace std;

int main() {
  redBlackTree tree;
  bool run = true;
  char input[20];
  cout << "Enter file name: ";
  cin >> input;
  ifstream file(input);
  int num;
  while(file >> num) {
    tree.insert(num);
  }
  tree.print();
  return 0;
}
