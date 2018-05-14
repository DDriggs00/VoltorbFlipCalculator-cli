#include <iostream>
#include <vector>

#include "cell.h"
#include "board.h"

using namespace std;

//0. Error check;
//1. generate board;
//2. generate all possible boards
//3. do stats
//4. do gui

int main() {

	board Board;

	Board.VerifyInput();
	Board.Initialize();
	Board.Display();

	return 0;
}

