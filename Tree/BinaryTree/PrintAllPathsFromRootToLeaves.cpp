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
	void printPathUtil(stack<int> &s);
	void printAllPathRecur(stack<int> &s, Node *);
public:
	Node *rootOfTree();
	void copyTree(Node *);
	void printAllPaths();
};


void Tree::printPathUtil(stack<int> &s)
{
	if (s.empty())
		return;
	int data = s.top();
	s.pop();
	printPathUtil(s);
	cout << data << " ";
	s.push(data);
}

void Tree::printAllPathRecur(stack<int> &s, Node *root_ref)
{
	if (root_ref == NULL)
		return;
	else
		s.push(root_ref->data);
	if (root_ref->left == NULL&&root_ref->right == NULL)
	{
		printPathUtil(s);
		s.pop();
		cout << "\n";
	}
	else
	{
		printAllPathRecur(s, root_ref->left);
		printAllPathRecur(s, root_ref->right);
		s.pop();
	}
}

void Tree::printAllPaths()
{
	if (root == NULL)
		return;
	stack<int> aux_stack;
	printAllPathRecur(aux_stack, root);
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
	mTree.printAllPaths();
	return 0;
}