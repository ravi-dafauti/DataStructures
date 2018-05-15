/*
Given some resources in the form of linked list you have to canceled out all the resources whose sum up to 0(Zero) and return the remaining list.

E.g-->> 6 -6 8 4 -12 9 8 -8

the above example lists which gets canceled :
6 -6
8 4 -12
8 -8
o/p : 9
case 3 : 4 6 -10 8 9 10 -19 10 -18 20 25
O/P : 20 25
*/
#include<iostream>
#include<unordered_map>
using namespace std;

/* Link list node */
struct Node
{
	int data;
	Node* next;
};


void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node =
		(Node*) malloc(sizeof(Node));

	/* put in the data  */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

// A utility function to print a given linked list
void printList(Node *ptr)
{
	while (ptr != NULL)
	{
		printf("%d->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

Node *stripZero(Node *head)
{
	if (!head)
		return NULL;
	Node *t = head;
	Node *prev = NULL;
	while (t)
	{
		if (t->data == 0 && t==head)
		{
			head = head->next;
			free(t);
			t = head;
		}
		else if (t->data != 0)
		{
			prev = t;
			t = t->next;
		}
		else
		{
			prev->next = t->next;
			free(t);
			t = prev->next;
		}
	}
	return head;
}
Node *removeZero(Node *head)
{
	if (!head || (head->next==NULL&&head->data==0))
		return NULL;
	if (!head->next)
		return head;
	head = stripZero(head);
	if (!head)
		return NULL;
	unordered_map<int, Node *> mMap;
	Node *t = head;
	int sum;
	while (t)
	{
		if (t == head)
		{
			t = head->next;
			sum = head->data;
			mMap[sum] = head;
		}
		else
		{
			sum += t->data;
			if (sum == 0)
			{
				head = t->next;
				t = t->next;
				mMap.clear();
			}
			else
			{
				if (mMap.find(sum) != mMap.end())
				{
					mMap[sum]->next = t->next;
				}
				else
				{
					mMap[sum] = t;
				}
				t = t->next;
			}
		}
	}
	return head;
}
/* Drier program to test above function*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;
	int i;
	push(&head, 0);
	push(&head, 0);
	push(&head, 7);
	push(&head, 8);
	push(&head, -8);
	push(&head, 25);
	push(&head, 20);
	push(&head, -18);
	push(&head,10);
	push(&head, -19);
	push(&head, 10);
	push(&head, 9);
	push(&head, 0);
	push(&head, 8);
	push(&head, 0);
	push(&head, -10);
	push(&head, 6);
	push(&head, 4);
	push(&head, 0);
	push(&head, 0);
	push(&head, 0);
	printList(head);
	cout << "\n";
	head = removeZero(head);
	printList(head);
	return 0;
}