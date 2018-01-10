/* input : careermonk
   output : camonk*/

#include<iostream>
#include<stack>
using namespace std;

void removeAdjDuplicates(char str[])
{
	//using inplace stack to remove duplicates.
	int top = -1;
	int i = 0;
	while (str[i] != '\0')
	{
		if (top == -1 || str[top] != str[i])
			str[++top] = str[i++];
		else
		{
			while (str[i] == str[top])
			{
				i++;
			}
			top--;
		}
	}
	str[++top] = '\0';
}
int main()
{
	char str[] = "careermonk";
	cout << str << "\n";
	removeAdjDuplicates(str);
	cout << str;
	return 0;
}