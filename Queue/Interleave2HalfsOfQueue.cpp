//input : 1 2 3 4 5 6
//output : 1 4 2 5 3 6

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void interleaveQueueHalfs(queue<int> &q)
{
	stack<int> s;
	int n = q.size() / 2;
	for (int i = 0; i < n; i++)
	{
		s.push(q.front());
		q.pop();
	}
	for (int i = 0; i < n; i++)
	{
		q.push(s.top());
		s.pop();
	}
	for (int i = 0; i < n; i++)
	{
		q.push(q.front());
		q.pop();
	}
	for (int i = 0; i < n; i++)
	{
		s.push(q.front());
		q.pop();
	}
	for (int i = 0; i < n; i++)
	{
		q.push(s.top());
		s.pop();
		q.push(q.front());
		q.pop();
	}
}
int main()

{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);

	interleaveQueueHalfs(q);

	cout << q.front();
	q.pop();
	cout << q.front();
	q.pop();
	cout << q.front();
	q.pop();
	cout << q.front();
	q.pop();
	cout << q.front();
	q.pop();
	cout << q.front();
	q.pop();
    return 0;
}

