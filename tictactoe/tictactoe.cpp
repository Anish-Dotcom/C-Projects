#include <iostream>

using namespace std;

void printboard(int table[3][3]);

int main() {
  bool game = true;;
  while (game) {
      int table[3][3] = {{0,0,0},{0,0,0},{0,0,0}};// Creates a 3x3 array that holds the tictactoe board
      char input[3];
      int player = 1;
      printboard(table);
      bool playing = true;
      while(playing) {
	player = 1;
	cout << "Player 1 enter your move: ";
	cin.get(input,3);
	int inputy = (int)(input[1]) -97;
	int inputx = input[0]-49;
	table[inputx][inputy] = player;
	printboard(table);
	
	player = 2;
	cout << "Player 2 enter your move: ";
        cin.get(input,3);
        inputy = (int)(input[1]) -97;
	inputx = input[0]-49;
        table[inputx][inputy] = player;
        printboard(table);

	
	playing = false;
      }
      game = false;
  }
  return 0;
}

void printboard (int table[3][3]) {
  cout << "  1 2 3" << endl;
   for(int i=0; i<3; i++) {
    cout << (char)(i+97) << " "; //Uses typecasting to convert i to its ASCII charecter (Kinda unecessary)
    for(int j =0;j<3; j++) {
      if(table[i][j] == 0) {
        cout << "  ";
      }else if (table[i][j] == 1){
        cout << "X" << " ";
      } else if (table[i][j] == 2) {
        cout << "O" << " ";
      }
    }
    cout << endl;
  }

}
