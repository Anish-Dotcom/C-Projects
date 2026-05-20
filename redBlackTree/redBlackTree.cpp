#include <iostream>
#include "redBlackTree.h"
using namespace std;

redBlackTree::redBlackTree() {//constructor
  nil = new node;
  nil->data = 0;
  nil->color = 'b';
  nil->left = nil;
  nil->right = nil;
  nil->parent = nil;

  root = nil;
}

void redBlackTree::insert(int data) {//public insert helper function to start recursion
  node* newnode = new node;
  newnode->data = data;
  newnode->left = nil;
  newnode->right = nil;
  newnode->parent = nil;
  insert(root, newnode);				 
  insertfix(newnode);
}

void redBlackTree::insert(node* &current, node* newnode) {//binary search tree insertion with parent pointers
  if(current == nil) {
    current = newnode;
    if(current->left == nil) current->left->parent = current;
    if(current->right == nil) current->right->parent = current;
    return;
  }
  if(newnode->data < current->data) {
    newnode->parent = current;
    insert(current->left, newnode);
  } else {
    newnode->parent = current;
    insert(current->right, newnode);
  }
}

void redBlackTree::insertfix(node* current) {//red black tree fix
  if(current->parent == nil) {//case 1: insert at root
    current->color = 'b';//color root black
    return;
  }

  if(current->parent->color == 'b') return;//case 2: parent is black

  node* grandparent = current->parent->parent;//get grandparent
  node* uncle = sibling(current->parent);
    
  if (uncle != nil && uncle->color == 'r') {//case 3: uncle is red
    current->parent->color = 'b';//change uncle and parent to black
    uncle->color = 'b';
    grandparent->color = 'r';//grandparent to red
    insertfix(grandparent);//recursively call on grandpa
  }else {//case 4/5: uncle is black
    //case 4: triangle, rotate to make line
    if(current == current->parent->right && current->parent == grandparent->left) {
      current = current->parent;//moves up
      leftRotate(current);//left rotate to make line
    } else if(current == current->parent->left && current->parent == grandparent->right) {
      current = current->parent;//assign parent to current
      rightRotate(current);//right rotate to make line
    }
    //case 5: line, rotate grandparent
    current->parent->color = 'b';//set parent to black
    grandparent->color = 'r';//set grandparent to red
    if(current->parent == grandparent->left) {//left line
      rightRotate(grandparent);//right rotate on grandparent
    } else {//right line
      leftRotate(grandparent);//left rotate on grandparent
    }
  }
  root->color = 'b';//recolor root to satasfy rbt
}

void redBlackTree::print() {//print helper
  print(root, 0);
}

void redBlackTree::print(node* current, int depth) {//inorder traversal with depth
  if(current == nil) return;
  print(current->right, depth+1);
  for(int i = 0; i < depth; i++) cout << "\t";
  cout << current->data << current->color << endl;
  print(current->left, depth+1);
}

node* redBlackTree::sibling(node* current) {//gets sibling
  if(current == nil || current->parent == nil) return nil;
  if(current == current->parent->left){
    return current->parent->right;
  } else {
    return current->parent->left;
  }
}

void redBlackTree::rightRotate(node* top) {
  node* middle = top->left;
  top->left = middle->right;//update subtrees by moving middle's subtrees to top
  if(middle->right != nil) {
    middle->right->parent = top;//update subtree
  }
  middle->parent = top->parent;//update parent pointer
  if(top->parent == nil) {//If root update pointer
    root = middle;
  } else if(top == top->parent->right) {//update parent to have correct child
    top->parent->right = middle;
  } else {
    top->parent->left = middle;
  }
  middle->right = top;//finally switch the two nodes
  top->parent = middle;
}

void redBlackTree::leftRotate(node* top) {
  node* middle = top->right;//1. get the middle
  top->right = middle->left;//2. update subtree by moving middle's left to tops right
  if(middle->left != nil) {
    middle->left->parent = top;//update subtree
  }
  middle->parent = top->parent;
  if(top->parent == nil) {//3. If root update
    root = middle;
  } else if(top == top->parent->left) {//4. if top is left child then set middle as left of parent
    top->parent->left = middle;
  } else {//5. Otherwise its right
    top->parent->right = middle;
  }
  middle->left = top;//6. Swap the nodes
  top->parent = middle;
}

void redBlackTree::remove(int key) {
  remove(root, key);
}

