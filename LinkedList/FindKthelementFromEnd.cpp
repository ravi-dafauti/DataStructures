// FindKthelementFromEnd.cpp : Defines the entry point for the console application.
#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

void kElementFromLast(Node **head_ref, int k)
{
	if (*head_ref == NULL)
	{
		cout << "list empty\n";
		return;
	}
	Node *ptr = *head_ref;
	Node *temp = NULL;
	int c = k;
	while (k)
	{
		if (temp == NULL)
			temp = *head_ref;
		else
		{
			temp = temp->next;
		}
		k--;
	}
	ptr = *head_ref;
	while (temp->next)
	{
		temp = temp->next;
		ptr = ptr->next;
	}
	cout << c <<"th element from last = " << ptr->data << "\n";
}
/* Function to push a node */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	/* put in the data  */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
}

/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 85);

	printf("Given linked list\n");
	printList(head);

	kElementFromLast(&head, 2);

	return 0;
}
