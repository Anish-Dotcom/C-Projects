#include <iostream>
#include "redBlackTree.h"

using namespace std;

int main() {
  redBlackTree tree;
  tree.insert(6);  
  tree.insert(2);
  tree.insert(8);
  tree.insert(9);
  tree.insert(7);
  tree.print();
  return 0;
}
