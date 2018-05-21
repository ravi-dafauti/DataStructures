/*
Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.

Example:

Input:
mat[4][5] = {{1, 2, 1, 4, 8},
{3, 7, 8, 5, 1},
{8, 7, 7, 3, 1},
{8, 1, 2, 7, 9},
};

Output:
1 8 or 8 1
8 and 1 are present in all rows.
*/
#include<iostream>
#include<unordered_set>
#define M 4
#define N 5
using namespace std;
void printCommonElements(int mat[][N])
{
	unordered_set<int> s1;
	unordered_set<int> s2;
	for (int i = 0; i < N; i++)
		s1.insert(mat[0][i]);
	for (int i = 1; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (s1.find(mat[i][j]) != s1.end())
			{
				s2.insert(mat[i][j]);
			}
		}
		s1.swap(s2);
		s2.clear();
	}
	cout << "common elements are: \n";
	unordered_set<int>::iterator it;
	for (it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
}
int main()
{
	int mat[M][N] =
	{
		{ 1, 2, 1, 4, 8 },
		{ 3, 7, 8, 5, 1 },
		{ 8, 7, 7, 3, 1 },
		{ 8, 1, 2, 7, 9 },
	};

	printCommonElements(mat);

	return 0;
}