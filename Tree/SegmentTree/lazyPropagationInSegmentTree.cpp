#include<iostream>
#define MAX 999999
using namespace std;

struct SegmentTree
{
	int *mainTree;
	int *lazyTree;
};
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
SegmentTree *createSegmentTree(int arr[], int n)
{
	SegmentTree *s = (SegmentTree *)malloc(sizeof(SegmentTree));
	int lenght_of_tree = lenghtOfTree(n);
	s->mainTree = (int *)malloc(sizeof(int)*lenght_of_tree);
	s->lazyTree = (int *)malloc(sizeof(int)*lenght_of_tree);
	for (int i = 0; i < lenght_of_tree; i++)
		s->lazyTree[i] = 0;
	createSegmentTreeUtil(arr, s->mainTree, 0, n - 1, 0);
	return s;
}

void updateRangeInSegmentTree(SegmentTree *s, int low, int high, int pos, int qlow, int qhigh, int data)
{
	//if lazy node is not zero update node of main tree and propagate the changes to be done to the children of lazy node for future updates
	if (s->lazyTree[pos] != 0)
	{
		s->mainTree[pos] = s->mainTree[pos] + (high - low + 1)*s->lazyTree[pos];
		if (low != high)
		{
			s->lazyTree[2 * pos + 1] += s->lazyTree[pos];
			s->lazyTree[2 * pos + 2] += s->lazyTree[pos];
		}
		s->lazyTree[pos] = 0;
	}
	//if full overlap update currnet node and return
	if (qlow <= low&&qhigh >= high)
	{
		s->mainTree[pos] = s->mainTree[pos] + (high - low + 1)*data;
		//propagate the changes to be done to the children of lazy node for future updates
		if (low != high)
		{
			s->lazyTree[2 * pos + 1] += data;
			s->lazyTree[2 * pos + 2] += data;
		}
		return;
	}
	//if no overlap just return
	if (qlow > high || qhigh < low)
		return;
	//if partial overlap then recur for both halfs of tree
	int mid = (low + high) / 2;
	updateRangeInSegmentTree(s, low, mid, 2 * pos + 1, qlow, qhigh, data);
	updateRangeInSegmentTree(s, mid + 1, high, 2 * pos + 2, qlow, qhigh, data);
	s->mainTree[pos] = s->mainTree[2 * pos + 1] + s->mainTree[2 * pos + 2];
}
int SumInRange(SegmentTree *s, int low, int high, int pos, int qlow, int qhigh)
{
	//if lazy node is not zero update node of main tree
	if (s->lazyTree[pos] != 0)
	{
		s->mainTree[pos] = s->mainTree[pos] + (high - low + 1)*s->lazyTree[pos];
		if (low != high)
		{
			s->lazyTree[2 * pos + 1] += s->lazyTree[pos];
			s->lazyTree[2 * pos + 2] += s->lazyTree[pos];
		}
		s->lazyTree[pos] = 0;
	}
	//if full overlap update currnet node and return
	if (qlow <= low&&qhigh >= high)
	{
		return s->mainTree[pos];
	}
	//if no overlap just return
	if (qlow > high || qhigh < low)
		return 0;
	//if partial overlap then recur for both halfs of tree
	int mid = (low + high) / 2;
	return SumInRange(s, low, mid, 2 * pos + 1, qlow, qhigh) + SumInRange(s, mid + 1, high, 2 * pos + 2, qlow, qhigh);
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5,6 };
	SegmentTree *s = createSegmentTree(arr, 6);
	cout << "sum in range [1,3] before update is : ";
	cout << SumInRange(s, 0, 5, 0, 1, 3) << "\n"; // sum in range [1,3]
	updateRangeInSegmentTree(s, 0, 5, 0, 0, 5, 2);
	cout << "sum in range [1,3] after update is : ";
	cout << SumInRange(s, 0, 5, 0, 1, 3); // sum in range [1,3]
	return 0;
}
