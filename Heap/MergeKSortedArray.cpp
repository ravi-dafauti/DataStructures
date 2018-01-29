#include<iostream>
#include<queue>
using namespace std;

struct Node
{
	int data;
	int i;
	int j;
};

class myComparator
{
public:
	int operator() (const Node& p1, const Node& p2)
	{
		return p1.data > p2.data;
	}
};
int *mergeKArrays(int arr[][4], int k)
{
	int i;
	int *output = (int *)malloc(sizeof(int) * 4 * k);
	priority_queue<Node, vector<Node>, myComparator> pq;
	for (i = 0; i < k; i++)
	{
		Node n;
		n.data = arr[i][0];
		n.i = i;
		n.j = 0;
		pq.push(n);
	}
	for (i = 0;!pq.empty(); i++)
	{
		output[i] = pq.top().data;
		int x, y;
		x = pq.top().i;
		y = pq.top().j;
		pq.pop();
		Node n;
		if (y < 3)
		{
			n.data = arr[x][y + 1];
			n.i = x;
			n.j = y + 1;
			pq.push(n);
		}
	}
	return output;
}
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
int main()
{
	int arr[][4] = { { 2, 6, 12, 34 },
	{ 1, 9, 20, 1000 },
	{ 23, 34, 90, 2000 } };
	int k = sizeof(arr) / sizeof(arr[0]);

	int *output = mergeKArrays(arr, k);

	cout << "Merged array is " << endl;
	printArray(output, 4*k);
	return 0;
}