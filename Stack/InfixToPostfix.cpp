#include<iostream>
#include<stack>
using namespace std;

int precedence(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

void infixToPostfix(char *exp)
{
	stack<char> mystack;
	int i = 0;
	while (exp[i] != '\0')
	{
		if (exp[i] != '+' && exp[i] != '-' && exp[i] != '/' && exp[i] != '*' && exp[i] != '(' && exp[i] != ')' && exp[i] != '^')
		{
			cout << exp[i];
		}
		else
		{
			if (exp[i] == '(')
				mystack.push(exp[i]);
			else if (exp[i] == ')')
			{
				while (mystack.top() != '(')
				{
					cout << mystack.top();
					mystack.pop();
				}
				mystack.pop();
			}
			else
			{
				while (!mystack.empty() && precedence(mystack.top())>=precedence(exp[i]))
				{
					cout << mystack.top();
					mystack.pop();
				}
				mystack.push(exp[i]);
			}
		}
		i++;
	}
	while (!mystack.empty())
	{
		cout << mystack.top();
		mystack.pop();
	}
	cout << "\n";
}

int main()
{
	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);
	return 0;
}
