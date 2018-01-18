/* given nos 1,2,3....n how many BST are possible */

#include<iostream>
using namespace std;

int noOfBSTs(int N)
{
	int total = 0;
	if (N <= 1)
		return 1;
	int l, r;
	for (int i = 1; i <= N; i++)
	{
		l = noOfBSTs(i - 1);
		r = noOfBSTs(N - i);
		total += l*r;
	}
	return total;
}
int main()
{
	int N = 3;
	cout << noOfBSTs(N);
	return 0;
}