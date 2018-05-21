/*
Given a binary matrix, print all unique rows of the given matrix.

Input:
{0, 1, 0, 0, 1}
{1, 0, 1, 1, 0}
{0, 1, 0, 0, 1}
{1, 1, 1, 0, 0}
Output:
0 1 0 0 1
1 0 1 1 0
1 1 1 0 0

*/

#include<iostream>
using namespace std;
#define ROW 4
#define COL 5

struct TrieNode
{
	bool isEnd;
	TrieNode *arr[2];
};
class Trie
{
	TrieNode *root;
	TrieNode *createTriNode()
	{
		TrieNode *t = new TrieNode();
		t->isEnd = false;
		t->arr[0] = NULL;
		t->arr[1] = NULL;
		return t;
	}
public:
	Trie()
	{
		root = createTriNode();
	}
	void insert(int array[],int n)
	{
		TrieNode *crawl = root;
		for (int i = 0; i < n; i++)
		{
			if (!crawl->arr[array[i]])
				crawl->arr[array[i]] = createTriNode();
			crawl = crawl->arr[array[i]];
		}
		crawl->isEnd = true;
	}
	bool search(int array[], int n)
	{
		TrieNode *crawl = root;
		for (int i = 0; i < n; i++)
		{
			if (!crawl->arr[array[i]])
				return false;
			crawl = crawl->arr[array[i]];
		}
		return crawl->isEnd;
	}
};

void findUniqueRows(int mat[][COL])
{
	Trie t;
	for (int i = 0; i < ROW; i++)
	{
		if (!t.search(mat[i], COL))
		{
			t.insert(mat[i], COL);
			for (int j = 0; j < COL; j++)
				cout << mat[i][j] << " ";
			cout << endl;
		}	
	}
}
int main()
{
	int M[ROW][COL] = { { 0, 1, 0, 0, 1 },
	{ 1, 0, 1, 1, 0 },
	{ 0, 1, 0, 0, 1 },
	{ 1, 0, 1, 0, 0 }
	};

	findUniqueRows(M);
    return 0;
}

