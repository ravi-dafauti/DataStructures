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
	int levelWithMaxSum();
};

int Tree::levelWithMaxSum()
{
	int curr_sum = 0;
	int max_sum = 0;
	int curr_level = 0;
	int max_level = 0;
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
			if (curr_sum > max_sum)
			{
				max_sum = curr_sum;
				max_level = curr_level;
			}
			curr_sum = 0;
			curr_level++;
			if (!aux_queue.empty())
			{
				aux_queue.push(NULL);
			}
		}
		else
		{
			curr_sum += temp->data;
			if (temp->left)
				aux_queue.push(temp->left);
			if (temp->right)
				aux_queue.push(temp->right);
		}
	}
	return max_level;
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
	cout << mTree.levelWithMaxSum();
	return 0;
}