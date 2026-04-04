#include <iostream>
#include <cstring>
#include <fstream>
#include "node.h"

using namespace std;
//prototypes
void add(node* &current, int data);
void remove(node* &current, int value);
bool search(node* current, int value);
void print(node* current, int depth);

int main() {
  //main loop
    node* root = NULL;
    char input[20];
    bool running = true;
    cout << "Type file or console: ";
    cin >> input;
    cin.ignore(1000, '\n');
    
    //input type
    if(strcmp(input, "file") == 0) {
      cout << "File name(numbers.txt): ";
      cin >> input;
      ifstream file(input);
      if(!file) {
        cout << "Invalid file type" << endl;
        return 1;
      }
      int num;
      while(file >> num) {//Reads from the file then check if number fits the requirements
        if(num >= 1 && num <= 999) add(root, num);
      }
      file.close();
    } else if(strcmp(input, "console") == 0) {
      char line[100];
      cin.getline(line, 100);//Gets a line then iterates through it adding each valid number
      for(int i = 0; i < strlen(line); i++) {
        if(isdigit(line[i])) {
          int num = 0;
          while(i < strlen(line) && isdigit(line[i])) {
            num = num * 10 + (line[i] - '0');
            i++;
          }
          if(num >= 1 && num <= 999) add(root, num);
        }
      }
    }
    else {//Any other input
      cout << "Invalid input type" << endl;
      return 1;
    }

    char command[20];
    while(running) {//Command loop
      cout << "Type a command (add, remove, search, print, quit): ";        
      cin >> command;
        cin.ignore();
        if(strcmp(command, "add") == 0) { //add
          cout << "Enter number to add: ";
            int val;
            cin >> val;
            if(val >= 1 && val <= 999) add(root, val);
            else cout << "Number out of range" << endl;
        } 
        else if(strcmp(command, "remove") == 0) {//remove
          cout << "Enter number to remove: ";
          int val;
          cin >> val;
          remove(root, val);
        } 
        else if(strcmp(command, "search") == 0) {//search
          cout << "Enter number to search for: ";
            int val;
            cin >> val;
            if(search(root, val)) cout << val << " is in the tree" << endl;
            else cout << val << " is not in the tree" << endl;
        } 
        else if(strcmp(command, "print") == 0) {//print
          print(root, 0);
        } 
        else if(strcmp(command, "quit") == 0) {//quit
          running = false;;
        } 
        else {
          cout << "Invalid command" << endl;
        }
    }
    
    return 0;
}

void add(node* &current, int data) {//add
  if(current == NULL) {//base case when it reaches a leaf
    current = new node(data);
    return;
  }
  if(data < current->getData()) {//goes left if less than number
    add(current->getLeft(), data);
  } else {//right if otherwise
    add(current->getRight(), data);
  }
}

void print(node* current, int depth) {
  if(current == NULL) return;
    print(current->getRight(), depth+1);// right first
    for(int i = 0; i < depth; i++) cout << "\t";//prints it tabbing for each depth
    cout << current->getData() << endl;
    print(current->getLeft(), depth+1);//left second
}

void remove(node* &current, int value) {
  if(current == NULL) return;//Base case

  if(value < current->getData()) {//If it's less than go left
    remove(current->getLeft(), value);
  } else if(value > current->getData()) {//if its greater go right
    remove(current->getRight(), value);
  } else {//otherwise its equal and this node shall be deleted
    if(current->getLeft() == NULL && current->getRight() == NULL) {//both leafs don't exist
      delete current;
      current = NULL;
    } else if(current->getLeft() == NULL){//left or right leafs exist
      node* temp = current;
      current = current->getRight();
      delete temp;
    } else if(current->getRight() == NULL) {
      node* temp = current;
      current = current->getLeft();
      delete temp;
    } else {//otherwise both exist and a replacment needs to be chosen
      node* replacement = current->getRight();
      while(replacement->getLeft() != NULL) {//Finds the replacement node by going down the right until it reaches a left node
        replacement = replacement->getLeft();
      }
      current->setData(replacement->getData());//remove that and bring it up
      remove(current->getRight(), replacement->getData());
    }
  }
}

bool search(node* current, int value) {//search
  if(current == NULL) return false;
  if(value == current->getData()) {//if it finds it return true otherwise search the tree
    return true;
  } else if (value < current->getData()) {
    return search(current->getLeft(), value);
  } else {
    return search(current->getRight(), value);
  }
}
