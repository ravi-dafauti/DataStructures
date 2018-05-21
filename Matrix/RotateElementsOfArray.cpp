/*
Given a matrix, clockwise rotate elements in it.

Examples:

Input
1    2    3
4    5    6
7    8    9

Output:
4    1    2
7    5    3
8    9    6

For 4*4 matrix
Input:
1    2    3    4
5    6    7    8
9    10   11   12
13   14   15   16

Output:
5    1    2    3
9    10   6    4
13   11   7    8
14   15   16   12

*/

#include<iostream>
using namespace std;
#define R 4
#define C 4
void rotatematrix(int mat[][C])
{
	int re, rs, ce, cs;
	rs = cs = 0;
	re = R - 1;
	ce = C - 1;
	while (rs <= re&&cs <= ce)
	{
		int temp = mat[rs+1][cs];
		int i = cs;
		while (i <= ce)
		{
			int t = mat[rs][i];
			mat[rs][i] = temp;
			temp = t;
			i++;
		}
		rs++;
		i = rs;
		while (i <= re)
		{
			int t = mat[i][ce];
			mat[i][ce] = temp;
			temp = t;
			i++;
		}
		ce--;
		if (cs <= ce)
		{
			i = ce;
			while (i >= cs)
			{
				int t = mat[re][i];
				mat[re][i] = temp;
				temp = t;
				i--;
			}
			re--;
		}
		if (rs <= re)
		{
			i = re;
			while (i >= rs)
			{
				int t = mat[i][cs];
				mat[i][cs] = temp;
				temp = t;
				i--;
			}
			mat[rs - 1][cs] = temp;
			cs++;
		}
	}
}
int main()
{
	// Test Case 1
	int a[R][C] = { { 1,  2,  3,  4 },
	{ 5,  6,  7,  8 },
	{ 9,  10, 11, 12 },
	{ 13, 14, 15, 16 } };

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	rotatematrix(a);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	// Tese Case 2
	/* int a[R][C] = {{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9}
	};
	*/  rotatematrix(a);
    return 0;
}

