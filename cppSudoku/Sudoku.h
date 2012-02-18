#pragma once

#include "Field.h"

#define MAX_WIDTH  9
#define MAX_HEIGHT 9

class Sudoku
{

private:
	Field matrix[MAX_WIDTH][MAX_HEIGHT];

	bool solveRecursive(int x, int y);

public:
	Sudoku(void);
	Sudoku(int matrix[MAX_WIDTH][MAX_HEIGHT]);
	Sudoku(Field matrix[MAX_WIDTH][MAX_HEIGHT]);

	~Sudoku(void);

	bool isSolved();
	bool solve();

	std::vector<int> getAvailableNumbers(int x, int y);

	Field getField(int x, int y);
};

