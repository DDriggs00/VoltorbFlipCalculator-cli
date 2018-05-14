#include <iostream>

#include "cell.h"

const int CELLS_PER_ROW = 5; //(5x5 grid by default)

cell::cell()
{
	voltorb = true;
	one = true;
	two = true;
	three = true;
}


cell::~cell()
{
}

void cell::disable(int val)
{
	switch (val)
	{
	case 0: 
		voltorb= false;
		break;
	case 1:
		one = false;
		break;
	case 2:
		two = false;
		break;
	case 3:
		three = false;
		break;
	default:
		break;
	}
}

void cell::PrintCell()
{
	if (voltorb) {
		std::cout << "V";
	}
	else {
		std::cout << " ";
	}
	if (one) {
		std::cout << "1";
	}
	else {
		std::cout << " ";
	}
	if (two) {
		std::cout << "2";
	}
	else {
		std::cout << " ";
	}
	if (three) {
		std::cout << "3";
	}
	else {
		std::cout << " ";
	}
}

void cell::FindPossibleVals(int rowTotal, int rowVoltorbs, int colTotal, int colVoltorbs) {

	FindPossibleRowVals(rowTotal, rowVoltorbs);
	FindPossibleRowVals(colTotal, colVoltorbs);
}

void cell::FindPossibleRowVals(int total, int voltorbs) {

	// Rule 1: All Voltorb (this rule returns)
	if (voltorbs == CELLS_PER_ROW) {
		one = false;
		two = false;
		three = false;
	}

	// Rule 2: No Voltorb
	if (voltorbs == 0) {
		voltorb = false;
	}

	// Rule 3: total 5 (this rule returns)
	if ((total + voltorbs) == CELLS_PER_ROW) {
		two = false;
		three = false;
	}

	// Rule 4: 4 Voltorb
	if (voltorbs == (CELLS_PER_ROW - 1)) {
		switch (total) {
		case 1:
			two = false;
			three = false;
			break;
		case 2:
			one = false;
			three = false;
			break;
		case 3:
			one = false;
			two = false;
			break;
		default:
			break;
		}
	}

	// Rule 5: Total 6
	if ((total + voltorbs) == (CELLS_PER_ROW + 1)) {
		three = false;
	}

	// Rule 6: Too High for 2's
	int numberCells = CELLS_PER_ROW - voltorbs;
	int addlPoints = total - numberCells;
	if (addlPoints == (numberCells * 2)) {
		// All cells must be 3 or 0
		one = false;
		two = false;
	}

	// Rule 7: Too High for 1's
	if ((addlPoints + 1) == (numberCells * 2)) {
		// 1's not possible
		one = false;
	}

	// Rule 8: Eliminate the Impossible
	// Rule 9: Whatever remains...
	// Rule 10: Cannot be Voltorb
}

int cell::CountPossibleVals()
{
	int numValues = 0;
	if (voltorb) {
		numValues++;
	}
	if (one) {
		numValues++;
	}
	if (two) {
		numValues++;
	}
	if (three) {
		numValues++;
	}
	return numValues;
}
