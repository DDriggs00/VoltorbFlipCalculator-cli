#include <iostream>	// For cout
#include <conio.h>	// For _getch()

#include "board.h"
//#include "cell.h"

using namespace std;

board::board()
{
}


board::~board()
{
}

bool board::VerifyInput()
{
	// 1. Less than 5 total
	// 2. Too Many Voltorbs
	for (int i = 0; i < CELLS_PER_ROW; i++) 
	{
		if (rowTotals[i] + rowVoltorbs[i] < CELLS_PER_ROW) {
			return false;
		}
		if (colTotals[i] + colVoltorbs[i] < CELLS_PER_ROW) {
			return false;
		}
		if (rowVoltorbs[i] > CELLS_PER_ROW) {
			return false;
		}
		if (colVoltorbs[i] > CELLS_PER_ROW) {
			return false;
		}
	}
	// 2. Too large numbers
	for (int i = 0; i < CELLS_PER_ROW; i++) 
	{
		int rowNumberCells = CELLS_PER_ROW - rowVoltorbs[i];
		int colNumberCells = CELLS_PER_ROW - colVoltorbs[i];
		if (rowTotals[i] - 3 * rowNumberCells > 0) {
			return false;
		}
		if (colTotals[i] - 3 * colNumberCells > 0) {
			return false;
		}
	}
	// 3. different total in rows vs. Columns
	// 4. different number of Voltorbs in rows vs. Columns
	int totalRowValue = 0;
	int totalColValue = 0;
	int totalRowVoltorbs = 0;
	int totalColVoltorbs = 0;
	for (int i = 0; i < CELLS_PER_ROW; i++) 
	{
		totalRowValue += rowTotals[i];
		totalColValue += colTotals[i];
		totalRowVoltorbs += rowVoltorbs[i];
		totalColVoltorbs += colVoltorbs[i];
	}
	if (totalRowValue != totalColValue) {
		return false;
	}
	if (totalRowVoltorbs != totalColVoltorbs) {
		return false;
	}
	return true;
}

void board::Initialize()
{
	for (int i = 0; i < CELLS_PER_ROW; i++) 
	{
		for (int j = 0; j < CELLS_PER_ROW; j++) 
		{
			Gameboard[i][j].FindPossibleVals(rowTotals[i], rowVoltorbs[i], colTotals[j], colVoltorbs[j]);
		}
	}
}
void board::Display()
{
	cout << endl << endl;
	for (int i = 0; i < CELLS_PER_ROW; i++) 
	{
		for (int j = 0; j < CELLS_PER_ROW; j++) 
		{
			cout << i << j << ' ';
			Gameboard[i][j].PrintCell();
			cout << " ";
		}
		cout << endl;
	}
	_getch();
}
