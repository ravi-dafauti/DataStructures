#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};

//recursive version 
Node *reverseInPairRecursive(Node *head_ref)
{
	if (head_ref == NULL)
		return NULL;
	if (head_ref->next == NULL)
		return head_ref;
	Node *t = head_ref->next->next;
	Node *temp;
	head_ref->next->next = head_ref;
	temp = head_ref;
	head_ref = head_ref->next;
	temp->next = reverseInPairRecursive(t);
	return head_ref;
}
 //iterative version
void reverseInPairIterative(Node **head_ref)
{
	Node *temp = *head_ref;
	Node *pref = NULL;
	while (temp&&temp->next)
	{
		Node *t = temp->next->next;
		temp->next->next = temp;
		if (temp == *head_ref)
		{
			*head_ref = temp->next;
			 pref = temp;
		}
		else
		{
			pref->next = temp->next;
			pref = temp;
		}
		temp = t;
	}
	pref->next = temp;
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
	cout << "List before\n";
	printList(head);
	cout << "List after pair reversal\n";
	reverseInPairIterative(&head);
	printList(head);
	return 0;
}