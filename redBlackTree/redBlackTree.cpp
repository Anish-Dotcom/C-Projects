#include <iostream>
#include "redBlackTree.h"
using namespace std;

redBlackTree::redBlackTree() {//constructor
  root = NULL;
}

void redBlackTree::insert(int data) {//public insert helper function to start recursion
  node* newnode = new node;
  newnode->data = data;
  insert(root, newnode);				 
  insertfix(newnode);
}

void redBlackTree::insert(node* &current, node* newnode) {//binary search tree insertion with parent pointers
  if(current == NULL) {
    current = newnode;
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
  if(current->parent == NULL) {//case 1: insert at root
    current->color = 'b';//color root black
    return;
  }

  if(current->parent->color == 'b') return;//case 2: parent is black

  node* grandparent = current->parent->parent;//get grandparent
  node* uncle = sibling(current->parent);
    
  if (uncle != NULL && uncle->color == 'r') {//case 3: uncle is red
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
  if(current == NULL) return;
  print(current->right, depth+1);
  for(int i = 0; i < depth; i++) cout << "\t";
  cout << current->data << current->color << endl;
  print(current->left, depth+1);
}

node* redBlackTree::sibling(node* current) {//gets sibling
  if(current == NULL || current->parent == NULL) return NULL;
  if(current == current->parent->left){
    return current->parent->right;
  } else {
    return current->parent->left;
  }
}

void redBlackTree::rightRotate(node* top) {
  node* middle = top->left;
  top->left = middle->right;//update subtrees by moving middle's subtrees to top
  if(middle->right != NULL) {
    middle->right->parent = top;//update subtree
  }
  middle->parent = top->parent;//update parent pointer
  if(top->parent == NULL) {//If root update pointer
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
  if(middle->left != NULL) {
    middle->left->parent = top;//update subtree
  }
  middle->parent = top->parent;
  if(top->parent == NULL) {//3. If root update
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

void redBlackTree::remove(node* &current, int key) {
  if(current == NULL) return;

  if(key < current->data) {
    remove(current->left, key);
  } 
  else if(key > current->data) {
    remove(current->right, key);
  } 
  else {//found node to delete

    node* deleted = current;
    node* removed = current;
    node* child;
    char removedColor = removed->color;

    //case 1: no left child
    if(current->left == NULL) {
      child = current->right;
      rbtransplant(current, current->right);
    }

    //case 2: no right child
    else if(current->right == NULL) {
      child = current->left;
      rbtransplant(current, current->left);
    }

    //case 3: two children
    else {
      removed = minimum(current->right);
      removedColor = removed->color;
      child = removed->right;

      //successor is direct child
      if(removed->parent == current) {
        if(child != NULL) {
          child->parent = removed;
        }
      } 
      else {
        rbtransplant(removed, removed->right);

        removed->right = current->right;

        if(removed->right != NULL) {
          removed->right->parent = removed;
        }
      }

      //THIS MUST ALWAYS HAPPEN
      rbtransplant(current, removed);

      removed->left = current->left;

      if(removed->left != NULL) {
        removed->left->parent = removed;
      }

      removed->color = current->color;
    }

    delete deleted;

    if(removedColor == 'b') {
      removefix(child);
    }
  }
}

void redBlackTree::removefix(node* current) {

}

node* redBlackTree::minimum(node* current) {
  if(current->left == NULL) {
    return current;
  }
  return minimum(current->left);
}

void redBlackTree::rbtransplant(node* current, node* replacement) {
  if(current->parent == NULL) {//current is root
    root = replacement;
  } 
  else if(current == current->parent->left) {//current is left child
    current->parent->left = replacement;
  } 
  else {//current is right child
    current->parent->right = replacement;
  }

  if(replacement != NULL) {//update parent pointer
    replacement->parent = current->parent;
  }
}
