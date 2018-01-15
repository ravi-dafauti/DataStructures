#include<iostream>
#include<stack>
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
	void printStack(stack<int> &s);
	bool printAllAncestorsUtil(Node *, stack<int> &s, Node *);
public:
	Tree();
	void copyTree(Node *);
	Node *getRoot();
	void printAllAncestors(Node *, Node *);
};

void Tree::printStack(stack<int> &s)
{
	if (s.empty())
		return;
	int temp = s.top();
	s.pop();
	printStack(s);
	cout << temp << " ";
	s.push(temp);
}
bool Tree::printAllAncestorsUtil(Node *root_ref, stack<int> &s, Node *child)
{
	if (root_ref == NULL)
		return false;
	s.push(root_ref->data);
	if (root_ref->data == child->data)
	{
		printStack(s);
		return true;
	}
	if (printAllAncestorsUtil(root_ref->left, s, child))
		return true;
	else if (printAllAncestorsUtil(root_ref->right, s, child))
	{
		return true;
	}
	s.pop();
	return false;
}

void Tree::printAllAncestors(Node *root_ref, Node *child)
{
	stack<int> s;
	printAllAncestorsUtil(root_ref, s, child);
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
int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	Tree binaryTree;
	binaryTree.copyTree(root);
	binaryTree.printAllAncestors(binaryTree.getRoot(), root->left->right);
	return 0;
}