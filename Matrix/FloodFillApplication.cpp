/*
Given a matrix where every element is either ‘O’ or ‘X’, replace ‘O’ with ‘X’ if surrounded by ‘X’. A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below, just above, just left and just right of it.

Examples:

Input: mat[M][N] =  {{'X', 'O', 'X', 'X', 'X', 'X'},
{'X', 'O', 'X', 'X', 'O', 'X'},
{'X', 'X', 'X', 'O', 'O', 'X'},
{'O', 'X', 'X', 'X', 'X', 'X'},
{'X', 'X', 'X', 'O', 'X', 'O'},
{'O', 'O', 'X', 'O', 'O', 'O'},
};
Output: mat[M][N] =  {{'X', 'O', 'X', 'X', 'X', 'X'},
{'X', 'O', 'X', 'X', 'X', 'X'},
{'X', 'X', 'X', 'X', 'X', 'X'},
{'O', 'X', 'X', 'X', 'X', 'X'},
{'X', 'X', 'X', 'O', 'X', 'O'},
{'O', 'O', 'X', 'O', 'O', 'O'},
};
*/

#include<iostream>
using namespace std;

#define M 6
#define N 6

void floodFill(char mat[][N], int x, int y, char prev, char newc)
{
	if (x < 0 || x >= M || y < 0 || y >= N)
		return;
	if (mat[x][y] != prev)
		return;
	mat[x][y] = newc;
	floodFill(mat, x + 1, y, prev, newc);
	floodFill(mat, x, y + 1, prev, newc);
	floodFill(mat, x - 1, y, prev, newc);
	floodFill(mat, x, y - 1, prev, newc);
}
void replaceSurrounded(char mat[][N])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (mat[i][j] == 'O')
				mat[i][j] = '-';
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (mat[0][i] == '-')
			floodFill(mat, 0, i, '-', 'O');
	}
	for (int i = 1; i < M; i++)
	{
		if (mat[i][N - 1] == '-')
			floodFill(mat, i, N - 1, '-', 'O');
	}
	for (int i = N-1; i >= 0; i--)
	{
		if (mat[M-1][i] == '-')
			floodFill(mat, M-1, i, '-', 'O');
	}
	for (int i = M-2; i >=0; i--)
	{
		if (mat[i][0] == '-')
			floodFill(mat, i, 0, '-', 'O');
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (mat[i][j] == '-')
				mat[i][j] = 'X';
		}
	}
}
int main()
{
	char mat[][N] = { { 'X', 'O', 'X', 'O', 'X', 'X' },
	{ 'X', 'O', 'X', 'X', 'O', 'X' },
	{ 'X', 'X', 'X', 'O', 'X', 'X' },
	{ 'O', 'X', 'X', 'X', 'X', 'X' },
	{ 'X', 'X', 'X', 'O', 'X', 'O' },
	{ 'O', 'O', 'X', 'O', 'O', 'O' },
	};

	cout << "before\n";
	for (int i = 0; i<M; i++)
	{
		for (int j = 0; j<N; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	cout << "after\n";
	replaceSurrounded(mat);


	for (int i = 0; i<M; i++)
	{
		for (int j = 0; j<N; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
    return 0;
}

