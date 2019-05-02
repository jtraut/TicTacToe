#include "Game.hpp"

using namespace ttt;

int main() {
	// Start new game
	Game game;	

	// Display whose turn it is 
	game.nextTurn();

	bool gameOver = false;
	while (!gameOver) {
	
		// wait for user input here for next piece placement 
		// will fill board on successful selection
		game.selectPosition();

		// Check game status
		if (game.checkWin() || game.checkTie()) {
			gameOver = true;
		} else {
			// Or proceed to next turn
			game.nextTurn();				
		}
	}

	return 0;
};