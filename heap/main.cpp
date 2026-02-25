#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void add(int** heap, int index);
void remove(int** heap, int index, int size);
void print(int* heap, int index,int size, int depth);

int main() {
  int* heap = new int[101];
  int size = 0;
  
  bool running = true;
  char input [20];
  
  cout << "Commands: ADDTYPE ADDFILE DELETE PRINT QUIT" << endl;
  while(running) {
    cin >> input;
    if (strcmp(input, "ADDTYPE") == 0) {
      cout << "Enter numbers seperated by spaces: ";
      char line[100];
      cin.ignore();
      cin.getline(line, 100);
      
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
    } else if(strcmp(input, "ADDFILE")==0){
      cout << "Enter filename: ";
      cin>>input;
      ifstream file(input);
      if(file){
        char line[10];
        file.get(line, 10, ' ');
        while(line[0]!='\0') {
          size++;
          heap[size] = atoi(line);
          add(&heap,size);
          file.ignore();
          file.get(line, 10, ' ');
        }
      }else {
        cout << "Error reading file" << endl;
      }
    }else if (strcmp(input, "DELETE") == 0){
      cout << "Deleting: " << heap[1] << endl;
      swap(heap[1], heap[size]);
      size--;
      remove(&heap, 1, size);
    } else if (strcmp(input, "PRINT") == 0){
      if(size == 0) {
        cout << "Empty list" << endl;
      }else {
        print(heap, 1, size+1, 0);
      }
    } else if (strcmp(input, "QUIT") == 0) {
      running = false;
    } else {
      cout << "Invalid command" << endl;
    }
  }
}

void add(int** heap, int index) {
  if(index == 1) {
    return;
  }
  int parent = (floor(index/2));
  if((*heap)[index]>(*heap)[parent]) {
    swap((*heap)[index], (*heap)[parent]);
    add(heap, parent);
  }
}

void remove(int** heap, int index, int size) {
  
  if(index>=size) {
    return;
  }
  int left = (index*2);
  int right = (index*2+1);
  if(left>=size){//Leaf node
    return;
  }
  
  if((*heap)[left] >= (*heap)[right]) {
    swap((*heap)[index], (*heap)[left]);
    remove(heap, left, size);
  } else{
    swap((*heap)[index], (*heap)[right]);
    remove(heap, right, size);
  }
}

void print(int* heap, int index, int size, int depth) {
  int left = (index*2);
  int right = ((index*2)+1);
  
  if(right<size) {
    print(heap, right, size, depth+1);
  }
  
  for(int i = 0; i < depth;i++) {
    cout << "\t";
  }
  cout << heap[index] << endl;

  if(left<size) {
    print(heap,left,size,depth+1);
  }  
}
