#include<iostream>
#define MAX 999999
using namespace std;

bool isPowerOfTwo(int n)
{
	while (n % 2 == 0)
	{
		n = n / 2;
	}
	if (n == 1)
		return true;
	return false;
}
int nextPowerOfTwo(int n)
{
	while (!isPowerOfTwo(n))
		n++;
	return n;
}
int lenghtOfTree(int n)
{
	int lenght_of_tree;
	if (isPowerOfTwo(n))
		lenght_of_tree = n * 2 - 1;
	else
		lenght_of_tree = nextPowerOfTwo(n) * 2 - 1;
	return lenght_of_tree;
}
int minimum(int a, int b)
{
	if (a<b)
		return a;
	return b;
}
int createSegmentTreeUtil(int arr[], int segmentTree[], int low, int high, int pos)
{
	if (low > high)
		return MAX;
	if (low == high)
	{
		segmentTree[pos] = arr[low];
		return arr[low];
	}
	int mid = (low + high) / 2;
	segmentTree[pos] = createSegmentTreeUtil(arr, segmentTree, low, mid, 2 * pos + 1) + createSegmentTreeUtil(arr, segmentTree, mid + 1, high, 2 * pos + 2);
	return segmentTree[pos];
}
int *createSegmentTree(int arr[], int n)
{
	int *segmentTree;
	int lenght_of_tree = lenghtOfTree(n);
	segmentTree = (int *)malloc(sizeof(int)*lenght_of_tree);
	createSegmentTreeUtil(arr, segmentTree, 0, n - 1, 0);
	return segmentTree;
}

int updateSegmentTree(int segmentTree[], int low, int high, int data, int pos, int index)
{
	if (pos<low || pos > high)
		return segmentTree[index];
	if (low == high)
	{
		segmentTree[index] = segmentTree[index] + data;
		return segmentTree[index];
	}
	int mid = (low + high) / 2;
	segmentTree[index] = updateSegmentTree(segmentTree, low, mid, data, pos, 2 * index + 1) + updateSegmentTree(segmentTree, mid + 1, high, data, pos, 2 * index + 2);
	return segmentTree[index];
}

int updateRangeInSegmentTree(int segmentTree[], int plow, int phigh, int low, int high, int data, int pos)
{
	if (plow > high || phigh < low)
		return segmentTree[pos];
	if (low == high)
	{
		segmentTree[pos] += data;
		return segmentTree[pos];
	}
	int mid = (low + high) / 2;
	return segmentTree[pos] = updateRangeInSegmentTree(segmentTree, plow, phigh, low, mid, data, pos * 2 + 1) + updateRangeInSegmentTree(segmentTree, plow, phigh, mid + 1, high, data, pos * 2 + 2);
}
int SumInRange(int segmentTree[], int qlow, int qhigh, int low, int high, int pos)
{
	if (qlow <= low&&qhigh >= high)
		return segmentTree[pos];
	if (qhigh <low || qlow>high)
		return 0;
	int mid = (low + high) / 2;
	return SumInRange(segmentTree, qlow, qhigh, low, mid, 2 * pos + 1) + SumInRange(segmentTree, qlow, qhigh, mid + 1, high, 2 * pos + 2);
}
void traverse(int *tree, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << tree[i] << " ";
	}
	cout << "\n";
}
int main()
{
	int arr[] = { 0, 1, 2, 3 };
	int *segmentTree = createSegmentTree(arr, 4);
	cout << "sum in range [1,3] before update is : ";
	cout << SumInRange(segmentTree, 1, 3, 0, 3, 0); // sum in range [1,3]
	//updateSegmentTree(segmentTree, 0, 3, 2, 2, 0);
	updateRangeInSegmentTree(segmentTree, 0, 3, 0, 3, 2, 0);
	cout << "\n";
	cout << "sum in range [1,3] after update is : ";
	cout << SumInRange(segmentTree, 1, 3, 0, 3, 0); // sum in range [1,3]
	return 0;
}
