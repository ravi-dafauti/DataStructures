#include<iostream>
using namespace std;

class DisjointSet
{
	int *arr;
	int *sizearr;
	int size;
public:
	DisjointSet(int);
	int root(int);
	bool find(int, int);
	void unionfun(int, int);
};
DisjointSet::DisjointSet(int size)
{
	this->size = size;
	arr = (int*)malloc(sizeof(int)*size);
	sizearr = (int*)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
		sizearr[i] = 1;
	}
}

int DisjointSet::root(int a)
{
	int i = a;
	/* we use path compression for optimizing the union-find (point the current element to its grandparent)*/
	while (arr[i] != i)
	{
		arr[i] = arr[arr[i]];
		i = arr[i];
	}
	return i;
}

bool DisjointSet::find(int a, int b)
{
	if (root(a) == root(b))
		return true;
	return false;
}

void DisjointSet::unionfun(int a, int b)
{
	// using weighted union so that complexity of union-find is log(N) instead of N in worst case
	if (find(a, b))
		return;
	int roota = root(a);
	int rootb = root(b);
	if (sizearr[roota] > sizearr[rootb])
	{
		arr[rootb] = roota;
		sizearr[roota] += sizearr[rootb];
	}
	else
	{
		arr[roota] = rootb;
		sizearr[rootb] += sizearr[roota];
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