#include<iostream>
#include<stack>
using namespace std;

void stockSpan(int price[], int span[], int n)
{
	stack<int> mystack;
	for (int i = 0; i < n; i++)
	{
		int p;
		while (!mystack.empty() && price[mystack.top()] <= price[i])
		{
			mystack.pop();
		}
		if (mystack.empty())
		{
			p = -1;
		}
		else
		{
			p = mystack.top();
		}
		span[i] = i - p;
		mystack.push(i);
	}
}

int main()
{
	int price[] = { 10, 4, 5, 90, 120, 80 };
	int n = sizeof(price) / sizeof(price[0]);
	int *span = (int *)malloc(sizeof(int)*n);
	stockSpan(price, span, n);
	cout << "price is \n";
	for (int i = 0; i < n; i++)
	{
		cout << price[i] << " ";
	}
	cout << "\n";
	cout << "span is :\n";
	for (int i = 0; i < n; i++)
	{
		cout << span[i] << " ";
	}
	cout << "\n";
	return 0;
}