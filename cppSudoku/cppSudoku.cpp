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
	if (argc != 2)
	{
		printf("Not enough parameters\n");
		return 0;
	}


	_TCHAR *initString = NULL;
	initString = (_TCHAR *)calloc(9 * 9 + 1, sizeof(_TCHAR));
	memcpy(initString, argv[1], 9 * 9 * sizeof(_TCHAR));

	int initStringLenght = _tcslen(initString);
	if (initStringLenght != (9 * 9))
	{
		printf("Lenght of the init string must be 81\n");
		return 0;
	}
	
	_TCHAR initChar[2] = _T("");
	int matrix[9][9];
	int x, y;
	
	for (int i = 0; i < initStringLenght; i++)
	{
		x = i % 9;
		y = i / 9;

		_stprintf(initChar, _T("%c"), initString[i]);

		matrix[x][y] = _ttoi(initChar);
	}

	LARGE_INTEGER li;
    QueryPerformanceFrequency(&li);

    double PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    __int64 CounterStart = li.QuadPart;

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

    QueryPerformanceCounter(&li);
    printf("%f\n", double(li.QuadPart-CounterStart) / PCFreq);
	
	return 0;
}

