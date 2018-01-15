#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node* newNode(int data)
{
	Node* node = (Node*)
		malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}
class Tree
{
	Node *root;
	int max(int, int);
public:
	Tree();
	void copyTree(Node *);
	Node *getRoot();
	int diameter(Node *);
	int height(Node *);
};
int Tree::max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
Tree::Tree()
{
	root = NULL;
}
void Tree::copyTree(Node *root_ref)
{
	root = root_ref;
}
Node *Tree::getRoot()
{
	return root;
}
int Tree::height(Node *root_ref)
{
	if (root_ref == NULL)
		return 0;
	else
		return(max(height(root_ref->left), height(root_ref->right)) + 1);
}
int Tree::diameter(Node *root_ref)
{
	if (root_ref == NULL)
		return 0;
	int left_height = height(root_ref->left);
	int right_height = height(root_ref->right);
	return max((height(root_ref->left) + height(root_ref->right) + 1), max(diameter(root_ref->left), diameter(root_ref->right)));
}
int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	Tree binaryTree;
	binaryTree.copyTree(root);
	cout << "diameter of Tree is : " << binaryTree.diameter(binaryTree.getRoot());
	return 0;
}
