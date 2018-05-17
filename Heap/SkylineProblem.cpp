/*
Given n rectangular buildings in a 2-dimensional city, computes the skyline of these buildings, eliminating hidden lines. The main task is to view buildings from a side and remove all sections that are not visible.

All buildings share common bottom and every building is represented by triplet (left, ht, right)

‘left’: is x coordinated of left side (or wall).
‘right’: is x coordinate of right side
‘ht’: is height of building.

A skyline is a collection of rectangular strips. A rectangular strip is represented as a pair (left, ht) where left is x coordinate of left side of strip and ht is height of strip.

Examples:

Input: Array of buildings
{ (1,11,5), (2,6,7), (3,13,9), (12,7,16), (14,3,25),
(19,18,22), (23,13,29), (24,4,28) }
Output: Skyline (an array of rectangular strips)
A strip has x coordinate of left side and height
(1, 11), (3, 13), (9, 0), (12, 7), (16, 3), (19, 18),
(22, 3), (25, 0)
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;


class PriorityQueue
{
	int *arr;
	unordered_map<int, int> indexStore;
	int count;
	int size;
	int leftChild(int i)
	{
		if (i < count && (2 * i + 1) < count)
			return (2 * i + 1);
		return -1;
	}
	int rightChild(int i)
	{
		if (i < count && (2 * i + 2) < count)
			return (2 * i + 2);
		return -1;
	}
	int parent(int i)
	{
		if (i == 0)
			return -1;
		if (i < count && (i - 1) / 2 >= 0)
		{
			return (i - 1) / 2;
		}
		return -1;
	}
	void percolateDown(int i)
	{
		if (i >= count)
			return;
		int l = leftChild(i);
		int r = rightChild(i);
		int max = i;
		if (l != -1 && arr[max] < arr[l])
			max = l;
		if (r != -1 && arr[max] < arr[r])
			max = r;
		if (max != i)
		{
			indexStore[arr[max]] = i;
			indexStore[arr[i]] = max;
			int temp = arr[max];
			arr[max] = arr[i];
			arr[i] = temp;
			percolateDown(max);
		}
	}
	void resizeHeap()
	{
		size = size * 2;
		arr = (int*)realloc(arr, sizeof(int)*size);
	}
public:
	PriorityQueue()
	{
		arr = (int*)malloc(sizeof(int));
		size = 1;
		count = 0;
	}
	void push(int data)
	{
		if (count == size)
			resizeHeap();
		count++;
		int i;
		for (i = count - 1; parent(i) != -1 && arr[parent(i)] < data;)
		{
			indexStore[arr[parent(i)]] = i;
			arr[i] = arr[parent(i)];
			i = parent(i);
		}
		arr[i] = data;
		indexStore[data] = i;
	}
	void erase(int data)
	{
		if (indexStore.find(data) == indexStore.end())
		{
			exception e;
			throw e;
		}
		int index = indexStore[data];
		arr[index] = arr[count - 1];
		count--;
		indexStore[arr[index]] = index;
		indexStore.erase(data);
		percolateDown(index);
	}
	int top()
	{
		if (count == 0)
			return -1;
		return arr[0];
	}
	int pop()
	{
		if (count == 0)
			return -1;
		int data = arr[0];
		arr[0] = arr[count - 1];
		indexStore.erase(data);
		indexStore[arr[0]] = 0;
		count--;
		percolateDown(0);
		return data;
	}
};

struct Building
{
	int left;  // x coordinate of left side
	int ht;    // height
	int right; // x coordinate of right side
};

bool compare(const pair<pair<int, int>, int> &p1, const pair<pair<int, int>, int> &p2)
{
	if (p1.first.first == p2.first.first)
	{
		if (p1.second == 0 && p2.second == 0)    // when x coordinate is same for starting of two buildings take higher building first
			return p1.first.second > p2.first.second;
		else if (p1.second == 1 && p2.second == 1) // when x coordinate is same for ending of two buildings take lower building first
			return p1.first.second < p2.first.second;
		else {                                   // when x coordinate is same for starting of one building and ending of other building take starting building first
			return p1.second < p2.second;
		}
	}
	return (p1.first.first < p2.first.first);
}
void skyline(Building arr[], int n)
{
	vector<pair<int, int>> result;
	vector<pair<pair<int,int>,int>> set;
	//divide the coordinates in start and end indexes.
	for (int i = 0; i < n; i++)
	{
		set.push_back(make_pair(make_pair(arr[i].left, arr[i].ht), 0));
		set.push_back(make_pair(make_pair(arr[i].right, arr[i].ht), 1));
	}
	// sort the starting and ending coordinates in asc order of x coordinate
	sort(set.begin(), set.end(), compare);
	PriorityQueue pq;
	int max = 0;
	pq.push(0);
	vector<pair<pair<int, int>, int>>::iterator it;
	for (it = set.begin(); it != set.end(); it++)
	{
		//if it is starting of building then include this in ans if max in priority queue changes on inserting this else ignore this coordinate as it comes under max building
		if ((*it).second == 0) 
		{
			pq.push((*it).first.second);
			if (pq.top() != max)
			{
				max = pq.top();
				result.push_back((*it).first);
			}
		}
		else  //if it is ending of building then include this in ans if max in priority queue changes on deleting this and take y coordinate to be max in queue else ignore as it is covered under max building.
		{
			pq.erase((*it).first.second);
			if (max != pq.top())
			{
				max = pq.top();
				result.push_back(make_pair((*it).first.first, max));
			}
		}
	}
	cout << "the skyline is\n";
	vector<pair<int, int>>::iterator i;
	for (i = result.begin(); i != result.end(); i++)
	{
		cout << "(" << (*i).first << "," << (*i).second << ")" << "\n";
	}
}
int main()
{
	Building arr[] = { { 1, 11, 5 },{ 2, 6, 7 },{ 3, 13, 9 },
	{ 12, 7, 16 },{ 14, 3, 25 },{ 19, 18, 22 },
	{ 23, 13, 29 },{ 24, 4, 28 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	skyline(arr, n);
	return 0;
}