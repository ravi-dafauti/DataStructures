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
	void convertToMirror(Node *);
	void levelorderTraversal();
};

void Tree::levelorderTraversal()
{
	if (root == NULL)
		return;
	queue<Node *> aux_queue;
	aux_queue.push(root);
	while (!aux_queue.empty())
	{
		Node *temp = aux_queue.front();
		aux_queue.pop();
		cout << temp->data << " ";
		if (temp->left != NULL)
			aux_queue.push(temp->left);
		if (temp->right != NULL)
			aux_queue.push(temp->right);
	}
}
void Tree::convertToMirror(Node *root_ref)
{
	if (root_ref == NULL)
		return;
	convertToMirror(root_ref->left);
	convertToMirror(root_ref->right);
	Node *temp = root_ref->left;
	root_ref->left = root_ref->right;
	root_ref->right = temp;
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
	mTree.levelorderTraversal();
	cout << "\n";
	cout << "after mirroring\n";
	mTree.convertToMirror(mTree.rootOfTree());
	mTree.levelorderTraversal();
	return 0;
}