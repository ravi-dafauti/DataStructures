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

bool isPalindrome(Node *head_ref)
{
	Node *temp = head_ref;
	Node *t = head_ref;
	Node *next;
	int size = sizeOfList(head_ref);
	int c = size / 2;
	while (c - 1)
	{
		temp = temp->next;
		c--;
	}
	next = temp->next;
	temp->next = NULL;
	reverseList(&head_ref);
	t->next = next;
	if (size % 2 != 0)
		next = next->next;
	while (next)
	{
		if (head_ref->data != next->data)
			return false;
		head_ref = head_ref->next;
		next = next->next;
	}
	return true;
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
	push(&head, 6);
	push(&head, 2);
	push(&head, 1);
	printList(head);
	if (isPalindrome(head))
	{
		cout << "is palindrome\n";
	}
	else
		cout << "not a palindrome\n";
	return 0;
}

