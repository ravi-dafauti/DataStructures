#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};

bool isCycle(Node *head)
{
	Node *slow = head;
	Node *fast = head;
	while (slow&&fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
		{
			return true;
		}
	}
	return false;
}

Node *beginOfCycle(Node *head)
{
	Node *slow = head;
	Node *fast = head;
	while (slow&&fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
		{
			slow = head;
			break;
		}
	}
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast-> next;
	}
	return slow;
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
}
int main()
{
	Node *head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	Node *t = head;
	while (t->next)
	{
		t = t->next;
	}
	t->next = head;
	if (isCycle(head))
	{
		cout << "there is cycle\n";
		cout << "begin of cycle : " << beginOfCycle(head)->data << "\n";
	}
	else
	{
		cout << "no cycle\n";
	}
	return 0;
}