/*
Given a linked list where every node represents a linked list and contains two pointers of its type:
(i) Pointer to next node in the main list (we call it ‘right’ pointer in below code)
(ii) Pointer to a linked list where this node is head (we call it ‘down’ pointer in below code).
All linked lists are sorted. See the following example

5 -> 10 -> 19 -> 28
|    |     |     |
V    V     V     V
7    20    22    35
|          |     |
V          V     V
8          50    40
|                |
V                V
30               45
Write a function flatten() to flatten the lists into a single linked list. The flattened linked list should also be sorted. For example, for the above input list, output list should be 5->7->8->10->19->20->22->28->30->35->40->45->50
*/
#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *right;
	struct Node *down;
};

/* A utility function to insert a new node at the begining
of linked list */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = (Node *)malloc(sizeof(Node));
	new_node->right = NULL;

	/* put in the data  */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->down = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in the flattened linked list */
void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->down;
	}
}
Node *mergeLists(Node *a, Node *b)
{
	if (!a)
		return b;
	if (!b)
		return a;
	Node *temp = (Node *)malloc(sizeof(Node));
	Node *t = temp;
	while (a&&b)
	{
		if (a->data < b->data)
		{
			t->down = a;
			t = t->down;
			a = a->down;
		}
		else
		{
			t->down = b;
			t = t->down;
			b = b->down;
		}
	}
	while (a)
	{
		t->down = a;
		t = t->down;
		a = a->down;
	}
	while (b)
	{
		t->down = b;
		t = t->down;
		b = b->down;
	}
	t = temp->down;
	free(temp);
	return t;
}
Node *flatten(Node *head)
{
	if (!head)
		return NULL;
	if (!head->right)
		return head;
	Node *merge = head;
	Node *curr = head->right;
	head->right = NULL;
	while (curr)
	{
		Node *temp = curr;
		curr = curr->right;
		temp->right = NULL;
		merge = mergeLists(merge, temp);
	}
	return merge;
}
int main()
{
	Node* root = NULL;

	/* Let us create the following linked list
	5 -> 10 -> 19 -> 28
	|    |     |     |
	V    V     V     V
	7    20    22    35
	|          |     |
	V          V     V
	8          50    40
	|                |
	V                V
	30               45
	*/
	push(&root, 30);
	push(&root, 8);
	push(&root, 7);
	push(&root, 5);

	push(&(root->right), 20);
	push(&(root->right), 10);

	push(&(root->right->right), 50);
	push(&(root->right->right), 22);
	push(&(root->right->right), 19);

	push(&(root->right->right->right), 45);
	push(&(root->right->right->right), 40);
	push(&(root->right->right->right), 35);
	push(&(root->right->right->right), 28);

	// Let us flatten the list
	root = flatten(root);

	// Let us print the flatened linked list
	printList(root);

	return 0;
}