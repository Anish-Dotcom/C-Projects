#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>

class treenode {
public:
  treenode(int inum);//Constructor
  ~treenode();//Desructor
  int getdata();//Getters
  treenode* getleft();
  treenode* getright();
  void setleft(treenode* newleft);//Setters
  void setright(treenode* newleft);
private://Data and child pointers
  int data;
  treenode* left = NULL;
  treenode* right = NULL;
};

#endif
