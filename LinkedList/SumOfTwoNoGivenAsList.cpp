#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

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
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

int listSize(Node *head_ref)
{
	int size = 0;
	while (head_ref)
	{
		size++;
		head_ref = head_ref->next;
	}
	return size;
}
void appendZero(Node **head_ref, int count)
{
	Node *temp = NULL;
	for (int i = 0; i < count; i++)
	{
		push(&temp, 0);
	}
	Node *t = temp;
	while (t->next)
		t = t->next;
	t->next = *head_ref;
	*head_ref = temp;
}

int addUtil(Node *one, Node *two, Node **res)
{

	if (one == NULL&&two == NULL)
	{
		return 0;
	}
	int base = 0;
	int carr;
	carr = addUtil(one->next, two->next, res);
	int data = one->data + two->data + carr;
	if (data > 9)
	{
		base = data % 10;
		carr = 1;
	}
	else
	{
		carr = 0;
		base = data;
	}
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = base;
	if (*res == NULL)
	{
		temp->next = NULL;
		*res = temp;
	}
	else
	{
		temp->next = *res;
		*res = temp;
	}
	return carr;
}
Node *addNo(Node *one, Node *two)
{
	int size1 = listSize(one);
	int size2 = listSize(two);
	if (size1 > size2)
		appendZero(&two, size1 - size2);
	else if (size1 < size2)
		appendZero(&one, size2 - size1);
	Node *res = NULL;
	int carr = addUtil(one, two, &res);
	if (carr > 0)
	{
		Node *temp = (Node *)malloc(sizeof(Node));
		temp->data = carr;
		temp->next = res;
		res = temp;
	}
	return res;
}
int main()
{
	Node* no1 = NULL;
	Node *no2 = NULL;
	Node *res = NULL;
	push(&no1, 9);
	push(&no1, 2);
	push(&no1, 3);

	push(&no2, 9);
	push(&no2, 8);
	push(&no2, 9);

	cout << "No are : \n";

	printList(no1);
	printList(no2);

	res = addNo(no1, no2);

	cout << "result is : \n";
	printList(res);
	return 0;
}
