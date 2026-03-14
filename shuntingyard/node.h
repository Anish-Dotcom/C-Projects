#ifndef NODE
#define NODE

#include <iostream>
#include "binarytree.h"

class node {
public:
  node(char input);//Constructor
  ~node();//Destructor
  void setNext(node* node);//Setter
  node* getNext();//Getter
  char getData();//Getter
  treenode* getTree();
  void setTree(treenode* itree);
private://Values
  char data;
  node* next;
  treenode* tree;
};

#endif
