class node {
 public:
  node(int inum);
  ~node();
  void setNext(node* node);
  node* getNext();
  int getNum();
 public:
  int num;
  node* next;
};
