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
	Node *root;
public:
	Node *rootOfTree();
	void copyTree(Node *);
	Node *leastCommonAncestor(Node *, Node *, Node *);
};

Node *Tree::leastCommonAncestor(Node *root_ref, Node *a, Node *b)
{
	if (root_ref == NULL)
		return NULL;
	if (root_ref == a || root_ref == b)
		return root_ref;
	Node *left = leastCommonAncestor(root_ref->left, a, b);
	Node *right = leastCommonAncestor(root_ref->right, a, b);
	if (left != NULL && right != NULL)
	{
		return root_ref;
	}
	else if (right == NULL)
		return left;
	else if (left == NULL)
		return right;
	return NULL;
}
Node * Tree::rootOfTree()
{
	return root;
}

void Tree::copyTree(Node *root_ref)
{
	root = root_ref;
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
	mTree.copyTree(root);
	cout << mTree.leastCommonAncestor(mTree.rootOfTree(), root->left->left, root->right->right)->data;
	return 0;
}