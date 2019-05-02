#include "Game.hpp"
#include <iostream> 

using namespace std; 
using namespace ttt;

Game::Game() {
	cout << "New game started." << endl;
	player = "O";
}

// Check for 3 in a row
bool Game::checkWin() {
	// Save the "matrix" 
	int * m = board.getBoard();
	// 0|1|2
	// 3|4|5
	// 6|7|8
	bool win = false;
	// Check vertical matches
	for (int i = 0; i <= 2; i++) {
		if (m[i] != EMPTY && m[i] == m[i+3] && m[i] == m[i+6]) {
			win = true;
		}
	}
	// Check horizontal matches 
	for (int i = 0; i <= 6; i+=3) {
		if (m[i] != EMPTY && m[i] == m[i+1] && m[i] == m[i+2]) {
			win = true;
		}		
	}
	// Check diagonal match (\)
	if (m[0] != EMPTY && m[0] == m[4] && m[0] == m[8]) {
		win = true;
	}	
	// Check diagonal match (/)
	if (m[6] != EMPTY && m[6] == m[4] && m[6] == m[2]) {
		win = true;
	}

	if (win) {
		cout << "Player " << player << " wins!" << endl;
	}
	return win;
}	

// Check for full board with no 3 in a row
bool Game::checkTie() {
	int * m = board.getBoard();	
	bool emptySlot = false;
	for (int i = 0; i < SIZE; i++) {
		if (m[i] == EMPTY) {
			emptySlot = true;
		}
	}
	if (!checkWin() && !emptySlot) {
		cout << "Tie game." << endl;
		return true;
	}
	return false;
}

// Changes active player
void Game::nextTurn() {
	if (player == "X") {
		player = "O";
	} else {
		player = "X";
	}
	cout << "Player " << player << " turn." << endl;
}

// Return numerical value based on active player letter 
int Game::getPlayerType() {
	if (player == "O") {
		return O; // 0
	}
	return X; // 1 
}

// Prompt user input for next box selection. 
// Will continue to prompt user until a successful input.
void Game::selectPosition() {
	cout << "Choose position 1-9 for next piece." << endl;
	
	bool selectionMade = false;
	int pos;
	while (!selectionMade) {
		cin >> pos;
		// Check for non-number inputs 
		if (!pos || cin.fail()) {
			cin.clear(); // remove the error flag 
			cin.ignore(10000, '\n'); // clear the buffer to prevent future failure
			cout << "Please enter a number 1-9. No non-numbers!" << endl;		
			continue;
		}	
		// Check input within range 
		if (pos < 1 || pos > 9) {
			cout << "Invalid selection. Please choose between 1-9." << endl;
			continue;
		} 
		// Attempt to place piece 
		if (!board.placePiece(getPlayerType(), pos)) {
			cout << "Invalid selection. Position already full. Try again." << endl;
		} else {
			selectionMade = true;
		}
	}

	return;
}
