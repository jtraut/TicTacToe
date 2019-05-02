#include "Board.cpp" // note - bad practice, use header files instead 
#include <iostream> 
#include <string>

using namespace std; 
using namespace ttt;

class Game {
public:
	Game(); // The game constructor
	bool checkWin();
	bool checkTie(); 
	void nextTurn(); 
	int  getPlayerType();
	int  selectPosition();
private:
	string player;
	bool gameOver;
};

Game::Game() {
	cout << "New game started." << endl;
	player = "O";
}

// Check for 3 in a row
bool Game::checkWin() {
	return false;
}	

// Check for full board with no 3 in a row
bool Game::checkTie() {
	return false;
}

void Game::nextTurn() {
	if (player == "X") {
		player = "O";
	} else {
		player = "X";
	}
	cout << "Player " << player << " turn." << endl;
}

int Game::getPlayerType() {
	if (player == "O") {
		return 0;
	}
	return 1;
}

int Game::selectPosition() {
	cout << "Choose position 1-9 for next piece." << endl;
	
	bool selectionMade = false;
	int pos;
	while (!selectionMade) {
		cin >> pos;
		if (pos < 1 || pos > 9) {
			cout << "Invalid selection. Please choose between 1-9." << endl;
		} else {
			selectionMade = true;
		}
		/*
		if (!board.placePiece(game.getPlayerType(), pos)) {
			cout << "Invalid selection. Position already full. Try again." << endl;
		} else {
			selectionMade = true;
		}*/
	}

	return pos;
}

int main() {
	// Start new game
	Game game;	
	ttt::Board board;

	// Display whose turn it is 
	game.nextTurn();

	bool gameOver = false;
	while (!gameOver) {
	
		// wait for user input here for location 
		int pos = game.selectPosition();

		if (!board.placePiece(game.getPlayerType(), pos)) {
			cout << "Invalid selection. Position already full. Try again." << endl;
		} else {
			// Check game status
			if (game.checkWin() || game.checkTie()) {
				gameOver = true;
			}
			// Or proceed to next turn
			game.nextTurn();
		}
	}
	return 0;
};