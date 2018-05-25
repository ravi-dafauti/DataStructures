/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

*/
#include <iostream>
using namespace std;

// A binary Tree node
struct node
{
	int data;
	struct node *left, *right;
};

node *newnode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int maximumSumPathUtil(node *root, int &maximum)
{
	if (!root)
		return 0;
	int l = max(maximumSumPathUtil(root->left, maximum), 0);
	int r = max(maximumSumPathUtil(root->right, maximum), 0);
	maximum = max(maximum, root->data + l + r);
	return root->data + max(l, r);
}
int maximumSumPath(node *root)
{
	if (!root)
		return 0;
	int maximum = INT_MIN;
	maximumSumPathUtil(root, maximum);
	return maximum;
}
int main()
{

	node * root = newnode(-10);
	root->left = newnode(9);
	root->right = newnode(20);
	root->right->left = newnode(15);
	root->right->right = newnode(7);
	node * target = root->left->right;
	cout << maximumSumPath(root);
	return 0;
}