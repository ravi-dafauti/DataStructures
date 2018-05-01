/*
Given a Binary tree create Linked Lists of all the nodes at each depth , say if the tree has height k then create k linked lists.

NOTE : This problem is very similar “Print binary tree, each level in one line“

Input: A binary tree

Output: K linked lists if the height of tree is k. Each linked list will have all the nodes of each level.
*/
#include<iostream>
#include<queue>
#include<list>
using namespace std;
struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node* newnode(int data)
{
	Node* node = (Node*)
		malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

void makelistUtil(Node *root, vector<list<Node *> *> &v, int level, int &maxlevel)
{
	if (!root)
		return;
	if (maxlevel < level)
	{
		list<Node *> *l = new list<Node*>;
		v.push_back(l);
		v[level - 1]->push_back(root);
		maxlevel++;
	}
	else
	{
		v[level - 1]->push_back(root);
	}
	makelistUtil(root->left, v, level + 1, maxlevel);
	makelistUtil(root->right, v, level + 1, maxlevel);
}
void makeList(Node *root)
{
	vector<list<Node *> *> v;
	int maxlevel = 0;
	makelistUtil(root, v, 1, maxlevel);
	vector<list<Node *> *>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
	{
		list<Node *>::iterator i;
		for (i = (*it)->begin(); i != (*it)->end(); i++)
		{
			cout << (*i)->data << " ";
		}
		cout << "\n";
	}
}
/* Driver program to test above functions*/
int main()
{

	/* Constructed binary tree is
	10
	/   \
	8      2
	/         \
	3            90
	*/
	Node *root = newnode(10);
	root->left = newnode(8);
	root->right = newnode(2);
	root->left->left = newnode(3);
	root->right->right = newnode(90);

	makeList(root);

	return 0;
}
