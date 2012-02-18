#pragma once

#define MAX_WIDTH  9
#define MAX_HEIGHT 9

class Sudoku
{

private:
	int matrix[MAX_WIDTH][MAX_HEIGHT];

	bool solveRecursive(int x, int y);

public:
	Sudoku(void);
	~Sudoku(void);

	bool isSolved();
	bool solve();

	int getAvailableNumbers(int x, int y);

	int getField(int x, int y);
};

