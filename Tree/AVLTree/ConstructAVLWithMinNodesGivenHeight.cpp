#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	int height;
};
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

Node *constructAVLUtil(int h,int &count)
{
	if (h <= -1)
		return NULL;
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->left = constructAVLUtil(h - 1, count);
	temp->data = count++;
	temp->right = constructAVLUtil(h - 2, count);
	if (temp->left)
		temp->height = temp->left->height + 1;
	else
		temp->height = 0;
	return temp;
}
Node *constructAVL(int h)
{
	int count = 0;
	return constructAVLUtil(h, count);
}
int main()
{
	Node *root = constructAVL(2);
	
	if (isAVL(root) != -1)
	{
		cout << "is AVL";
	}
	else
	{
		cout << "is not AVL";
	}
	return 0;
}