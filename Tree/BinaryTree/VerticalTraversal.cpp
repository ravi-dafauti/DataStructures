#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};
struct DataNode
{
	int data;
	DataNode *next;
};
struct ListNode
{
	DataNode *data;
	DataNode *tail;
	ListNode *next;
	ListNode *prev;
};

DataNode *createDataNode(int data)
{
	DataNode *temp = (DataNode *)malloc(sizeof(DataNode));
	temp->data = data;
	temp->next = NULL;
	return temp;
}
ListNode * makeListNode()
{
	ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL)
	{
		cout << "out of memory!!";
		exception e;
		throw e;
	}
	temp->data = NULL;
	temp->tail = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
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
	void printList(ListNode *);
public:
	Tree();
	void copyTree(Node *);
	Node *getRoot();
	void verticalTraversalUtil(Node *, ListNode **);
	void verticalTraversal(Node *);
};

void Tree::printList(ListNode *head)
{
	while (head->prev)
		head = head->prev;
	while (head)
	{
		DataNode *temp = head->data;
		while (temp)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		head = head->next;
	}
}
void Tree::verticalTraversal(Node *root_ref)
{
	ListNode *head = makeListNode();
	verticalTraversalUtil(root_ref, &head);
	printList(head);
}
void Tree::verticalTraversalUtil(Node *root_ref, ListNode **head_ref)
{
	if (root_ref == NULL)
		return;
	DataNode *temp = createDataNode(root_ref->data);
	if ((*head_ref)->data == NULL)
	{
		(*head_ref)->data = temp;
		(*head_ref)->tail = temp;
	}
	else
	{
		(*head_ref)->tail->next = temp;
		(*head_ref)->tail = temp;
	}
	if (root_ref->left != NULL)
	{
		if ((*head_ref)->prev == NULL)
		{
			ListNode *temp = makeListNode();
			temp->next = *head_ref;
			(*head_ref)->prev = temp;
		}
		verticalTraversalUtil(root_ref->left, &(*head_ref)->prev);
	}
	if (root_ref->right != NULL)
	{
		if ((*head_ref)->next == NULL)
		{
			ListNode *temp = makeListNode();
			temp->prev = *head_ref;
			(*head_ref)->next = temp;
		}
		verticalTraversalUtil(root_ref->right, &(*head_ref)->next);
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
	binaryTree.verticalTraversal(binaryTree.getRoot());
	return 0;
}