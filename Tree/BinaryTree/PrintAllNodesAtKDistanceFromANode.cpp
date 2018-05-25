/*
Given a binary tree, a target node in the binary tree, and an integer value k,
print all the nodes that are at distance k from the given target node. No parent pointers are available.
*/
#include <iostream>
using namespace std;

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

void printdown(node *t, int k)
{
	if (!t || k < 0)
		return;
	if (k == 0)
	{
		cout << t->data << " ";
		return;
	}
	printdown(t->left, k - 1);
	printdown(t->right, k - 1);
}
int printkdistanceNode(node *root, node *target, int k)
{
	if (!root)
		return -1;
	if (root == target)
	{
		printdown(target, k);
		return 0;
	}
	int l = printkdistanceNode(root->left, target, k);
	if (l != -1)
	{
		if (l + 1 == k)
		{
			cout << root->data << " ";
		}
		else
		{
			printdown(root->right, k - l - 2);
		}
		return l + 1;
	}
	int r = printkdistanceNode(root->right, target, k);
	if (r != -1)
	{
		if (r + 1 == k)
		{
			cout << root->data << " ";
		}
		else
		{
			printdown(root->left, k - r - 2);
		}
		return r + 1;
	}
	return -1;
}
int main()
{
	node * root = newnode(20);
	root->left = newnode(8);
	root->right = newnode(22);
	root->left->left = newnode(4);
	root->left->right = newnode(12);
	root->left->right->left = newnode(10);
	root->left->right->right = newnode(14);
	node * target = root->left->right;
	printkdistanceNode(root, target, 2);
	return 0;
}