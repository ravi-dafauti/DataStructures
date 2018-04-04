/*
Given a stack of integers, sort it in ascending order using another temporary stack.

Examples:

Input : [34, 3, 31, 98, 92, 23]
Output : [3, 23, 31, 34, 92, 98]

Input : [3, 5, 1, 4, 2, 8]
Output : [1, 2, 3, 4, 5, 8]
*/

#include<iostream>
#include<stack>
using namespace std;
void sortStack(stack<int> &s,stack<int> &temp)
{
	while (!s.empty())
	{
		int data = s.top();
		s.pop();
		while (!temp.empty() && temp.top() > data)
		{
			s.push(temp.top());
			temp.pop();
		}
		temp.push(data);
	}
}
void sort(stack<int> &s)
{
	stack<int> temp;
	sortStack(s, temp);
	s = temp;
}
int main()
{
	stack<int> input;
	input.push(34);
	input.push(3);
	input.push(31);
	input.push(98);
	input.push(92);
	input.push(23);

	// This is the temporary stack
	sort(input);
	cout << "Sorted numbers are:\n";

	while (!input.empty())
	{
		cout << input.top() << " ";
		input.pop();
	}
    return 0;
}

