#include<iostream>
#include<queue>
#include<functional>
using namespace std;

void sortK(int arr[], int n, int k)
{
	int i, j;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (i = 0; i <= k&&i < n; i++)
	{
		pq.push(arr[i]);
	}
	for (i = 0, j = k + 1; i < n&&j<n; i++, j++)
	{
		arr[i] = pq.top();
		pq.pop();
		pq.push(arr[j]);
	}
	while (!pq.empty())
	{
		arr[i] = pq.top();
		pq.pop();
		i++;
	}
}

int main()
{
	int k = 3;
	int arr[] = { 2, 6, 3, 12, 56, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	sortK(arr, n, k);
	cout << "sorted array is\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}