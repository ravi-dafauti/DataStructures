/*
       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
bottom view of the above binary tree is
4 2 6 7
        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
Bottom view of the above binary tree is
2 4 5 6
*/
#include<iostream>
#include<map>
#include<queue>
using namespace std;
 
//Structure of binary tree
struct Node
{
	int data; //data of the node
	Node *left, *right; //left and right references

						// Constructor of tree node
	Node(int key)
	{
		data = key;
		left = right = NULL;
	}
};
 
 

void bottomView(Node *root)
{
	if (root == NULL)
		return;
	map<int, int> m;
	queue < pair<Node *, int>> q;
	q.push(make_pair(root, 0));
	while (!q.empty())
	{
		pair<Node *, int> temp = q.front();
		Node *n = temp.first;
		int index = temp.second;
		q.pop();
		m[index] = n->data;
		if (n->left)
		{
			q.push(make_pair(n->left, index-1));
		}
		if (n->right)
		{
			q.push(make_pair(n->right, index+1));
		}
	}
	map<int, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++)
	{
		cout << it->second << " ";
	}
}
// main function
int main()
{
	Node *root = new Node(20);
	root->left = new Node(8);
	root->right = new Node(22);
	root->left->left = new Node(5);
	root->left->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(25);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(14);
	cout << "Bottom view of the given binary tree :\n";
		bottomView(root);
	return 0;
}