#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

void middleNode(Node **head_ref)
{
	if (*head_ref == NULL)
		return;
	Node *slow = *head_ref;
	Node *fast = *head_ref;
	while (slow&&fast->next&&fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << "middle node is : " << slow->data << "\n";
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

	middleNode(&head);
	return 0;
}
