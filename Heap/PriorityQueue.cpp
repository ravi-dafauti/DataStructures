#include<iostream>
using namespace std;

class PriorityQueue
{
	int *arr;
	int size;
	int count;
	int leftChild(int);
	int rightChild(int);
	int parent(int);
	void percolateDown(int i);
	void resizeHeap();

public:
	PriorityQueue();
	void insert(int);
	void deleteFromPQ(int);
	int max();
	void deleteMax();
};

void PriorityQueue::resizeHeap()
{
	size = size * 2;
	arr = (int *)realloc(arr, sizeof(int)*size);
}
int PriorityQueue::parent(int i)
{
	if (i == 0)
		return -1;
	if (i < count && (i - 1) / 2 >= 0)
	{
		return (i - 1) / 2;
	}
	return -1;
}
int PriorityQueue::leftChild(int i)
{
	if (i < count && 2 * i + 1 < count)
	{
		return 2 * i + 1;
	}
	return -1;
}
void PriorityQueue::percolateDown(int i)
{
	if (i >= count)
		return;
	int l = leftChild(i);
	int r = rightChild(i);
	int max = i;
	if (l != -1 && arr[l] > arr[max])
	{
		max = l;
	}
	if (r != -1 && arr[r] > arr[max])
	{
		max = r;
	}
	if (max != i)
	{
		int temp = arr[max];
		arr[max] = arr[i];
		arr[i] = temp;
		percolateDown(max);
	}
}
int PriorityQueue::rightChild(int i)
{
	if (i < count && 2 * i + 2 < count)
	{
		return 2 * i + 2;
	}
	return -1;
}
PriorityQueue::PriorityQueue()
{
	size = 1;
	count = 0;
	arr = (int*)malloc(sizeof(int));
}
int PriorityQueue::max()
{
	if (count == 0)
	{
		cout << "no element";
		exception e1;
		throw e1;
	}
	return arr[0];
}
void PriorityQueue::insert(int data)
{
	if (count == size)
	{
		resizeHeap();
	}
	count++;
	int i = count - 1;
	while (parent(i) != -1 && arr[parent(i)] < data)
	{
		arr[i] = arr[parent(i)];
		i = parent(i);
	}
	arr[i] = data;
}

void PriorityQueue::deleteFromPQ(int data)
{
	int i;
	for (i = 0; i < count; i++)
	{
		if (arr[i] == data)
		{
			break;
		}
	}
	if (i == count)
	{
		cout << "element not is PQ\n";
		exception e1;
		throw e1;
	}
	if (i == count - 1)
	{
		count--;
		return;
	}
	arr[i] = arr[count - 1];
	count--;
	percolateDown(0);
}

void PriorityQueue::deleteMax()
{
	if (count == 0)
	{
		cout << "no element";
		exception e1;
		throw e1;
	}
	arr[0] = arr[count - 1];
	count--;
	percolateDown(0);
}

int main()
{
	PriorityQueue pq;
	pq.insert(1);
	pq.insert(2);
	pq.insert(3);
	pq.insert(4);
	pq.insert(10);
	pq.insert(12);
	pq.deleteMax();
	pq.deleteFromPQ(4);
	cout << pq.max();
	return 0;
}