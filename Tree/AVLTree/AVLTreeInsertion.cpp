#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *left;
	Node *right;
	int height;
};

Node *newNode(int item)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	temp->height = 0;
	return temp;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int height(Node *root_ref)
{
	if (root_ref == NULL)
		return -1;
	return max(height(root_ref->left), height(root_ref->right)) + 1;
}

Node *LLRotate(Node *X)
{
	Node *W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(height(X->left), height(X->right)) + 1;
	W->height = max(height(W->left), X->height) + 1;
	return W;
}

Node *RRRotate(Node *W)
{
	Node *X = W->right;
	W->right = X->left;
	X->left = W;
	W->height = max(height(W->left), height(W->right)) + 1;
	X->height = max(height(X->right), W->height) + 1;
	return X;
}

Node *LRRotate(Node *Z)
{
	Z->left = RRRotate(Z->left);
	return LLRotate(Z);
}
Node *RLRotate(Node *Z)
{
	Z->right = LLRotate(Z->right);
	return RRRotate(Z);
}

void inorder(Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

int abs(int a)
{
	if (a < 0)
		return -a;
	return a;
}
Node *insertToAVL(Node *root_ref, int data)
{
	if (root_ref == NULL)
	{
		Node *temp = newNode(data);
		root_ref = temp;
		return root_ref;
	}
	if (root_ref->data >= data)
	{
		root_ref->left = insertToAVL(root_ref->left, data);
		if (abs(height(root_ref->left) - height(root_ref->right)) == 2)
		{
			if (data <= root_ref->left->data)
			{
				root_ref = LLRotate(root_ref);
			}
			else
			{
				root_ref = LRRotate(root_ref);
			}
		}
	}
	else if (root_ref->data < data)
	{
		root_ref->right = insertToAVL(root_ref->right, data);
		if (abs(height(root_ref->left) - height(root_ref->right)) == 2)
		{
			if (data > root_ref->right->data)
			{
				root_ref = RRRotate(root_ref);
			}
			else
			{
				root_ref = RLRotate(root_ref);
			}
		}
	}
	root_ref->height = max(height(root_ref->left), height(root_ref->right)) + 1;
	return root_ref;
}

int main()
{
	Node *root = NULL;
	root = insertToAVL(root, 40);
	root = insertToAVL(root, 70);
	root = insertToAVL(root, 60);
	root = insertToAVL(root, 80);
	root = insertToAVL(root, 50);
	root = insertToAVL(root, 30);
	root = insertToAVL(root, 20);
	inorder(root);
	return 0;
}
