#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

void inorder(Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
Node *insertToBST(Node *root_ref, int data)
{
	if (root_ref == NULL)
	{
		Node *temp = (Node *)malloc(sizeof(Node));
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		root_ref = temp;
		return root_ref;
	}
	if (root_ref->data > data)
	{
		root_ref->left = insertToBST(root_ref->left, data);
	}
	else if (root_ref->data < data)
	{
		root_ref->right = insertToBST(root_ref->right, data);
	}
	return root_ref;
}

Node *LCA(Node *root_ref, Node *a, Node *b)
{
	if (root_ref->data > a->data&&root_ref->data<b->data)
		return root_ref;
	if (root_ref->data < a->data&&root_ref->data<b->data)
		return LCA(root_ref->right, a, b);
	if (root_ref->data > a->data&&root_ref->data>b->data)
		return LCA(root_ref->left, a, b);
}

int main()
{
	/* Let us create following BST
	50
	/     \
	30      70
	/  \    /  \
	20   40  60   80 */
	Node *root = NULL;
	root = insertToBST(root, 50);
	root = insertToBST(root, 30);
	root = insertToBST(root, 20);
	root = insertToBST(root, 40);
	root = insertToBST(root, 70);
	root = insertToBST(root, 60);
	root = insertToBST(root, 80);
	
	cout << LCA(root, root->left, root->left->right)->data;
	cout << LCA(root, root->left, root->right->right)->data;
	return 0;
}