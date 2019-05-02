#include "Board.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace ttt;

// Member functions
// Constructor 
Board::Board() {
	cout << "Creating empty tic-tac-toe board." << endl;
	cout << "Slots are numbered as seen on a num pad." << endl;
	for (int i = 0; i < SIZE; i++) {
		board[i] = -1;
	}

	printBoard(); // Show an empty board in terminal
}

// Places new piece on board. Returns true if successful.
bool Board::placePiece(int type, int location) {
	// adjust location to index values
	location -= 1;

	if (board[location] != EMPTY) {
		cout << "Slot " << location+1 << " is already taken." << endl;
		return false;
	}
	if (type != X && type != O) {
		cout << "Invalid piece type: " << type << endl;
		return false;
	}

	string player = "X";
	if (type == O) {
		player = "O";
	} 

	cout << "Player " << player << " places a piece." << endl;

	board[location] = type;

	printBoard(); // show updated board in terminal 

	return true;
}

int * Board::getBoard() {
	return board;
}

// Print board matrix flipped s.t. resembles num pad on keyboard 
void Board::printBoard() {
	// Reorder the 3 rows 
	for (int j = 2; j >= 0; j--) {
		for (int i = j*3; i < j*3+3; i++) {
			string value = "-";
			// Determine correct value 
			if (board[i] == O) {
				value = "O";
			} else if (board[i] == X) {
				value = "X";
			}

			// Check for end row 
			if ((i+1) % 3 == 0) {
				cout << value << endl;				
			} else {
				cout << value << "|";
			}
		}			
	}

	cout << endl;
}
