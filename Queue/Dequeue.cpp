#include<iostream>
using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node *prev;
	Node *next;
	Node(T data)
	{
		this->data = data;
		prev = NULL;
		next = NULL;
	}
};

template <typename T>
class Dequeue
{
	Node<T> *head;
public:
	Dequeue();
	void pushBack(T data);
	void pushFront(T data);
	T popFront();
	T popBack();
	int size();
};
template <typename T>
Dequeue<T>::Dequeue()
{
	head = NULL;
}
template <typename T>
void Dequeue<T>::pushBack(T data)
{
	Node<T> *mNode = new Node<T>(data);
	if (head == NULL)
	{
		head = mNode;
		head->next = head;
		head->prev = head;
		return;
	}
	mNode->next = head;
	head->prev->next = mNode;
	mNode->prev = head->prev;
	head->prev = mNode;
}
template <typename T>
void Dequeue<T>::pushFront(T data)
{
	pushBack(data);
	head = head->prev;
}
template <typename T>
T Dequeue<T>::popFront()
{
	if (head == NULL)
	{
		cout << "dequeue empty!!\n";
		exception e1;
		throw e1;
	}
	T data;
	if (head->next == head)
	{
		data = head->data;
		head = NULL;
	}
	else
	{
		head = head->next;
		data = popBack();
	}
	return data;
}
template <typename T>
T Dequeue<T>::popBack()
{
	if (head == NULL)
	{
		cout << "dequeue empty!!\n";
		exception e1;
		throw e1;
	}
	if (head->next == head)
	{
		T data = head->data;
		head = NULL;
		return data;
	}
	Node<T> *temp = head->prev->prev;
	temp->next = head;
	T data = head->prev->data;
	free(head->prev);
	head->prev = temp;
	return data;
}
template <typename T>
int Dequeue<T>::size()
{
	int c = 0;
	if (head == NULL)
		return 0;
	Node<T> *temp = head;
	do
	{
		temp = temp->next;
		c++;
	} while (temp != head);
	return c;
}
int main()
{
	Dequeue<int> dq;
	dq.pushFront(1);
	dq.pushFront(2);
	cout << dq.popFront();
	dq.pushBack(3);
	dq.pushBack(4);
	cout << dq.size();
	cout << dq.popBack();
	return 0;
}