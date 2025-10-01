#include <iostream>
#include <string.h>

using namespace std;

void printboard(int table[3][3]);
bool checkwin(int player, int table[3][3]);

int main() {
  int table[3][3] = {{0,0,0},{0,0,0},{0,0,0}};// Creates a 3x3 array that holds the tictactoe board
  bool playing = true;
  char input[2];
  int xTurn = 0;
  int oTurn = 1;
  int blank = 0;
  int xMove =1;
  int oMove =2;
  int xWins =0;
  int oWins =0;
  int turn = xTurn;
  while (playing) {
    cout << "Type move in coordinate form Ex. b3" << endl;
     printboard(table);
      while(checkwin(player,table)== false) {
	cout << "Type move in coordinate form Ex. b3" << endl;
	printboard(table);
	player = 1;
	cout << "Player 1 enter your move: ";
	cin.get(input,3);
	if(strlen(input) != 2) {
	  cout<< "Please type a valid input" << endl;
	} else if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c') {
	  cout<< "Please type a valid input" << endl;
	}  else if (input[1] != '1' && input[1] != '2' && input[1] != '3') {
	  cout << "Please type a valid input" << endl;
	} else {
	  int row = (int)(input[0]) -97;
	  int col = input[1]-49;
	  cout << row << col << endl;
	  table[row][col] = player;
	}
	table[inputx][inputy] = player;
	printboard(table);
	player = 2;
	cout << "Player 2 enter your move: ";
	cin.ignore();
	cin.get(input,3);
        inputy = (int)(input[1]) -97;
	inputx = input[0]-49;
        table[inputx][inputy] = player;
        printboard(table);
	cin.ignore();
      }
      playing = false;
  }
  return 0;
}

void printboard (int table[3][3]) {
  cout << "  1 2 3" << endl;
   for(int i=0; i<3; i++) {
    cout << (char)(i+97) << " "; //Uses typecasting to convert i to its ASCII charecter 
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

bool checkwin(int player, int board[3][3]) {
  //Verticals
  if(board[2][0]==player && board [2][1] && board [2][2] == player) {
    return true;
  }
 if(board[1][0]==player && board [1][1] && board [1][2] == player) {
    return true;
}
if(board[0][0]==player && board [0][1] && board [0][2] == player) {
  return true;
}
//Diagonals
if(board[0][0]==player && board [1][1] && board [2][2] == player) {
  return true;
}
if(board[2][0]==player && board [2][1] && board [2][2] == player) {
  return true;
}
//Horizantals
if(board[0][0]==player && board [1][0] && board [2][0] == player) {
  return true;
}
if(board[0][1]==player && board [1][1] && board [2][1] == player) {
  return true;
}
if(board[0][2]==player && board [1][2] && board [2][2] == player) {
  return true;
}
 return false;
}
