#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

void insertList(node **head, int pos, node *temp)
{
	if (*head == NULL)
	{
		if (pos != 1)
		{
			cout << "position dosent exists\n";
			return;
		}
		*head = temp;
		return;
	}
	if (pos == 1)
	{
		temp->next = *head;
		*head = temp;
		return;
	}
	node *t = *head;
	int c = 1;
	while (c<pos)
	{
		if (t == NULL)
		{
			cout << "position doesnt exists\n";
			return;
		}
		if (c == pos - 1)
		{

			temp->next = t->next;
			t->next = temp;
			return;
		}
		else
		{
			t = t->next;
			c++;
		}
	}
}

void deleteListElement(node **head, int pos)
{
	if (*head == NULL)
	{
		cout << "no elements to delete\n";
		return;
	}
	if (pos == 1)
	{
		node *temp = *head;
		*head = temp->next;
		free(temp);
		return;
	}
	node *t = *head;
	node *prev = NULL;
	int c = 1;
	while (c<=pos)
	{
		if (t == NULL)
		{
			cout << "position doesnt exists\n";
			return;
		}
		if (c == pos)
		{

			prev->next = t->next;
			free(t);
			return;
		}
		else
		{
			prev = t;
			t = t->next;
			c++;
		}
	}
}
void printList(node *head)
{
	while (head)
	{
		cout << head->data << "->";
		head = head->next;
	}
	cout << "\n";
}
int main()
{
	node *head = NULL;
	for (int i = 1; i <= 4; i++)
	{
		node *n1 = (node *)malloc(sizeof(node));
		n1->data = i;
		n1->next = NULL;
		insertList(&head, i, n1);
	}
	printList(head);
	deleteListElement(&head, 3);
	printList(head);
	return 0;
}

