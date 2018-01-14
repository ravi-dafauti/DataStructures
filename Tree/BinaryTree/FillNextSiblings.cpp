/* given a complete binary tree with left,right and nextSibling pointer, give an algorithm for filling the next siblings pointer assuming
they are initially null.
*/
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node *nextSibling;
};

class Tree
{
	Node *root;
public:
	Node *rootOfTree();
	void copyTree(Node *);
	void fillNextSiblingsIterative();
	void fillNextSiblingsRecursive(Node *);
};

void Tree::fillNextSiblingsIterative()
{
	queue<Node *> aux_queue;
	if (root == NULL)
		return;
	aux_queue.push(root);
	aux_queue.push(NULL);
	while (!aux_queue.empty())
	{
		Node *temp = aux_queue.front();
		aux_queue.pop();
		if (temp != NULL)
		{
			temp->nextSibling = aux_queue.front();
			if (temp->left != NULL)
				aux_queue.push(temp->left);
			if (temp->right != NULL)
				aux_queue.push(temp->right);
		}
		else
		{
			if (!aux_queue.empty())
			{
				aux_queue.push(NULL);
			}
		}
	}
}

void Tree::fillNextSiblingsRecursive(Node *root_ref)
{
	if (root_ref == NULL)
		return;
	if (root_ref == root)
		root_ref->nextSibling = NULL;
	if (root_ref->left != NULL)
		root_ref->left->nextSibling = root_ref->right;
	if (root_ref->right != NULL && root_ref->nextSibling != NULL)
		root_ref->right->nextSibling = root_ref->nextSibling->left;
	else
		root_ref->right->nextSibling = NULL;
	fillNextSiblingsRecursive(root->left);
	fillNextSiblingsRecursive(root->right);
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
	return 0;
}
