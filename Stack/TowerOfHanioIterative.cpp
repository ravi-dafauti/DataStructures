#include<iostream>
#include<stack>
using namespace std;

int power(int a, int b)
{
	int ans = 1;
	for (int i = 1; i <= b; i++)
		ans *= a;
	return ans; 
}
void legalMove(stack<int> &a, stack<int> &b)
{
	int aTop, bTop;
	if (!a.empty() && !b.empty())
	{
		aTop = a.top();
		bTop = b.top();
		if (aTop < bTop)
		{
			a.pop();
			b.push(aTop);
		}
		else
		{
			b.pop();
			a.push(bTop);
		}
	}
	else if (a.empty())
	{
		bTop = b.top();
		b.pop();
		a.push(bTop);
	}
	else if (b.empty())
	{
		aTop = a.top();
		a.pop();
		b.push(aTop);
	}
}
void towerOfHanoi(stack<int> &s, stack<int> &a, stack<int> &d)
{
	int n = s.size();
	int moves = power(2, n) - 1;
	for (int i = 1; i <= moves; i++)
	{
		switch (i % 3)
		{
		case 1:
			if (n % 2 != 0)
				legalMove(s, d);
			else
				legalMove(s, a);
			break;
		case 2:
			if (n % 2 != 0)
				legalMove(s, a);
			else
				legalMove(s, d);
			break;
		case 0:
			legalMove(a, d);
			break;
		}
	}
}
int main()
{
	stack<int> source;
	stack<int> destination;
	stack<int> auxillary;
	source.push(4);
	source.push(3);
	source.push(2);
	source.push(1);
	towerOfHanoi(source, auxillary, destination);
	cout << destination.top();
	destination.pop();
	cout << destination.top();
	destination.pop();
	cout << destination.top();
	destination.pop();
	cout << destination.top();
	destination.pop();
	return 0;
}

