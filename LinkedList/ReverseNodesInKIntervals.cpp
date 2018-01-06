#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};

int sizeOfList(Node *head)
{
	int c = 0;
	while (head)
	{
		c++;
		head = head->next;
	}
	return c;
}

void reverseList(Node** head_ref)
{
	Node* prev = NULL;
	Node* current = *head_ref;
	Node* next;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}
//recursive version 
Node *reverseInKInterval(Node *head_ref, int k)
{
	if (sizeOfList(head_ref) < k || k == 0 || k == 1)
		return head_ref;
	if (head_ref == NULL)
		return NULL;
	Node *temp = head_ref;
	Node *next;
	Node *t = head_ref;
	int c = k;
	while (c - 1)
	{
		temp = temp->next;
		c--;
	}
	next = temp->next;
	temp->next = NULL;
	reverseList(&head_ref);
	t->next = reverseInKInterval(next, k);
	return head_ref;
}

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
int main()
{
	Node *head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	push(&head, 6);
	push(&head, 7);
	push(&head, 8);
	push(&head, 9);
	push(&head, 10);
	cout << "List before\n";
	printList(head);
	cout << "List after pair reversal\n";
	head = reverseInKInterval(head, 3);
	printList(head);
	return 0;
}