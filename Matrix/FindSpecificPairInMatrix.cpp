/*
Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.

Example:

Input:
mat[N][N] = {{ 1, 2, -1, -4, -20 },
{ -8, -3, 4, 2, 1 },
{ 3, 8, 6, 1, 3 },
{ -4, -1, 1, 7, -6 },
{ 0, -4, 10, -5, 1 }};
Output: 18
The maximum value is 18 as mat[4][2]
- mat[1][0] = 18 has maximum difference.
*/

#include<iostream>
#define N 5
using namespace std;

int maximum(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int findMaxValue(int mat[][N])
{
	int **aux = new int*[N];
	for (int i = 0; i < N; i++)
	{
		aux[i] = new int[N];
	}
	int max = mat[N - 1][N - 1];
	for (int i = N - 2; i >= 0; i--)
	{
		if (mat[N - 1][i] > max)
			max = mat[N - 1][i];
		aux[N - 1][i] = max;
	}
	max = mat[N - 1][N - 1];
	for (int i = N-2; i >=0; i--)
	{
		if (mat[i][N - 1] > max)
			max = mat[i][N - 1];
		aux[i][N - 1] = max;
	}
	int max_val = INT_MIN;
	for (int i = N - 2; i >= 0; i--)
	{
		for (int j = N - 2; j >= 0; j--)
		{
			if (aux[i + 1][j + 1] - mat[i][j] > max_val)
				max_val = aux[i + 1][j + 1] - mat[i][j];
			aux[i][j] = maximum(mat[i][j], maximum(aux[i + 1][j], aux[i][j + 1]));
		}
	}
	return max_val;
}
int main()
{
	int mat[N][N] = {
                      { 1, 2, -1, -4, -20 },
                      { -8, -3, 4, 2, 1 },
                      { 3, 8, 6, 1, 3 },
                      { -4, -1, 1, 7, -6 },
                      { 0, -4, 10, -5, 1 }
                    };
	cout << "Maximum Value is " << findMaxValue(mat);
    return 0;
}

