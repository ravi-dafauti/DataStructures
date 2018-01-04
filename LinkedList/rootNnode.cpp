#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

void rootNnode(Node **head_ref)
{
	int i = 1;
	int j = 1;
	Node *rootnode = NULL;
	Node *temp = *head_ref;
	while (temp)
	{
		if (i == j*j)
		{
			if (rootnode == NULL)
				rootnode = *head_ref;
			else
				rootnode = rootnode->next;
			j++;
		}
		i++;
		temp = temp->next;
	}

	cout << "root nth node is : " << rootnode->data << "\n";
}


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
		printf("%d  ", temp->data);
		temp = temp->next;
	}
}

int main()
{
	struct Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 85);

	printf("Given linked list\n");
	printList(head);
	rootNnode(&head);
	return 0;
}
