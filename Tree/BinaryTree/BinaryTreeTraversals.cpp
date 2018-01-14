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
	Node *head;
public:
	Node *rootOfTree();
	void init(Node *);
	void preorderTraversalIterative();
	void preorderTraveralRecursive(Node *);
	void inorderTraversalIterative();
	void inorderTraversalRecursive(Node *);
	void postorderTraversalIterative();
	void postorderTraversalRecursive(Node *);
	void levelorderTraversal();
};

Node * Tree::rootOfTree()
{
	return head;
}
void Tree::preorderTraveralRecursive(Node *root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preorderTraveralRecursive(root->left);
		preorderTraveralRecursive(root->right);
	}
}

void Tree::postorderTraversalRecursive(Node *root)
{
	if (root !=NULL)
	{
		postorderTraversalRecursive(root->left);
		postorderTraversalRecursive(root->right);
		cout << root->data << " ";
	}
}

void Tree::inorderTraversalRecursive(Node *root)
{
	if (root !=NULL)
	{
		inorderTraversalRecursive(root->left);
		cout << root->data << " ";
		inorderTraversalRecursive(root->right);
	}
}
void Tree::levelorderTraversal()
{
	if (head == NULL)
		return;
	queue<Node *> aux_queue;
	aux_queue.push(head);
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
void Tree::inorderTraversalIterative()
{
	stack<Node *> aux_stack;
	if (head == NULL)
		return;
	if (head->right)
		aux_stack.push(head->right);
	else
		aux_stack.push(NULL);
	aux_stack.push(head);
	if (head->left)
		aux_stack.push(head->left);
	else
		aux_stack.push(NULL);
	while (!aux_stack.empty())
	{
		Node *temp = aux_stack.top();
		aux_stack.pop();
		if (temp == NULL)
			continue;
		if ((temp->left == NULL&&temp->right == NULL) || (!aux_stack.empty() && temp->right == aux_stack.top()))
			cout << temp->data << " ";
		else
		{
			if (temp->right)
				aux_stack.push(temp->right);
			else
				aux_stack.push(NULL);
			aux_stack.push(temp);
			if (temp->left)
				aux_stack.push(temp->left);
			else
				aux_stack.push(NULL);
		}
	}
}

void Tree::postorderTraversalIterative()
{
	if (head == NULL)
		return;
	stack<Node *> aux_stack;
	Node *root = head;
	while (1)
	{
		while (root != NULL)
		{
			if (root->right != NULL)
				aux_stack.push(root->right);
			aux_stack.push(root);
			root = root->left;
		}
		if (aux_stack.empty())
			return;
		root = aux_stack.top();
		aux_stack.pop();
		if (root->right != NULL && !aux_stack.empty() && root->right == aux_stack.top())
		{
			aux_stack.pop();
			aux_stack.push(root);
			root = root->right;
		}
		else
		{
			cout << root->data << " ";
			root = NULL;
		}
	}
}

void Tree::init(Node *head_ref)
{
	head = head_ref;
}
void Tree::preorderTraversalIterative()
{
	stack<Node *> aux_stack;
	if (head == NULL)
		return;
	aux_stack.push(head);
	while (!aux_stack.empty())
	{
		Node *temp = aux_stack.top();
		aux_stack.pop();
		cout << temp->data << " ";
		if (temp->right)
			aux_stack.push(temp->right);
		if (temp->left)
			aux_stack.push(temp->left);
	}
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
	mTree.init(root);
	root = mTree.rootOfTree();
	cout << "preorder traversal : \n";
	mTree.preorderTraveralRecursive(root);
	cout << "\n";
	cout << "inorder traversal : \n";
	mTree.inorderTraversalRecursive(root);
	cout << "\n";
	cout << "postorder traversal : \n";
	mTree.postorderTraversalRecursive(root);
	cout << "\n";
	cout << "level order traversal : \n";
	mTree.levelorderTraversal();
	return 0;
}