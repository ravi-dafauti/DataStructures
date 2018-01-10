#include<iostream>
#include<queue>
using namespace std;

class Stack
{
	queue<int> q1;
	queue<int> q2;
public:
	int size();
	void push(int);
	void pop();
	int top();
	bool empty();
};
int Stack::size()
{
	return q1.size() + q2.size();
}
void Stack::push(int data)
{
	if (q2.empty())
		q1.push(data);
	else
		q2.push(data);
}
void Stack::pop()
{
	int c;
	if (!q1.empty())
	{
		c = q1.size();
		while (c > 1)
		{
			q2.push(q1.front());
			q1.pop();
			c--;
		}
		q1.pop();
	}
	else
	{
		c = q2.size();
		while (c > 1)
		{
			q1.push(q2.front());
			q2.pop();
			c--;
		}
		q2.pop();
	}
		
}
int Stack::top()
{
	int c;
	int res;
	if (!q1.empty())
	{
		c = q1.size();
		while (c > 1)
		{
			q2.push(q1.front());
			q1.pop();
			c--;
		}
		res = q1.front();
		q2.push(q1.front());
		q1.pop();
	}
	else
	{
		c = q2.size();
		while (c > 1)
		{
			q1.push(q2.front());
			q2.pop();
			c--;
		}
		res = q2.front();
		q1.push(q2.front());
		q2.pop();
	}
	return res;
}
bool Stack::empty()
{
	if (q1.empty() && q2.empty())
		return true;
	return false;
}
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.size();
	cout << s.top();
	s.pop();
	cout << s.top();
	s.pop();
	cout << s.top();
	s.pop();
	return 0;
}
