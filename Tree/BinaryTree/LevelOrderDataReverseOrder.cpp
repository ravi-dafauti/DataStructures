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
	void LevelOrderInReverse();
};

void Tree::LevelOrderInReverse()
{
	stack<Node *> aux_stack;
	queue<Node *> aux_queue;
	if (root == NULL)
		return;
	aux_queue.push(root);
	while (!aux_queue.empty())
	{
		Node *temp = aux_queue.front();
		aux_queue.pop();
		aux_stack.push(temp);
		if (temp->right)
			aux_queue.push(temp->right);
		if (temp->left)
			aux_queue.push(temp->left);
	}
	while (!aux_stack.empty())
	{
		cout << aux_stack.top()->data << " ";
		aux_stack.pop();
	}
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
	mTree.LevelOrderInReverse();
	return 0;
}