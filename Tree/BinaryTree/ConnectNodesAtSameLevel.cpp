#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *left;
	Node *right;
	Node *next;
};

Node* newnode(int data)
{
	Node* node = (Node*)
		malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->next = NULL;

	return(node);
}

void connectSameLevel(Node *head_ref)
{
	if (head_ref == NULL)
		return;
	Node *headNext = NULL;
	Node *nextNode = NULL;
	Node *temp = head_ref;
	while (temp != NULL)
	{
		if (temp->left != NULL)
		{
			if (nextNode == NULL)
			{
				headNext = temp->left;
				nextNode = temp->left;
			}
			else
			{
				nextNode->next = temp->left;
				nextNode = nextNode->next;
			}
		}
		if (temp->right != NULL)
		{
			if (nextNode == NULL)
			{
				headNext = temp->right;
				nextNode = temp->right;
			}
			else
			{
				nextNode->next = temp->right;
				nextNode = nextNode->next;
			}
		}
		temp = temp->next;
	}
	connectSameLevel(headNext);
}

int main()
{

	/* Constructed binary tree is
	10
	/   \
	8      2
	/       \
	3         4    
	*/
	Node *root = newnode(10);
	root->left = newnode(8);
	root->right = newnode(2);
	root->left->left = newnode(3);
	root->right->right = newnode(4);
	connectSameLevel(root);
	cout << root->left->left->next->data;
	return 0;
}