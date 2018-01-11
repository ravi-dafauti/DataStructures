#include<iostream>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q)
{
	if (q.empty())
		return;
	int data = q.front();
	q.pop();
	reverseQueue(q);
	q.push(data);
}
int main()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	reverseQueue(q);
	cout << q.front();
	q.pop();
	cout << q.front();
	q.pop();
	cout << q.front();
	q.pop();
    return 0;
}

