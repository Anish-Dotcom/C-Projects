#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>

class treenode {
 public:
  treenode(int inum);
  ~treenode();
  int getdata();
  treenode* getleft();
  treenode* getright();
  void setleft(treenode* newleft);
  void setright(treenode* newleft);
 private:
  int data;
  treenode* left = NULL;
  treenode* right = NULL;
};

#endif
