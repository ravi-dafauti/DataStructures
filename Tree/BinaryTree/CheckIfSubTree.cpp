#include <iostream>
//#include<cstring>
using namespace std;
#define MAX 100

// Structure of a tree node
struct Node
{
	char key;
	struct Node *left, *right;
};

// A utility function to create a new BST node
Node *newNode(char item)
{
	Node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void fillInorder(Node *root, char arr[], int &i)
{
	if (!root)
		return;
	fillInorder(root->left, arr, i);
	arr[i++] = root->key;
	fillInorder(root->right, arr, i);
}
void fillPreorder(Node *root, char arr[], int &i)
{
	if (!root)
		return;
	arr[i++] = root->key;
	fillPreorder(root->left, arr, i);
	fillPreorder(root->right, arr, i);
}
bool isSubtree(Node *T, Node *S)
{
	if (!S)
		return true;
	if (!T)
		return false;
	char inorderT[MAX];
	char inorderS[MAX];
	int i = 0;
	fillInorder(T, inorderT, i);
	inorderT[i] = '\0';
	i = 0;
	fillInorder(S, inorderS, i);
	inorderS[i] = '\0';
	if (!strstr(inorderT, inorderS))
		return false;
	char preorderT[MAX];
	char preorderS[MAX];
	i = 0;
	fillPreorder(T, preorderT, i);
	preorderT[i] = '\0';
	i = 0;
	fillPreorder(S, preorderS, i);
	preorderS[i] = '\0';
	return strstr(preorderT, preorderS);
}

// Driver program to test above function
int main()
{
	Node *T = newNode('a');
	T->left = newNode('b');
	T->right = newNode('d');
	T->left->left = newNode('c');
	T->right->right = newNode('e');

	Node *S = newNode('b');
	S->left = newNode('c');
	//S->left->left = newNode('c');
	//S->right = newNode('d');

	if (isSubtree(T, S))
		cout << "Yes: S is a subtree of T";
	else
		cout << "No: S is NOT a subtree of T";

	return 0;
}