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


bool isBSTUtil(Node * root_ref, Node *&prev)
{
	if (!root_ref)
		return true;
	if (!isBSTUtil(root_ref->left, prev))
		return false;
	if (prev && root_ref->data <= prev->data)
		return false;
	prev = root_ref;
	return isBSTUtil(root_ref->right, prev);
}

bool isBST(Node *root_ref)
{
	Node *prev = NULL;
	return isBSTUtil(root_ref, prev);
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

Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}
int main()
{
	Node *root = NULL;
	root = insertToBST(root, 50);
	root = insertToBST(root, 30);
	root = insertToBST(root, 20);
	root = insertToBST(root, 40);
	root = insertToBST(root, 70);
	root = insertToBST(root, 60);
	root = insertToBST(root, 80);

	Node *root1 = newNode(3);
	root1->left = newNode(2);
	root1->right = newNode(5);
	root1->left->left = newNode(1);
	root1->left->right = newNode(4);

	if (isBST(root))
	{
		cout << "is BST\n";
	}
	else
	{
		cout << "is not BST\n";
	}

	if (isBST(root1))
	{
		cout << "is BST\n";
	}
	else
	{
		cout << "is not BST\n";
	}
	return 0;
}