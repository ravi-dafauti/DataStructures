#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};
struct ListNode
{
	int data;
	ListNode *next;
	ListNode *prev;
};

ListNode * makeListNode()
{
	ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL)
	{
		cout << "out of memory!!";
			exception e;
		throw e;
	}
	temp->data = 0;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void printList(ListNode *head)
{
	while (head->prev)
		head = head->prev;
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
}
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
	void verticalSum(Node *, ListNode **);

};

void Tree::verticalSum(Node *root_ref, ListNode **head_ref)
{
	if (root_ref == NULL)
		return;
	(*head_ref)->data = (*head_ref)->data + root_ref->data;
	if (root_ref->left != NULL)
	{
		if ((*head_ref)->prev == NULL)
		{
			ListNode *temp = makeListNode();
			temp->next = *head_ref;
			(*head_ref)->prev = temp;
		}
		verticalSum(root_ref->left, &(*head_ref)->prev);
	}
	if (root_ref->right != NULL)
	{
		if ((*head_ref)->next == NULL)
		{
			ListNode *temp = makeListNode();
			temp->prev = *head_ref;
			(*head_ref)->next = temp;
		}
		verticalSum(root_ref->right, &(*head_ref)->next);
	}

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
	ListNode *head = makeListNode();
	binaryTree.verticalSum(binaryTree.getRoot(), &head);
	printList(head);
	return 0;
}