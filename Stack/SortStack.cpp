#include<iostream>
#include<stack>
using namespace std;

void pushToCorrectPos(stack<int> &s, int data)
{
	if (s.empty() || s.top() < data)
	{
		s.push(data);
		return;
	}
	int temp = s.top();
	s.pop();
	pushToCorrectPos(s, data);
	s.push(temp);
}
void sortStack(stack<int> &s)
{
	if (s.empty())
		return;
	int temp = s.top();
	s.pop();
	sortStack(s);
	pushToCorrectPos(s, temp);
}
int main()
{
	stack<int> s;
	s.push(1);
	s.push(7);
	s.push(6);
	sortStack(s);
	cout << s.top();
	s.pop();
	cout << s.top();
	s.pop();
	cout << s.top();
	s.pop();
    return 0;
}

