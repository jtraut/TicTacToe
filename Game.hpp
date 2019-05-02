#ifndef GAME_H
#define GAME_H
#include "Board.hpp"
#include <string>

// TicTacToe
namespace ttt {

	class Game {
	private:
		std::string player;
		bool gameOver;
		Board board;	
	public:
		Game(); // The game constructor
		bool checkWin();
		bool checkTie(); 
		void nextTurn(); 
		int  getPlayerType();
		int  selectPosition();
	};	

}

#endif