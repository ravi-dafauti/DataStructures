#include<iostream>
using namespace std;

class DisjointSet
{
	int *arr;
	int size;
public:
	DisjointSet(int);
	bool find(int, int);
	void unionfun(int, int);
};
DisjointSet::DisjointSet(int size)
{
	this->size = size;
	arr = (int*)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
}

bool DisjointSet::find(int a, int b)
{
	if (arr[a] == arr[b])
		return true;
	return false;
}

void DisjointSet::unionfun(int a, int b)
{
	if (find(a, b))
		return;
	int temp = arr[a];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == temp)
			arr[i] = arr[b];
	}
}
int main()
{
	DisjointSet *ds = new DisjointSet(5);
	cout << ds->find(0, 1);
	ds->unionfun(0, 1);
	cout << ds->find(0, 1);
	return 0;
}