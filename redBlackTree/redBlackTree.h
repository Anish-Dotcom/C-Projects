#include <iostream>
using namespace std;

struct node {
  int data;
  char color = 'r';
  node* parent = NULL;
  node* left = NULL;
  node* right = NULL;
};

class redBlackTree {
 public:
  redBlackTree();
  void insert(int data);
  void print();
  private:
  node* root;
  void insert(node* &current, node* newnode, int ndata);
  void print(node* current, int depth);
  node* sibling(node* current);
  void insertfix(node* current);
};
