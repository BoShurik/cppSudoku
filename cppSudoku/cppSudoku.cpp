// cppSudoku.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Sudoku.h"
#include <Windows.h>

void printSudoku(Sudoku sudoku)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", sudoku.getField(j, i));
		}
		printf("\n");
	}
	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	int matrix[9][9];

	DWORD beginTime = GetTickCount();

	matrix[0][0] = 2; matrix[1][0] = 0; matrix[2][0] = 0; 
	matrix[3][0] = 0; matrix[4][0] = 0; matrix[5][0] = 0; 
	matrix[6][0] = 0; matrix[7][0] = 0; matrix[8][0] = 8; 

	matrix[0][1] = 0; matrix[1][1] = 0; matrix[2][1] = 0; 
	matrix[3][1] = 0; matrix[4][1] = 0; matrix[5][1] = 9; 
	matrix[6][1] = 3; matrix[7][1] = 0; matrix[8][1] = 0; 

	matrix[0][2] = 8; matrix[1][2] = 0; matrix[2][2] = 5; 
	matrix[3][2] = 3; matrix[4][2] = 6; matrix[5][2] = 0; 
	matrix[6][2] = 0; matrix[7][2] = 4; matrix[8][2] = 0; 

	matrix[0][3] = 0; matrix[1][3] = 3; matrix[2][3] = 0; 
	matrix[3][3] = 0; matrix[4][3] = 8; matrix[5][3] = 0; 
	matrix[6][3] = 5; matrix[7][3] = 0; matrix[8][3] = 0; 

	matrix[0][4] = 7; matrix[1][4] = 0; matrix[2][4] = 0; 
	matrix[3][4] = 0; matrix[4][4] = 0; matrix[5][4] = 0; 
	matrix[6][4] = 0; matrix[7][4] = 0; matrix[8][4] = 4; 

	matrix[0][5] = 0; matrix[1][5] = 0; matrix[2][5] = 4; 
	matrix[3][5] = 0; matrix[4][5] = 1; matrix[5][5] = 0; 
	matrix[6][5] = 0; matrix[7][5] = 7; matrix[8][5] = 0; 

	matrix[0][6] = 0; matrix[1][6] = 4; matrix[2][6] = 0; 
	matrix[3][6] = 0; matrix[4][6] = 5; matrix[5][6] = 7; 
	matrix[6][6] = 8; matrix[7][6] = 0; matrix[8][6] = 6; 

	matrix[0][7] = 0; matrix[1][7] = 0; matrix[2][7] = 1; 
	matrix[3][7] = 2; matrix[4][7] = 0; matrix[5][7] = 0; 
	matrix[6][7] = 0; matrix[7][7] = 0; matrix[8][7] = 0; 

	matrix[0][8] = 9; matrix[1][8] = 0; matrix[2][8] = 0; 
	matrix[3][8] = 0; matrix[4][8] = 0; matrix[5][8] = 0; 
	matrix[6][8] = 0; matrix[7][8] = 0; matrix[8][8] = 2; 

	Sudoku sudoku(matrix);

	printSudoku(sudoku);

	if (sudoku.solve())
	{
		printf("Done!\n");
	}
	else
	{
		printf("Fail!\n");
	}

	printSudoku(sudoku);

	printf("%ul\n", GetTickCount() - beginTime);
	
	return 0;
}

