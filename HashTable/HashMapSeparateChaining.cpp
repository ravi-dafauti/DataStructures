#include<iostream>
using namespace std;
struct Node
{
	int key;
	int data;
	Node *next;
};
struct TableNode
{
	int count;
	Node *next;
};
class HashTable
{
	int size;
	int elementcount;
	int loadFactor;
	TableNode *table;
	int hash(int);
	void reHash();
public:
	HashTable();
	void push(int, int);
	void deleteFromHash(int);
	int search(int);
	int valueAt(int);
};

int HashTable::hash(int key)
{
	return key%size;
}

void HashTable::reHash()
{

	TableNode *oldTable = table;
	size = size * 2;
	TableNode *newTable = (TableNode*)malloc(sizeof(TableNode)*size);
	for (int i = 0; i < size; i++)
	{
		newTable[i].next = NULL;
	}
	table = newTable;
	for (int i = 0; i < size / 2; i++)
	{
		Node *temp = oldTable[i].next;
		Node *temp2;
		while (temp)
		{
			int index = hash(temp->key);
			temp2 = temp;
			temp = temp->next;
			temp2->next = table[index].next;
			table[index].next = temp2;
		}
	}
	free(oldTable);
}
HashTable::HashTable()
{
	size = 11;
	loadFactor = 3;
	elementcount = 0;
	table = (TableNode*)malloc(sizeof(TableNode)*size);
	for (int i = 0; i < size; i++)
	{
		table[i].count = 0;
		table[i].next = NULL;
	}
}

void HashTable::push(int key, int data)
{
	if (search(key))
		return;
	int index = hash(key);
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->key = key;
	temp->data = data;
	temp->next = NULL;
	table[index].count++;
	temp->next = table[index].next;
	table[index].next = temp;
	elementcount++;
	if ((elementcount / size) > loadFactor)
		reHash();
}

void HashTable::deleteFromHash(int key)
{
	int index = hash(key);
	Node *temp, *prev = NULL;
	if (!search(key))
	{
		cout << "key not found\n";
		exception e;
		throw e;
	}
	temp = table[index].next;
	if (temp->key == key)
	{
		table[index].next = temp->next;
		free(temp);
		return;
	}
	while (temp)
	{

		if (temp->key == key)
		{
			prev->next = temp->next;
			free(temp);
			return;
		}
		prev = temp;
		temp = temp->next;
	}
	table[index].count--;
	elementcount--;
}

int HashTable::search(int key)
{
	int index = hash(key);
	Node *temp;
	temp = table[index].next;
	while (temp)
	{
		if (temp->key == key)
			return 1;
		temp = temp->next;
	}
	return 0;
}

int HashTable::valueAt(int key)
{
	int index = hash(key);
	Node *temp;
	if (!search(key))
	{
		cout << "key not found\n";
		return -1;
	}
	temp = table[index].next;
	while (temp)
	{
		if (temp->key == key)
			return temp->data;
		temp = temp->next;
	}
	return -1;
}
int main()
{
	HashTable h;
	h.push(1, 2);
	h.push(3, 4);
	cout << h.valueAt(3);
	h.deleteFromHash(1);
	cout << h.search(3);
	return 0; 
}