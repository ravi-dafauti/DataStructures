// reverse a stack using only stack operations
#include<iostream>
#include<stack>
using namespace std;

void insertToBottom(stack<int> &s, int temp)
{
	if (s.empty())
	{
		s.push(temp);
		return;
	}
	int data = s.top();
	s.pop();
	insertToBottom(s, temp);
	s.push(data);
}
void reverseStack(stack<int> &s)
{
	if (s.empty())
		return;
	int temp = s.top();
	s.pop();
	reverseStack(s);
	insertToBottom(s, temp);
}
int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	reverseStack(s);
	cout << s.top();
	s.pop();
	cout << s.top();
	s.pop();
	cout << s.top();
	s.pop();
	return 0;
}