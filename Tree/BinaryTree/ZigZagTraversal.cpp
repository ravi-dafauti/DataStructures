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
public:
	Tree();
	void copyTree(Node *);
	Node *getRoot();
	void zigzagTraversal();
};
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
void Tree::zigzagTraversal()
{
	if (root == NULL)
		return;
	stack<Node *> s1;
	stack<Node *> s2;
	bool rightToLeft = false;
	s1.push(root);
	while (!s1.empty())
	{
		Node *temp = s1.top();
		cout << temp->data << " ";
		s1.pop();
		if (rightToLeft)
		{
			if (temp->right)
				s2.push(temp->right);
			if (temp->left)
				s2.push(temp->left);
		}
		else
		{
			if (temp->left)
				s2.push(temp->left);
			if (temp->right)
				s2.push(temp->right);
		}
		if (s1.empty())
		{
			s1.swap(s2);
			rightToLeft = (!rightToLeft);
		}
	}
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
	binaryTree.zigzagTraversal();
	return 0;
}
