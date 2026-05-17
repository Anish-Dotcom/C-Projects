#include <iostream>
using namespace std;

struct node {//initialization
  int data;
  char color = 'r';
  node* parent;
  node* left;
  node* right;
};

class redBlackTree {//prototypes
 public:
  redBlackTree();
  void insert(int data);
  void print();
  void remove(int key);
  bool search(int key);
  private:
  node* root;
  node* nil;
  void insert(node* &current, node* newnode);
  void insertfix(node* current);
  void print(node* current, int depth);
  node* sibling(node* current);
  void rightRotate(node* current);
  void leftRotate(node* current);
  void remove(node* current, int key);
  void removefix(node* current);
  node* minimum(node* current);
  void rbtransplant(node* u, node* v);
  bool search(node* current, int key);
  char getColor(node* current);
};
