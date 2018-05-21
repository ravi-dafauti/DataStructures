/*
Given a matrix where every row is sorted in increasing order. Write a function that finds and returns a common element in all rows. If there is no common element, then returns -1.

Example:

Input: mat[4][5] = { {1, 2, 3, 4, 5},
{2, 4, 5, 8, 10},
{3, 5, 7, 9, 11},
{1, 3, 5, 7, 9},
};
Output: 5
*/

#include<iostream>
#define M 4
#define N 5
using namespace std;

int findCommon(int mat[][N])
{
	int *col = new int[M];
	for (int i = 0; i < M; i++)
		col[i] = N - 1;
	int min_row = 0;
	while (col[min_row] >= 0)
	{
		for (int i = 0; i < M; i++)
		{
			if (mat[i][col[i]] < mat[min_row][col[min_row]])
			{
				min_row = i;
			}
		}
		int count = 0;
		for (int i = 0; i < M; i++)
		{
			if (mat[i][col[i]] > mat[min_row][col[min_row]])
			{
				if (col[i] == 0)
					return -1;
				col[i]--;
			}
			else
				count++;
		}
		if (count == M)
			return mat[min_row][col[min_row]];
	}
	return -1;
}
int main()
{
	int mat[M][N] = { { 1, 2, 3, 4, 5 },
	{ 2, 4, 5, 8, 10 },
	{ 3, 5, 7, 9, 11 },
	{ 1, 3, 5, 7, 9 },
	};
	int result = findCommon(mat);
	if (result == -1)
		printf("No common element");
	else
		printf("Common element is %d", result);
	return 0;
}

