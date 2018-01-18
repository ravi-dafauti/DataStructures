#include<iostream>
using namespace std;

struct Node
{
	int data;

	struct Node* next;
	struct Node* prev;
};


/* Function to insert a node at the beginging of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node =
		(Node*) malloc(sizeof(Node));

	/* put in the data  */
	new_node->data = new_data;

	/* since we are adding at the begining,
	prev is always NULL */
	new_node->prev = NULL;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* change prev of head node to new node */
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

/* A utility function to print preorder traversal of BST */
void preOrder(Node* node)
{
	if (node == NULL)
		return;
	cout << node->data << " ";
	preOrder(node->prev);
	preOrder(node->next);
}

Node *findMidNode(Node *head_ref)
{
	Node *slow, *fast;
	slow = fast = head_ref;
	if (head_ref == NULL || head_ref->next == NULL)
		return head_ref;
	while (fast->next&&fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
Node *CreateBST(Node *list_head)
{
	if (list_head == NULL || list_head->next == NULL)
		return list_head;
	Node *temp = findMidNode(list_head);
	if (temp->prev)
		temp->prev->next = NULL;
	if (temp->next)
		temp->next->prev = NULL;
	temp->prev = CreateBST(list_head);
	temp->next = CreateBST(temp->next);
	return temp;
}
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	/* Let us create a sorted linked list to test the functions
	Created linked list will be 7->6->5->4->3->2->1 */
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	cout<<"Given Linked List\n";
	printList(head);

	Node *root = CreateBST(head);
	preOrder(root);
	return 0;
}