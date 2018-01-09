//evaluate Infix Expression in one pass.
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isOperator(char a)
{
	if (a == '+' || a == '-' || a == '/' || a == '*')
	{
		return true;
	}
	return false;
}
bool isParanthesis(char a)
{
	if (a == '(' || a == ')')
		return true;
	return false;
}
int evalUtil(int b, int a, char oper)
{
	switch (oper)
	{
	case '+':
		return b + a;
	case'-':
		return b - a;
	case '*':
		return b*a;
	case '/':
		if (a == 0)
		{
			cout << "error\n";
			exception e1;
			throw e1;
		}
		else
			return b / a;
	}
	return -1;
}

int precedence(char a)
{
	switch (a)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	}
	return 0;
}
int evaluate(string exp)
{
	stack<int> operand; //operand stack
	stack<char> opt; //operator stack
	int i = 0;
	while (i<exp.length())
	{
		if (!isOperator(exp[i]) && !isParanthesis(exp[i]))
		{
			int c = 0;
			while (i + c <exp.length() && exp[i + c] != ' ')
			{
				c++;
			}
			string str = exp.substr(i, c);
			try{
				int num = stoi(str);
				operand.push(num);
			}
				catch (std::exception const &e) {
				// This could not be parsed into a number so an exception is thrown.
				// atoi() would return 0, which is less helpful if it could be a valid value.
			}	
				i = i + c + 1;
		}
		else
		{
			if (exp[i] == '(')
				opt.push(exp[i]);
			else if (exp[i] == ')')
			{
				while (opt.top() != '(')
				{
					char oper = opt.top();
					opt.pop();
					int a = operand.top();
					operand.pop();
					int b = operand.top();
					operand.pop();
					operand.push(evalUtil(b, a, oper));
				}
				opt.pop();
			}
			else
			{
				while (!opt.empty() && precedence(opt.top()) >= precedence(exp[i]))
				{
					char oper = opt.top();
					opt.pop();
					int a = operand.top();
					operand.pop();
					int b = operand.top();
					operand.pop();
					operand.push(evalUtil(b, a, oper));
				}
				opt.push(exp[i]);
			}
			i = i + 2;
		}
	}
	while (!opt.empty())
	{
		char oper = opt.top();
		opt.pop();
		int a = operand.top();
		operand.pop();
		int b = operand.top();
		operand.pop();
		operand.push(evalUtil(b, a, oper));
	}
	return operand.top();
}
int main()
{
	string exp = "100 * ( 2 + 12 ) / 14";
	cout << evaluate(exp);
}

