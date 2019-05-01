#include "Board.cpp" // note - bad practice, use header files instead 
#include <iostream> 

using namespace std; 
using namespace ttt;

int main() {
	// Start new game
	ttt::Board board;

	board.placePiece(0, 2);

	return 0;
};