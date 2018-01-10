#include<iostream>
#include<stack>
using namespace std;

int maxAreaUnderHisto(int histo[], int n)
{
	stack<int> mystack;
	int maxArea = -1;
	int currArea;
	int i;
	int b;
	int h;
	for (i = 0; i < n;)
	{
		if (mystack.empty() || histo[i] >= histo[mystack.top()])
			mystack.push(i++);
		else
		{
			while (!mystack.empty() && histo[i] < histo[mystack.top()])
			{
				h = histo[mystack.top()];
				mystack.pop();
				if (mystack.empty())
					b = i;
				else
					b = i - mystack.top() - 1;
				currArea = b*h;
				if (currArea>maxArea)
					maxArea = currArea;
			}
		}
	}
	while (!mystack.empty())
	{
		h = histo[mystack.top()];
		mystack.pop();
		if (mystack.empty())
			b = i;
		else
			b = i - mystack.top() - 1;
		currArea = b*h;
		if (currArea>maxArea)
			maxArea = currArea;
	}
	return maxArea;
}
int main()
{
	int histroGram[] = { 6, 2, 5, 4, 5, 1, 6 };
	int size = sizeof(histroGram) / sizeof(histroGram[0]);
	cout << "maximum area is : " << maxAreaUnderHisto(histroGram, size);
	return 0;
}

