#pragma once

#include "cell.h"

const int CELLS_PER_ROW = 5;

class board
{
public:
	board();
	~board();
	bool VerifyInput();
	void Display();
	void Initialize();
private:
	int rowTotals[CELLS_PER_ROW] = { 3,5,3,9,5 };   // Going down the right
	int rowVoltorbs[CELLS_PER_ROW] = { 2,1,2,0,1 };
	int colTotals[CELLS_PER_ROW] = { 4,8,4,8,1 };   // Across the bottom
	int colVoltorbs[CELLS_PER_ROW] = { 1,0,1,0,4 };

	cell Gameboard[CELLS_PER_ROW][CELLS_PER_ROW];		//The Actual Board
};

