/*
Given a linked list where in addition to the next pointer, each node has a child pointer, which may or may not point to a separate list. 
These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in below figure.
You are given the head of the first level of the list. Flatten the list so that all the nodes appear in a single-level linked list. 
You need to flatten the list in way that all nodes at first level should come first, then nodes of second level, and so on.
*/

#include<iostream>
using namespace std;

// Macro to find number of elements in array
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

// A linked list node has data, next pointer and child pointer
struct Node
{
	int data;
	Node *next;
	Node *child;
};

// A utility function to create a linked list with n nodes. The data
// of nodes is taken from arr[].  All child pointers are set as NULL
Node *createList(int *arr, int n)
{
	Node *head = NULL;
	Node *p;

	int i;
	for (i = 0; i < n; ++i) {
		if (head == NULL)
			head = p = (Node *)malloc(sizeof(*p));
		else {
			p->next = (Node *)malloc(sizeof(*p));
			p = p->next;
		}
		p->data = arr[i];
		p->next = p->child = NULL;
	}
	return head;
}

// A utility function to print all nodes of a linked list
void printList(Node *head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

// This function creates the input list.  The created list is same
// as shown in the above figure
Node *createList(void)
{
	int arr1[] = { 10, 5, 12, 7, 11 };
	int arr2[] = { 4, 20, 13 };
	int arr3[] = { 17, 6 };
	int arr4[] = { 9, 8 };
	int arr5[] = { 19, 15 };
	int arr6[] = { 2 };
	int arr7[] = { 16 };
	int arr8[] = { 3 };

	/* create 8 linked lists */
	Node *head1 = createList(arr1, SIZE(arr1));
	Node *head2 = createList(arr2, SIZE(arr2));
	Node *head3 = createList(arr3, SIZE(arr3));
	Node *head4 = createList(arr4, SIZE(arr4));
	Node *head5 = createList(arr5, SIZE(arr5));
	Node *head6 = createList(arr6, SIZE(arr6));
	Node *head7 = createList(arr7, SIZE(arr7));
	Node *head8 = createList(arr8, SIZE(arr8));


	/* modify child pointers to create the list shown above */
	head1->child = head2;
	head1->next->next->next->child = head3;
	head3->child = head4;
	head4->child = head5;
	head2->next->child = head6;
	head2->next->next->child = head7;
	head7->child = head8;


	/* Return head pointer of first linked list.  Note that all nodes are
	reachable from head1 */
	return head1;
}
void flattenList(Node *head)
{
	if (!head)
		return;
	Node *tail = head;
	while (tail->next != NULL)
		tail = tail->next;
	Node *curr = head;
	while (curr)
	{
		if (curr->child != NULL)
		{
			tail->next = curr->child;
			while (tail->next != NULL)
				tail = tail->next;
		}
		curr = curr->next;
	}
}
int main()
{
	Node *head = NULL;
	head = createList();
	flattenList(head);
	printList(head);
	return 0;
}