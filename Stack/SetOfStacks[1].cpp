#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class SetOfStacks
{
	vector<stack<int>> set_of_stacks;
	int max;
	int stackIndex;
	void adjustElementsUtil(int);
	void adjustElements(int stack_index);
public:
	SetOfStacks(int);
	void push(int);
	void pop();
	int top();
	int popFromStackAt(int);
	int size();
	int sizeOfStackAt(int);
	int topOfStackAt(int);
};

SetOfStacks::SetOfStacks(int limit)
{
	stackIndex = 0;
	max = limit;
	stack<int> s;
	set_of_stacks.push_back(s);
}
void SetOfStacks::push(int data)
{
	if (set_of_stacks.at(stackIndex).size() == max)
	{
		stackIndex++;
		if (set_of_stacks.size() == stackIndex)
		{
			stack<int> s;
			set_of_stacks.push_back(s);
		}
	}
	set_of_stacks.at(stackIndex).push(data);
}
void SetOfStacks::pop()
{
	set_of_stacks.at(stackIndex).pop();
	if (set_of_stacks.at(stackIndex).empty())
		stackIndex--;
}

int SetOfStacks::top()
{
	return set_of_stacks.at(stackIndex).top();
}

void SetOfStacks::adjustElementsUtil(int stack_index)
{
	if (set_of_stacks.at(stack_index + 1).size() == 1)
	{
		int bottom = set_of_stacks.at(stack_index + 1).top();
		set_of_stacks.at(stack_index + 1).pop();
		set_of_stacks.at(stack_index).push(bottom);
		return;
	}
	int data = set_of_stacks.at(stack_index + 1).top();
	set_of_stacks.at(stack_index + 1).pop();
	adjustElementsUtil(stack_index);
	set_of_stacks.at(stack_index + 1).push(data);
}
void SetOfStacks::adjustElements(int index)
{
	int i = 0;
	while (index + i < stackIndex)
	{
		adjustElementsUtil(index + i);
		i++;
	}
}
int SetOfStacks::popFromStackAt(int stack_index)
{
	int res;
	if (stack_index > stackIndex)
	{
		cout << "wrong index";
		exception e;
		throw e;
	}
	res = set_of_stacks.at(stack_index).top();
	set_of_stacks.at(stack_index).pop();
	if (stack_index != stackIndex)
	{
		adjustElements(stack_index);
	}
	return res;
}
int SetOfStacks::sizeOfStackAt(int stack_index)
{
	return set_of_stacks.at(stack_index).size();
}

int SetOfStacks::topOfStackAt(int stack_index)
{
	return set_of_stacks.at(stack_index).top();
}
int SetOfStacks::size()
{
	return set_of_stacks.at(stackIndex).size() + max*(stackIndex);
}
int main()
{
	SetOfStacks s(2);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	cout << s.popFromStackAt(0);
	cout << s.topOfStackAt(0);
	cout << s.topOfStackAt(1);
	cout << s.topOfStackAt(2);
	cout << s.sizeOfStackAt(2);
	return 0;
}
