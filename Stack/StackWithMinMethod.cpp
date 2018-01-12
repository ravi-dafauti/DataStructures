#include<iostream>
#include<stack>
using namespace std;

class Stack
{
	stack<int> main_stack;
	stack<int> aux_stack;
public:
	void push(int data);
	void pop();
	int top();
	bool empty();
	int min();
};
void Stack::push(int data)
{
	if (aux_stack.empty() || data <= aux_stack.top())
	{
		aux_stack.push(data);
	}
	main_stack.push(data);
}
void Stack::pop()
{
	if (main_stack.top() == aux_stack.top())
	{
		aux_stack.pop();
	}
	main_stack.pop();
}
int Stack::top()
{
	return main_stack.top();
}
bool Stack::empty()
{
	return main_stack.empty();
}
int Stack::min()
{
	return aux_stack.top();
}
int main()
{
	Stack s;
	s.push(0);
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.min();
	s.pop();
	s.pop();
	cout << s.min();
	s.push(-1);
	cout << s.min();
	s.pop();
	cout << s.min();
	return 0;
}
