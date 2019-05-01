#include <iostream>
#include <string>

using namespace std;

// TicTacToe
namespace ttt {

	#define EMPTY -1
	#define O 0 
	#define X 1	
	#define SIZE 9

	class Board {
		// Generate matrix
		// -1 is empty
		// 0 is O piece
		// 1 is X piece 
		// maybe declare these values as constants 
		// [-1 -1 -1]	
		// [0  -1  1]
		// [1   0  1]

	public:
		Board(); // The board constructor 		
		bool placePiece(int type, int location);
		int * getBoard();
		void printBoard(); // write board content to terminal 
	private:
		int board[SIZE];
		//int board[3][3];
	};	

	// Member functions
	Board::Board() {
		cout << "Creating empty tic-tac-toe board." << endl;
		// location 0-8 list or [0,2] matrix style?
		//board = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
		for (int i = 0; i < SIZE; i++) {
			board[i] = -1;
		}

		printBoard(); // Show an empty board in terminal
	}

	bool Board::placePiece(int type, int location) {
			if (board[location] != EMPTY) {
				return false;
			}
			if (type != X && type != O) {
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

	void Board::printBoard() {
		for (int i = 0; i < SIZE; i++) {
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

}