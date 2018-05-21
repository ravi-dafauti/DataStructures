/*
Given a 2D array, print it in spiral form. See the following examples.

Input:
1    2   3   4
5    6   7   8
9   10  11  12
13  14  15  16
Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10


Input:
1   2   3   4  5   6
7   8   9  10  11  12
13  14  15 16  17  18
Output:
1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11
*/

#include<iostream>
using namespace std;
#define R 3
#define C 6

void spiralPrint(int a[R][C])
{
	int rs, re, cs, ce;
	rs = cs = 0;
	ce = C - 1;
	re = R - 1;
	while (rs <= re&&cs <= ce)
	{
		for (int i = cs; i <= ce; i++)
			cout << a[rs][i] << " ";
		rs++;
		for (int i = rs; i <= re; i++)
			cout << a[i][ce] << " ";
		ce--;
		if (re >= rs)
		{
			for (int i = ce; i >= cs; i--)
				cout << a[re][i] << " ";
			re--;
		}
		if (cs<=ce)
		{
			for (int i = re; i >= rs; i--)
				cout << a[i][cs] << " ";
			cs++;
		}
	}
}

/* Driver program to test above functions */
int main()
{
	int a[R][C] = { { 1,  2,  3,  4,  5,  6 },
	{ 7,  8,  9,  10, 11, 12 },
	{ 13, 14, 15, 16, 17, 18 }
	};

	spiralPrint(a);
	return 0;
}

