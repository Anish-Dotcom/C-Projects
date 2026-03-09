#ifndef NODE
#define NODE

#include <iostream>

class node {
public:
  node(int inum);//Constructor
  ~node();//Destructor
  void setNext(node* node);//Setter
  node* getNext();//Getter
  int getNum();//Getter
private://Values
  int num;
  node* next;
};

#endif
