/*
Implement a stack using single queue
We are given queue data structure, the task is to implement stack using only given queue data structure.
*/
#include<iostream>
#include<queue>
using namespace std;

class Stack
{
	queue<int> q;
public:
	void push(int a);
	void pop();
	int top();
	bool isEmpty();
};
void Stack::push(int a)
{
	q.push(a);
	int s = q.size();
	while (s > 1)
	{
		q.push(q.front());
		q.pop();
		s--;
	}
}
void Stack::pop()
{
	q.pop();
}
int Stack::top()
{
	return q.front();
}
bool Stack::isEmpty()
{
	return q.empty();
}
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	cout << s.top();
	s.pop();
	s.push(3);
	s.push(5);
	cout << s.top();
	
    return 0;
}

