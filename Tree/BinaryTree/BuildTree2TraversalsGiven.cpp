/* given Inorder and Preorder sequence Construct a Binary Tree from it*/
#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *left;
	Node *right;
};

int findNode(int arr[], int s, int l, int data)
{
	for (int i = s; i <= l; i++)
	{
		if (arr[i] == data)
		{
			return i;
		}
	}
	return -1;
}
Node *makeNode(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if (!temp)
	{
		cout << "memory exception!!";
		return NULL;
	}
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void printPostorder(Node* node)
{
	if (node == NULL)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
	cout << node->data << " ";
}
Node *constructTree(int inorder[], int preorder[], int start, int end, int &index)
{
	if (start > end)
		return NULL; 
	else if (start <= end)
	{
		Node *root = makeNode(preorder[index]);
		index++;
		if (start < end)
		{
			int mid = findNode(inorder, start, end, preorder[index - 1]);
			root->left = constructTree(inorder, preorder, start, mid - 1, index);
			root->right = constructTree(inorder, preorder, mid + 1, end, index);
		}
		return root;
	}
	return NULL;
}
int main()
{
	int inorder[] = { 4, 2, 5, 1, 6, 3, 7 };
	int preorder[] = { 1, 2, 4, 5, 3, 6, 7 };
	int index = 0;
	Node *root = constructTree(inorder, preorder, 0, 6, index);
	printPostorder(root);
	return 0;
}
