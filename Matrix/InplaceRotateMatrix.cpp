/*
Given an square matrix, turn it by 90 degrees in anti-clockwise direction without using any extra space.

Examples:

Input
1  2  3
4  5  6
7  8  9

Output:
3  6  9
2  5  8
1  4  7

Input:
1  2  3  4
5  6  7  8
9 10 11 12
13 14 15 16

Output:
4  8 12 16
3  7 11 15
2  6 10 14
1  5  9 13
*/


#include <iostream>
#define N 4
using namespace std;

void displayMatrix(int mat[N][N]);

void rotateMatrix(int mat[][N])
{
	for (int x = 0; x < N / 2; x++)
	{
		for (int y = x; y < N - x - 1; y++)
		{
			int temp = mat[x][y];
			mat[x][y] = mat[y][N - x - 1];
			mat[y][N - x - 1] = mat[N - x - 1][N - y - 1];
			mat[N - x - 1][N - y - 1] = mat[N - y - 1][x];
			mat[N - y - 1][x] = temp;
		}
	}
}


void displayMatrix(int mat[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << mat[i][j] << " ";

		cout << endl;
	}
	cout << endl;
}


int main()
{
	// Test Case 1
	int mat[N][N] =
	{
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15, 16 }
	};


	// Tese Case 2
	/* int mat[N][N] = {
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9}
	};
	*/

	// Tese Case 3
	/*int mat[N][N] = {
	{1, 2},
	{4, 5}
	};*/

	displayMatrix(mat);

	rotateMatrix(mat);

	// Print rotated matrix
	displayMatrix(mat);

	return 0;
}

