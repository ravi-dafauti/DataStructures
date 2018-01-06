#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};

void insertToList(node **head, int pos, int data)
{
	node *temp = (node*)malloc(sizeof(node));
	if(temp == NULL)
	{
		cout << "memory error\n";
		return;
	}
	temp->data = data;
	temp->next = NULL;
	if (*head == NULL)
	{
		*head = temp;
		temp->next = temp;
		return;
	}
	node *t = *head;
	int size = 1;
	while (t->next != *head)
	{
		t = t->next;
		size++;
	}
	if (pos > size + 1)
	{
		cout << "position does not exists\n";
		return;
	}
	if (pos == 1)
	{
		temp->next = *head;
		*head = temp;
		t->next = temp;
		return;
	}
	node *t1 = *head;
	int c = 1;
	while (c<pos)
	{
		if (c == pos - 1)
		{
			temp->next = t1->next;
			t1->next = temp;
			return;
		}
		t1 = t1->next;
		c++;
	}
}

void deleteFromList(node **head, int pos)
{
	if (*head == NULL)
	{
		cout << "no elements to delete\n";
		return;
	}
	node *t = *head;
	int size = 1;
	while (t->next != *head)
	{
		t = t->next;
		size++;
	}
	if (pos > size)
	{
		cout << "position does not exists\n";
		return;
	}
	if (pos == 1)
	{
		node *temp = *head;
		*head = (*head)->next;
		t->next = *head;
		free(temp);
		return;
	}
	node *t1 = *head;
	node *prev = NULL;
	int c = 1;
	while (c <= pos)
	{
		if (c == pos)
		{
			prev->next = t1->next;
			free(t1);
			return;
		}
		prev = t1;
		t1 = t1->next;
		c++;
	}
}

void printList(node *head)
{
	node *t = head;
	if (head == NULL)
		return;
	do
	{
		cout << head->data << "->";
		head = head->next;
	} while (head != t);
	cout << "\n";
}
int main()
{
	node *head=NULL;
	for (int i = 1; i <= 4; i++)
	{
		insertToList(&head, i, i);
	}
	printList(head);
	deleteFromList(&head, 4);
	printList(head);
	return 0;
}