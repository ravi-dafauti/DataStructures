/*
n a party of N people, only one person is known to everyone.
Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. We can only ask questions like “does A know B? “.
Find the stranger (celebrity) in minimum number of questions.

We can describe the problem input as an array of numbers/characters representing persons in the party. 
We also have a hypothetical function HaveAcquaintance(A, B) which returns true if A knows B, false otherwise. How can we solve the problem.
*/

#include<iostream>
#include<stack>
using namespace std;

// Max # of persons in the party
#define N 8

// Person with 2 is celebrity
bool  MATRIX[N][N] = { { 0, 0, 1, 0 },
{ 0, 0, 1, 0 },
{ 0, 0, 0, 0 },
{ 0, 0, 1, 0 } };

bool knows(int a, int b)
{
	return MATRIX[a][b];
}
int findCelebrity(int n)
{
	stack<int> mS;
	for (int i = 1; i <= n; i++)
		mS.push(i);
	int A, B, C;
	if (mS.size() > 2)
	{
		A = mS.top();
		mS.pop();
		B = mS.top();
		mS.pop();
		while (mS.size() > 1)
		{
			if (knows(A, B))
			{
				A = mS.top();
				mS.pop();
			}
			else
			{
				B = mS.top();
				mS.pop();
			}
		}
		C = mS.top();
		mS.pop();
		if (knows(C,A))
		{
			C = A;
		}
		if (knows(C, B))
		{
			C = B;
		}
		for (int i = 1; i <= n; i++)
		{
			if (i != C && (knows(C, i) || !(i, C)))
				return -1;
		}
	}
	return C;
}
int main()
{
	int n = 4;
	int id = findCelebrity(n);
	id == -1 ? cout << "No celebrity" : cout << "Celebrity ID " << id;
    return 0;
}

