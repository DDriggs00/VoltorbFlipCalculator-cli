#pragma once
class cell
{
public:
	cell();
	~cell();
	void disable(int val);
	void PrintCell();
	void FindPossibleVals(int rowTotal, int rowVoltorb, int colTotal, int colVoltorbs);
	void FindPossibleRowVals(int total, int voltorbs);
	int CountPossibleVals();
private:
	bool voltorb;
	bool one;
	bool two;
	bool three;
};

