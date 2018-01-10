#include<iostream>
#include<stack>
using namespace std;

void nextGreaterInt(int arr[], int n)
{
	int *greaterInt = (int *)malloc(sizeof(int)*n);
	stack<int> mystack;
	for (int i = n - 1; i >= 0; i--)
	{
		while (!mystack.empty() && mystack.top() <= arr[i])
		{
			mystack.pop();
		}
		if (mystack.empty())
			greaterInt[i] = -1;
		else
			greaterInt[i] = mystack.top();
		mystack.push(arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " -> " << greaterInt[i] << "\n";
	}
}
int main()
{
	int arr[] = { 11, 13, 21, 3 };
	nextGreaterInt(arr, sizeof(arr) / sizeof(int));
	return 0;
}
