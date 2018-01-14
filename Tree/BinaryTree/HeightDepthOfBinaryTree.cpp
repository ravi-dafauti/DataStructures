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
	int max(int, int);
public:
	Node *rootOfTree();
	void copyTree(Node *);
	int heightRecursive(Node *);
	int heightIterative();
};

int Tree::heightIterative()
{
	int height = 0;
	if (root == NULL)
		return -1;
	queue<Node *> aux_queue;
	aux_queue.push(root);
	aux_queue.push(NULL);
	while (!aux_queue.empty())
	{
		Node *temp = aux_queue.front();
		aux_queue.pop();
		if (temp == NULL)
		{
			if (!aux_queue.empty())
			{
				height++;
				aux_queue.push(NULL);
			}
		}
		else
		{
			if (temp->left)
				aux_queue.push(temp->left);
			if (temp->right)
				aux_queue.push(temp->right);
		}
	}
	return height;
}
int Tree::max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int Tree::heightRecursive(Node *root_ref)
{
	if (root_ref == NULL)
		return -1;
	return max(heightRecursive(root_ref->left), heightRecursive(root_ref->right)) + 1;
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
	cout << mTree.heightIterative();
	return 0;
}