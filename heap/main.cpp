#include <iostream>
#include <algorithm>

using namespace std;

void add(int** heap, int index);
void print(int* heap, int total);

int main() {
  int* heap = new int[101];
  int total = 0;
  
  bool running = true;
  char input [20];
  
  cout << "Commands: ADD DELETE PRINT QUIT" << endl;
  while(running) {
    cin >> input;
    if (strcmp(input, "ADD") == 0) {
      int num;
      cin >> num;
      heap[total+1] = num;
      add(&heap, total+1);
      total++;
    } else if (strcmp(input, "DELETE") == 0){
      
    } else if (strcmp(input, "PRINT") == 0){
      print(heap, total);
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
  
  int pindex = (floor(index/2));
  if((*heap)[index]>(*heap)[pindex]) {
    swap((*heap)[index], (*heap)[pindex]);
    add(heap, pindex);
  }
  
}

void print(int* heap, int total) {
  for(int i = 0; i < total; i++) {
    cout << heap[i] << endl;
  }
}
