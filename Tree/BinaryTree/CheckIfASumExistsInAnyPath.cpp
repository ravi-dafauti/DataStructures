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
	bool isSumExists(Node *, int);
};


bool Tree::isSumExists(Node *root_ref, int sum)
{
	if (root_ref == NULL)
		return sum == 0;
	if (root_ref->left == NULL && root_ref->right==NULL)
	{
		return sum - (root_ref->data) == 0;
	}
	int remaning_sum = sum - root_ref->data;
	if (root->left!=NULL && isSumExists(root_ref->left, remaning_sum))
	{
		return true;
	}
	else if(root->right != NULL)
		return isSumExists(root_ref->right, remaning_sum);
	return false;
}
Node *Tree::rootOfTree()
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
	cout << mTree.isSumExists(mTree.rootOfTree(), 7);
	return 0;
}