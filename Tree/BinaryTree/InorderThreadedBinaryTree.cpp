#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	int lTag;
	int rTag;
};
class InorderThreadedBinaryTree
{
	Node *root;
public:
	InorderThreadedBinaryTree();
	void copyTree(Node *);
	void inorderTraversal();
	void preorderTraversal();
	Node *preorderSuccessor(Node *);
	Node *preorderPredecessor(Node *);
	Node *inorderSuccessor(Node *);
	Node *inorderPredecessor(Node *);
	Node *getRoot();
};

Node *InorderThreadedBinaryTree::getRoot()
{
	return root;
}
InorderThreadedBinaryTree::InorderThreadedBinaryTree()
{
	root = NULL;
}
void InorderThreadedBinaryTree::copyTree(Node *root_ref)
{
	root = root_ref;
}
void InorderThreadedBinaryTree::inorderTraversal()
{
	if (root->left == NULL)
		return;
 	Node *temp = inorderSuccessor(root);
	while (temp != root)
	{
		cout << temp->data << " ";
		temp = inorderSuccessor(temp);
	}
}
Node *InorderThreadedBinaryTree::inorderPredecessor(Node *node_ref)
{
	if (node_ref == root)
		return NULL;
	return node_ref->left;
}
Node *InorderThreadedBinaryTree::inorderSuccessor(Node *node_ref)
{
	if (node_ref == root)
	{
		if (root->left == NULL)
			return NULL;
		while (node_ref->lTag)
		{
			node_ref = node_ref->left;
		}
		return node_ref;
	}
	if (node_ref->rTag == 0)
		return node_ref->right;
	else
	{
		node_ref = node_ref->right;
		while (node_ref->lTag)
			node_ref = node_ref->left;
		return node_ref;
	}
}

void InorderThreadedBinaryTree::preorderTraversal()
{
	if (root->left == NULL)
		return;
	Node *temp = root->left;
	while (temp != root)
	{
		cout << temp->data << " ";
		temp = preorderSuccessor(temp);
	}
}

Node *InorderThreadedBinaryTree::preorderSuccessor(Node *node_ref)
{
	if (node_ref->lTag)
		return node_ref->left;
	while (!node_ref->rTag && node_ref != root)
	{
		node_ref = node_ref->right;
	}
	return node_ref->right;
}

Node *InorderThreadedBinaryTree::preorderPredecessor(Node *node_ref)
{
	if (!node_ref->rTag && node_ref->right!=root)
		return node_ref->right;
	while (node_ref->lTag)
		node_ref = node_ref->left;
	node_ref = node_ref->left;
	if (node_ref == root)
		return root;
	while (node_ref->lTag)
		node_ref = node_ref->left;
	return node_ref;
}

Node *createNode(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	temp->lTag = 0;
	temp->rTag = 0;
	return temp;
}
Node *createTree()
{
	Node *root = createNode(-1);
	root->lTag = 0;
	root->right = root;
	root->lTag = 1;
	root->left = createNode(3);
	root->left->lTag = 1;
	root->left->rTag = 1;
	root->left->left = createNode(2);
	root->left->right = createNode(6);

	root->left->left->lTag = 1;
	root->left->left->rTag = 0;
	root->left->left->right = root->left;
	root->left->left->left = createNode(1);

	root->left->left->left->lTag = 0;
	root->left->left->left->rTag = 0;
	root->left->left->left->right = root->left->left;
	root->left->left->left->left = root;

	root->left->right->lTag = 1;
	root->left->right->rTag = 1;
	root->left->right->right = createNode(7);
	root->left->right->left = createNode(5);

	root->left->right->right->right = 0;
	root->left->right->right->lTag = 0;
	root->left->right->right->right = root;
	root->left->right->right->left = root->left->right;

	root->left->right->left->rTag = 0;
	root->left->right->left->lTag = 1;
	root->left->right->left->right = root->left->right;
	root->left->right->left->left = createNode(4);
	root->left->right->left->left->lTag = 0;
	root->left->right->left->left->rTag = 0;
	root->left->right->left->left->right = root->left->right->left;
	root->left->right->left->left->left = root->left;
	return root;
}
int main()
{

	InorderThreadedBinaryTree tree;
	tree.copyTree(createTree());
	//tree.inorderTraversal();
	//tree.preorderTraversal();
	cout << tree.preorderPredecessor(tree.getRoot()->left->right->left)->data;
	return 0;
}
