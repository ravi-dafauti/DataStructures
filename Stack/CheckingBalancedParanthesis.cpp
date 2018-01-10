#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(char *exp)
{
	stack<char> mystack;
	int i = 0;
	while (exp[i] != '\0')
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
		{
			mystack.push(exp[i]);
		}
		else
		{
			if (mystack.empty())
			{
				return false;
			}
			else
			{
				if ((exp[i] == ')' &&mystack.top() != '(') || (exp[i] == '}' &&mystack.top() != '{') || (exp[i] == ']' &&mystack.top() != '['))
				{
					return false;
				}
				else
				{
					mystack.pop();
				}
			}
		}
		i++;
	}
	if (!mystack.empty())
		return false;

	return true;
}
int main()
{
	char exp[100] = "{()}[]";
	if (isBalanced(exp))
		cout << "balanced\n";
	else
		cout << "not balanced\n";
	return 0;
}