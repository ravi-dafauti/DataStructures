/*input : 1 2 3 1 4 5 2 3 6
  output : 3 3 4 5 5 5 6*/

#include<iostream>
#include<deque>
using namespace std;

void slidingWindowMaximum(int arr[] ,int n, int k)
{
	deque<int> dq;
	for (int i = 0; i < k; i++)
	{
		while (!dq.empty() && arr[i] > arr[dq.front()])
		{
			dq.pop_front();
		}
		dq.push_back(i);
	}
	cout << arr[dq.front()] << " ";
	for (int i = 1; i + k - 1 < n; i++)
	{
		while (!dq.empty() && arr[i + k - 1] > arr[dq.front()])
		{
			dq.pop_front();
		}
		dq.push_back(i + k - 1);
		while ((i + k - 1) - dq.front() >= k)
		{
			dq.pop_front();
		}
		cout << arr[dq.front()] << " ";
	}
}
int main()
{
	int arr[] = { 8, 5, 10, 7, 9, 4, 15, 12, 90, 13 };
	int n = sizeof(arr) / sizeof(arr[0]);
	slidingWindowMaximum(arr, n, 4);
    return 0;
}