void redBlackTree::remove(node* current, int key) {
  if(current == nil) return;

  if(key < current->data) {//binary search
    remove(current->left, key);
  } 
  else if(key > current->data) {
    remove(current->right, key);
  } 
  else {//found node to delete
    node* deleted = current;
    node* successor = current;
    node* child;
    char removedColor = successor->color;

    //case 1: no left child
    if(current->left == nil) {
      child = current->right;//store subtree
      rbtransplant(current, current->right);//swap
    }

    //case 2: no right child
    else if(current->right == nil) {
      child = current->left;//store subtree
      rbtransplant(current, current->left);//swap
    }

    //case 3: two children
    else {
      successor = minimum(current->right);//gets inorder successor
      removedColor = successor->color;//store successor color for future fixup
      child = successor->right;//store right subtree(only possible one)

      //successor is direct child
      if(successor->parent == current) {
        child->parent = successor;
      } 
      else {//not direct, requires transplant
        rbtransplant(successor, successor->right);//replace successor with child

        successor->right = deleted->right;//move currents right subtree to successors

        if(successor->right != nil) {//fix parent pointer
          successor->right->parent = successor;
        }
      }
 
      rbtransplant(current, successor);//move in successor

      successor->left = deleted->left;//move left subtree to successor

      if(successor->left != nil) {//fix parent pointer
        successor->left->parent = successor;
      }

      successor->color = deleted->color;//fix color
    }

    delete deleted;//delete the node

    if(removedColor == 'b') {//if its black violated rbt proporty and fix
      removefix(child);
    }
  }
}

void redBlackTree::removefix(node* current) {
  node* sibling;

  if(current == root) return; //case 1: current is root

  if(getColor(current) == 'r') {
    current->color = 'b';
    return;
  }

  if(current == current->parent->left) { //left child
    sibling = current->parent->right;
    if(getColor(sibling) == 'r') { //case 2
      sibling->color = 'b';
      current->parent->color = 'r';
      leftRotate(current->parent);
      sibling = current->parent->right;
    }

    if(getColor(sibling->left) == 'b' &&
       getColor(sibling->right) == 'b') { //case 3/4

      sibling->color = 'r';

      if(getColor(current->parent) == 'r') { //case 4
        current->parent->color = 'b';
      }
      else { //case 3
        removefix(current->parent);
      }
    }

    else { //case 5/6

      if(getColor(sibling->right) == 'b') { //case 5
        sibling->color = 'r';
        sibling->left->color = 'b';
        rightRotate(sibling);
        sibling = current->parent->right;
      }

      //case 6
      sibling->color = current->parent->color;
      current->parent->color = 'b';
      sibling->right->color = 'b';

      leftRotate(current->parent);
    }
  }

  else { //right child
    sibling = current->parent->left;
    if(getColor(sibling) == 'r') { //case 2
      sibling->color = 'b';
      current->parent->color = 'r';
      rightRotate(current->parent);
      sibling = current->parent->left;
    }

    if(getColor(sibling->right) == 'b' &&
       getColor(sibling->left) == 'b') { //case 3/4

      sibling->color = 'r';

      if(getColor(current->parent) == 'r') { //case 4
        current->parent->color = 'b';
      }
      else { //case 3
        removefix(current->parent);
      }
    }

    else { //case 5/6

      if(getColor(sibling->left) == 'b') { //case 5
        sibling->color = 'r';
        sibling->right->color = 'b';
        leftRotate(sibling);
        sibling = current->parent->left;
      }

      //case 6
      sibling->color = current->parent->color;
      current->parent->color = 'b';
      sibling->left->color = 'b';
      cout << current->parent->data << endl;
      rightRotate(current->parent);
    }
  }
}

node* redBlackTree::minimum(node* current) {
  if(current->left == nil) {//find leftmost node
    return current;
  }
  return minimum(current->left);
}

void redBlackTree::rbtransplant(node* current, node* replacement) {
  if(current->parent == nil) {//current is root
    root = replacement;
  } 
  else if(current == current->parent->left) {//current is left child
    current->parent->left = replacement;
  } 
  else {//current is right child
    current->parent->right = replacement;
  }
  replacement->parent = current->parent;
}

bool redBlackTree::search(int key) {
  return search(root, key);
}

//search, goes left if greater right else
bool redBlackTree::search(node* current, int key) {
  if (current == nil) return false;
  if(current->data == key) return true;
  if(current->data > key) {
    return search(current->left, key);
  } else  {
    return search(current->right, key);
  }
}

char redBlackTree::getColor(node* current) {//to make null nodes be black
  return current->color;
}
B
