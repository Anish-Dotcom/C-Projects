#include <iostream>
using namespace std;

struct node {//initialization
  int data;
  char color = 'r';
  node* parent = NULL;
  node* left = NULL;
  node* right = NULL;
};

class redBlackTree {//prototypes
 public:
  redBlackTree();
  void insert(int data);
  void print();
  private:
  node* root;
  void insert(node* &current, node* newnode);
  void insertfix(node* current);
  void print(node* current, int depth);
  node* sibling(node* current);
  void rightRotate(node* current);
  void leftRotate(node* current);
};
