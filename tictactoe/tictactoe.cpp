#include <iostream>
#include <string.h>

using namespace std;

void printboard(int table[3][3]);
bool checkwin(int player, int table[3][3]);

int main() {
  int table[3][3] = {{0,0,0},{0,0,0},{0,0,0}};// Creates a 3x3 array that holds the tictactoe board
  bool playing = true;
  char input[3];
  int blank = 0;
  int xMove =1;
  int oMove =2;
  int xWins =0;
  int oWins =0;
  int turn = 1;
  while (playing) {
      cout << "Type move in coordinate form Ex. b3" << endl;
      for(int i = 0; i < 3; i++) {
	for(int j = 0; j < 3; j++) {
	  table[i][j] = 0; 
        }
      }
      while(checkwin(1,table)== false && checkwin(2, table) == false) {
	
	int row =0;
	int col =0;
	cout << endl;
	printboard(table);
	cout << "Player " << turn << " enter your move: ";
	cin.get(input,3);
	if(strlen(input) == 3) {
	  cout<< "Please type a valid input STRLEN" << endl;
	} else if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c') {
	  cout<< "Please type a valid input ABC" << endl;
	}  else if (input[1] != '1' && input[1] != '2' && input[1] != '3') {
	  cout << "Please type a valid input 123" << endl;
	} else {
	  row = (int)(input[0]) -97;
	  col = input[1]-49;
	  if(table[row][col] != 0) {
	    cout << "Square taken" << endl;
	  } else {
	    table[row][col] = turn;
	    if(turn == 1) {
	      turn = 2;
	    } else {
	      turn = 1;
	    }
	  }
	}
        
	cin.ignore();
      }
      cout << endl;
      cout << "Player "<< turn << " wins!" << endl;
      if(turn == 1) {
	xWins++;
      } else {
	oWins++;
      }
      cout<< "X wins:" << xWins <<endl;
      cout<< "O wins:" << oWins <<endl;
      cout<< endl;
	 
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
