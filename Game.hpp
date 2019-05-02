#ifndef GAME_H
#define GAME_H
#include "Board.hpp"
#include <string>

// TicTacToe
namespace ttt {

	class Game {
	private:
		std::string player;
		Board board;	
	public:
		Game(); // The game constructor
		bool checkWin();
		bool checkTie(); 
		void nextTurn(); 
		int  getPlayerType();
		void selectPosition();
	};	

}

#endif