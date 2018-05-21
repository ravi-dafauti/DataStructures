/*
Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) 
then make all the cells of ith row and jth column as 1.

Example 1
The matrix
1 0
0 0
should be changed to following
1 1
1 0

Example 2
The matrix
0 0 0
0 0 1
should be changed to following
0 0 1
1 1 1

Example 3
The matrix
1 0 0 1
0 0 1 0
0 0 0 0
should be changed to following
1 1 1 1
1 1 1 1
1 0 1 1

*/


#include <iostream>
using namespace std;
#define R 3
#define C 4

void modifyMatrix(int mat[R][C])
{
	int row_flag, col_flag;
	row_flag = col_flag = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (i == 0 && mat[i][j] == 1)
				row_flag = 1;
			if (j == 0 && mat[i][j] == 1)
				col_flag = 1;
			else
			{
				if (mat[i][j] == 1)
				{
					mat[i][0] = 1;
					mat[0][j] = 1;
				}
			}
		}
	}
	for (int i = 1; i < R; i++)
	{
		for (int j = 1; j < C; j++)
		{
			if (mat[i][0] == 1 || mat[0][j] == 1)
				mat[i][j] = 1;
		}
	}
	if (col_flag == 1)
	{
		for (int i = 0; i < R; i++)
		{
			mat[i][0] = 1;
		}
	}
	if (row_flag == 1)
	{
		for (int i = 0; i < C; i++)
		{
			mat[0][i] = 1;
		}
	}
}

void printMatrix(int mat[R][C])
{
	int i, j;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int mat[R][C] = { { 1, 0, 0, 1 },
	{ 0, 0, 1, 0 },
	{ 0, 0, 0, 0 },
	};

	cout << "Input Matrix \n";
	printMatrix(mat);

	modifyMatrix(mat);

	cout << "Matrix after modification \n";
	printMatrix(mat);

	return 0;
}

