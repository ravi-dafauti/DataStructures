// FindKthelementFromEnd.cpp : Defines the entry point for the console application.

#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

void fractionNode(Node **head_ref, int k)
{
	if (k <= 0)
	{
		cout << "wrong value for k\n";
		return;
	}
	if (*head_ref == NULL)
	{
		cout << "list empty\n";
		return;
	}
	Node *temp = *head_ref;
	Node *frac = NULL;
	for (int i = 1; temp != NULL; i++,temp=temp->next)
	{
		if (i%k == 0)
		{
			if (frac == NULL)
				frac = *head_ref;
			else
				frac = frac->next;
		}
	}
	cout << "fraction node is : " << frac->data << "\n";
}


void push(Node** head_ref, int new_data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));

	new_node->data = new_data;
	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void printList(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
}

int main()
{
	struct Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 85);

	printf("Given linked list\n");
	printList(head);

	fractionNode(&head, 2);

	return 0;
}
