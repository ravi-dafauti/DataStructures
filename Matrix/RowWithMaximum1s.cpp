/*
Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s.

Example
Input matrix
0 1 1 1
0 0 1 1
1 1 1 1  // this row has maximum 1s
0 0 0 0

Output: 2
*/


#include <iostream>
using namespace std;

#define R 4
#define C 4

int rowWithMax1s(int mat[R][C])
{
	int i, j;
	i = 0; 
	j = C - 1;
	int maxcount, maxRow;
	maxcount = 0;
	maxRow = 0;
	while (i < R&&j >= 0)
	{
		if (mat[i][j] == 1)
		{
			maxcount++;
			maxRow = i;
			j--;
		}
		else
		{
			i++;
		}
	}
	return maxRow;
}

// Driver Code
int main()
{
	int mat[R][C] = { { 0, 0, 0, 1 },
	{ 0, 1, 1, 1 },
	{ 1, 1, 1, 1 },
	{ 0, 0, 0, 0 } };

	cout << "Index of row with maximum 1s is : " << rowWithMax1s(mat);

	return 0;
}

