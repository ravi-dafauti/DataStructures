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
	segmentTree[pos] = minimum(createSegmentTreeUtil(arr, segmentTree, low, mid, 2 * pos + 1), createSegmentTreeUtil(arr, segmentTree, mid + 1, high, 2 * pos + 2));
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
void traverse(int tree[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << tree[i] << " ";
	}
}
int main()
{
	int arr[] = { 0, -1, 2, 3 };
	int *tree = createSegmentTree(arr, 4);
	traverse(tree, lenghtOfTree(4));
	return 0;
}