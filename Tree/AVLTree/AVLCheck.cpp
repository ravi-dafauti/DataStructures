#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node* newNode(int data)
{
	Node* node = (Node*)
		malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int abs(int a)
{
	if (a < 0)
		return -a;
	return a;
}
int isAVL(Node *root_ref)
{
	if (root_ref == NULL)
		return 0;
	int l = isAVL(root_ref->left);
	if (l == -1)
		return l;
	int r = isAVL(root_ref->right);
	if (l == -1)
		return l;
	if (abs(l - r) > 1)
		return -1;
	return max(l, r) + 1;
}
int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->left = newNode(8);
	if (isAVL(root)!=-1)
	{
		cout << "is AVL";
	}
	else
	{
		cout << "is not AVL";
	}
	return 0;
}
