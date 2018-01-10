#include<iostream>
#include<stack>
using namespace std;
class Queue
{
	stack<int> s1;
	stack<int> s2;
public:
	void enqueue(int);
	int deQueue();
	int size();
	bool empty();
	int front();
};
void Queue::enqueue(int data)
{
	s1.push(data);
}
int Queue::deQueue()
{
	if (!s2.empty())
	{
		int f = s2.top();
		s2.pop();
		return f;
	}
	else
	{
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		int f = s2.top();
		s2.pop();
		return f;
	}
	return -1;
}
int Queue::size()
{
	return s1.size() + s2.size();
}
bool Queue::empty()
{
	if (s1.empty() && s2.empty())
		return true;
	return false;
}
int Queue::front()
{
	if (!s2.empty())
	{
		int f = s2.top();
		return f;
	}
	else
	{
		int c = 0;
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
			c++;
		}
		int f = s2.top();
		while (c)
		{
			s1.push(s2.top());
			s2.pop();
			c--;
		}
		return f;
	}
	return -1;
}
int main()
{
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	cout << q.deQueue();
	cout << q.deQueue();
	cout << q.deQueue();
	return 0;
}