#include <iostream>
using namespace std;

struct node {
  int data;
  bool color = 0;
  node* parent = NULL;
  node* left = NULL;
  node* right = NULL;
};

class redBlackTree {
 public:
  redBlackTree();
  void insert(int data);
  void insertTraversal(node* current, node* newnode);
 private:
  node* root;
};
