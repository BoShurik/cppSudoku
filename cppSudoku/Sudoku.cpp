#include "StdAfx.h"
#include "Sudoku.h"

Sudoku::Sudoku(void)
{
	for (int i = 0; i < MAX_HEIGHT; i++)
    {
        for (int j = 0; j < MAX_WIDTH; j++)
        {
			this->matrix[j][i] = Field();
        }
    }
}

Sudoku::Sudoku(int matrix[MAX_HEIGHT][MAX_WIDTH])
{
	for (int i = 0; i < MAX_HEIGHT; i++)
    {
        for (int j = 0; j < MAX_WIDTH; j++)
        {
			Field field = {matrix[j][i], (matrix[j][i] == 0) ? true : false};
			this->matrix[j][i] = field;
        }
    }
}

Sudoku::Sudoku(Field matrix[MAX_HEIGHT][MAX_WIDTH])
{
	for (int i = 0; i < MAX_HEIGHT; i++)
    {
        for (int j = 0; j < MAX_WIDTH; j++)
        {
			this->matrix[j][i] = matrix[j][i];
        }
    }
}

Sudoku::~Sudoku(void)
{
}

bool Sudoku::isSolved()
{
	for (int i = 0; i < MAX_HEIGHT; i++)
    {
        for (int j = 0; j < MAX_WIDTH; j++)
        {
			if (this->matrix[j][i].number == 0)
            {
                return false;
            }
        }
    }

    for (int i = 0; i < MAX_HEIGHT; i++)
    {
		std::vector<int> colNumbers;
        for (int j = 0; j < MAX_WIDTH; j++)
        {
			if (std::find(colNumbers.begin(), colNumbers.end(), this->matrix[j][i].number) != colNumbers.end())
			{
				return false;
			}

            colNumbers.push_back(this->matrix[j][i].number);
        }
    }

    for (int i = 0; i < MAX_HEIGHT; i++)
    {
        std::vector<int> rowNumbers;
        for (int j = 0; j < MAX_WIDTH; j++)
        {
            if (std::find(rowNumbers.begin(), rowNumbers.end(), this->matrix[i][j].number) != rowNumbers.end())
            {
                return false;
            }

			rowNumbers.push_back((this->matrix[i][j]).number);
        }
    }

    for (int q = 0; q < 9; q++)
    {
        int ki = q % 3;
        int kj = q / 3;

        for (int i = 0; i < 3; i++)
        {
            std::vector<int> squareNumbers;
            for (int j = 0; j < 3; j++)
            {
                if (std::find(squareNumbers.begin(), squareNumbers.end(), this->matrix[j + 3 * kj][i + 3 * ki].number) != squareNumbers.end())
				{
					return false;
				}

				squareNumbers.push_back(this->matrix[j + 3 * kj][i + 3 * ki].number);
            }
        }
    }

    return true;
}

bool Sudoku::solveRecursive(int x, int y)
{
	bool final = false;

    int nextX = (x + 1) % MAX_WIDTH;
	int nextY;

    if (((x + 1) / MAX_WIDTH) >= 1)
    {
        nextY = y + 1;
        if ((nextY / MAX_WIDTH) >= 1)
        {
            final = true;
        }
    }
    else
    {
        nextY = y;
    }

    if (this->matrix[x][y].changeable == true)
    {
		std::vector<int> availableNumbers = this->getAvailableNumbers(x, y);

		for(int i = 0; i < availableNumbers.size(); i++) 
		{
			int number = availableNumbers.at(i);

			this->matrix[x][y].number = number;
            if (!final)
            {
                bool result = this->solveRecursive(nextX, nextY);
                if (result)
                {
                    return true;
                }
                else
                {
					this->matrix[x][y].number = 0;
                }
            }
            else
            {
                bool result = this->isSolved();
                if (result)
                {
                    return true;
                }
            }
		}

        return false;
    }

    if (!final)
    {
        return this->solveRecursive(nextX, nextY);
    }
    else
    {
		return this->isSolved();
    }
}

bool Sudoku::solve()
{
	return this->solveRecursive(0, 0);
}

std::vector<int> Sudoku::getAvailableNumbers(int x, int y)
{
	std::vector<int> availableNumbers;
	
	if (this->matrix[x][y].changeable == false)
    {
        return availableNumbers;
    }

	for (int i = 1; i <= 9; i++)
	{
		availableNumbers.push_back(i);
	}

    for (int i = 0; i < MAX_WIDTH; i++)
    {
        if (i != x)
        {
            std::vector<int>::iterator key = std::find(availableNumbers.begin(), availableNumbers.end(), this->matrix[x][i].number);
			if (key != availableNumbers.end())
            {
				availableNumbers.erase(key);
            }
        }
    }

	if (availableNumbers.empty())
    {
        return availableNumbers;
    }

    for (int i = 0; i < MAX_HEIGHT; i++)
    {
        if (i != y)
        {
            std::vector<int>::iterator key = std::find(availableNumbers.begin(), availableNumbers.end(), this->matrix[i][y].number);
			if (key != availableNumbers.end())
            {
				availableNumbers.erase(key);
            }
        }
    }

    if (availableNumbers.empty())
    {
        return availableNumbers;
    }

    int ki = y / 3;
    int kj = x / 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((i + 3 * ki != y) && (j + 3 * kj != x))
            {
                std::vector<int>::iterator key = std::find(availableNumbers.begin(), availableNumbers.end(), this->matrix[j + 3 * kj][i + 3 * ki].number);
				if (key != availableNumbers.end())
				{
					availableNumbers.erase(key);
				}
            }
        }
    }

    return availableNumbers;
}

Field Sudoku::getField(int x, int y)
{
	return this->matrix[x][y];
}