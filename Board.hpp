#ifndef BOARD_H
#define BOARD_H

// TicTacToe
namespace ttt {

	#define EMPTY -1
	#define O 0 
	#define X 1	
	#define SIZE 9

	class Board {
	private:
		int board[SIZE];	
	public:
		Board(); // The board constructor 		
		bool placePiece(int type, int location);
		int * getBoard();
		void printBoard(); // write board content to terminal 
	};	
}

#endif