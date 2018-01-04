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

	kElementFromLast(&head, 2);

	return 0;
}
