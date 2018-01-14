#include<iostream>
#include<stack>
#include<queue>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

class Tree
{
	Node *head;
public:
	Node *rootOfTree();
	void init(Node *);
	bool searchInTree(Node *, int);
};

bool Tree::searchInTree(Node *root_ref, int data)
{
	if (root_ref == NULL)
		return false;
	if (root_ref->data == data)
		return true;
	else
	{
		int res = searchInTree(root_ref->left, data);
		if (res)
			return true;
		else
			return searchInTree(root_ref->right, data);
	}
	return false;
}
Node * Tree::rootOfTree()
{
	return head;
}

void Tree::init(Node *head_ref)
{
	head = head_ref;
}

Node * newNode(int data)
{
	Node * node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}
int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	Tree mTree;
	mTree.init(root);
	root = mTree.rootOfTree();
	cout << mTree.searchInTree(root, 9);
	return 0;
}