#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};

//recursive method to reverse a linked list

Node *reverseRecur(Node* head_ptr)
{
	if (head_ptr == NULL)
		return NULL;
	if (head_ptr->next == NULL)
	{
		return head_ptr;
	}
	Node *temp = head_ptr->next;
	Node *t = head_ptr;
	t->next = NULL;
	head_ptr = reverseRecur(temp);
	temp->next = t;
	return head_ptr;
}

//iterative method to reverse a linked list

void iterativeReverse(Node **head_ptr)
{
	Node *temp;
	Node *t = NULL;
	Node *next = *head_ptr;
	while (next)
	{
		temp = next;
		next = next->next;
		temp->next = t;
		t = temp;
	}
	*head_ptr = t;
}
void push(Node** head_ref, int new_data)
{
	Node* new_node =
		(Node*) malloc(sizeof(struct Node));

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
	Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 85);

	printf("Given linked list\n");
	printList(head);
	iterativeReverse(&head);
	printf("\nReversed Linked list \n");
	printList(head);
	getchar();
}