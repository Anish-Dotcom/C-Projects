/*
  Auther: Anish Rao
  Date: 2/25/26
  Description: A script that creates a binary tree that satasfies the heap proporty where each node is less than its parent. This code also supports file inputs.
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

//Function pass a double pointer to the heap to modify it. They also pass in the index to recurse through the heap.
void add(int** heap, int index);
void remove(int** heap, int index, int size);
void print(int* heap, int index,int size, int depth);//Passes depth to print the tree

int main() {
  int* heap = new int[101];//The heap starts at index 1
  int size = 0;
  
  bool running = true;
  char input [20];
  
  cout << "Commands: ADDTYPE ADDFILE DELETE PRINT QUIT" << endl;
  while(running) {
    cin >> input;
    if (strcmp(input, "ADDTYPE") == 0) {//Add by typing
      cout << "Enter numbers seperated by spaces: ";
      char line[10];
      cin.ignore();
      cin.get(line, 10, ' ');
      while(line[0]!='\0') {
	cout<<line;
	size++;
	heap[size] = atoi(line);
	add(&heap, size);
	cin.ignore();
	cin.get(line, 10, ' ');
      }
      cout << endl;
      /*
      char line[1000];
      cin.ignore();
      cin.getline(line, 1000);
      
      int num = 0;
      bool reading = false;

      for(int i = 0; i<strlen(line); i++) {
        if(isdigit(line[i])) {
          num = num*10 + (line[i] - '0');
          reading = true;
        }else if(reading) {
          size++;
          heap[size] = num;
          add(&heap, size);
          num = 0;
          reading = false;
        }
      }
      if(reading) {
        size++;
        heap[size] = num;
        add(&heap, size);
      }
      */
    } else if(strcmp(input, "ADDFILE")==0){//Add by file
      cout << "Enter filename: ";
      cin>>input;
      ifstream file(input);//Using the input gets the file and allows code to read it
      if(file){//File returns false when a problem happens
        char line[10];
        file.get(line, 10, ' ');//Gets the number untill it reaches a space
        while(line[0]!='\0') {//Until that line is the termiating char add that number
          size++;
          heap[size] = atoi(line);//Converts line to int and adds it to heap
          add(&heap,size);//Corrects nodes
          file.ignore();
          file.get(line, 10, ' ');
        }
	cout << "File read" << endl;
      }else {
        cout << "Error reading file" << endl;
      }
    }else if (strcmp(input, "DELETE") == 0){//Deletion
      cout << "Deleting: " << heap[1] << endl;
      swap(heap[1], heap[size]);//Swaps the root node with the last
      size--;//lowers the size essentially deleting it
      remove(&heap, 1, size);//Corrects the nodes
    } else if (strcmp(input, "PRINT") == 0){//Printing
      if(size == 0) {
        cout << "Empty list" << endl;
      }else {
        print(heap, 1, size+1, 0);//Starting index the root node
      }
    } else if (strcmp(input, "QUIT") == 0) {
      running = false;
    } else {
      cout << "Invalid command" << endl;
    }
  }
}

void add(int** heap, int index) {
  if(index == 1) {//Base case when it reaches root
    return;
  }
  int parent = (floor(index/2));//Gets parent
  if((*heap)[index]>(*heap)[parent]) {//If child is greater than parent swap them
    swap((*heap)[index], (*heap)[parent]);
    add(heap, parent);//Recursive step moving up the tree
  }
}

void remove(int** heap, int index, int size) {
  if(index>=size) {//Base case if it runs off the tree
    return;
  }
  //Get children
  int left = (index*2);
  int right = (index*2+1);
  if(left>=size){//If its left child doesnt exist then end the recursion because right can't exist either
    return;
  }
  
  if((*heap)[left] >= (*heap)[right]) {//if left is bigger swap with left
    swap((*heap)[index], (*heap)[left]);
    remove(heap, left, size);//Recursive step down
  } else{
    swap((*heap)[index], (*heap)[right]);//If right is bigger swap with right
    remove(heap, right, size);//Recursive step down
  }
}

void print(int* heap, int index, int size, int depth) {//Index starts at root
  //Get children
  int left = (index*2);
  int right = ((index*2)+1);
  
  if(right<size) {//Recurse down the right side increasing the depth each time untill you reach bottom node
    print(heap, right, size, depth+1);
  }
  
  for(int i = 0; i < depth;i++) {//For each depth tab once
    cout << "\t";
  }
  cout << heap[index] << endl;//Print

  if(left<size) {//For each node traverse down its left side, this allows every node to be printed
    print(heap,left,size,depth+1);
  }  
}
