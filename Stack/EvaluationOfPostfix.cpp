/*1) It supports only 4 binary operators ‘+’, ‘*’, ‘-‘ and ‘/’. It can be extended for more operators by adding more switch cases.
  2) The allowed operands are only single digit operands. The program can be extended for multiple digits by adding a separator like space between all elements (operators and operands) of given expression.*/


#include<iostream>
#include<stack>
using namespace std;

int valueOfExp(char *exp)
{
	stack<int> mystack;
	int i = 0;
	int res = 0;
	while (exp[i] != '\0')
	{
		if (exp[i] != '+' && exp[i] != '-' && exp[i] != '/' && exp[i] != '*')
		{
			mystack.push(exp[i] - '0');
		}
		else
		{
			switch (exp[i])
			{
				int a, b, c;
			case '+':
				a = mystack.top();
				mystack.pop();
				b = mystack.top();
				mystack.pop();
				c = b + a;
				mystack.push(c);
				break;
			case '-' :
				a = mystack.top();
				mystack.pop();
				b = mystack.top();
				mystack.pop();
				c = b - a;
				mystack.push(c);
				break;
			case '/':
				a = mystack.top();
				mystack.pop();
				b = mystack.top();
				mystack.pop();
				c = b / a;
				mystack.push(c);
				break;
			case '*':
				a = mystack.top();
				mystack.pop();
				b = mystack.top();
				mystack.pop();
				c = b * a;
				mystack.push(c);
				break;
			}
		}
		i++;
	}
	return mystack.top();
}
int main()
{
	char exp[] = "231*+9-";
	cout << "value of " << exp << " is : " << valueOfExp(exp);
	return 0;
}