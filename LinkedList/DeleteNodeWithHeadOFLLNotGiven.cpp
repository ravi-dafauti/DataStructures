#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};

void push(Node** head_ref, int new_data)
{
	Node* new_node =
		(Node*)malloc(sizeof(struct Node));

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
	cout << "\n";
}
void deleteNode(Node *ref)
{
	if (ref->next == NULL)
	{
		free(ref);
		return;
	}
	ref->data = ref->next->data;
	Node *t = ref->next;
	ref->next = t->next;
	free(t);
}
int main()
{
	Node *head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 6);
	push(&head, 2);
	push(&head, 1);
	printList(head);
	deleteNode(head);
	printList(head);
	return 0;
}