#include<iostream>
using namespace std;

template<typename T>
class Queue
{
	int mfront;
	int mrear;
	T *arr;
	int count;
	void resize();
public:
	Queue();
	int size();
	T dequeue();
	void enQueue(T);
	bool empty();
	T front();
};
template<typename T>
Queue<T>::Queue()
{
	count = 1;
	mfront = mrear = -1;
	arr = (T *)malloc(sizeof(T));
}
template<typename T>
void Queue<T>::resize()
{
	count = count * 2;
	arr = (T *)realloc(arr, sizeof(T)* 2 * count);
	if (mrear < mfront)
	{
		for (int i = 1; i <= mrear + 1; i++)
		{
			arr[count/2 + i - 1] = arr[i - 1];
		}
		mrear = count + mrear;
	}
}
template<typename T>
int Queue<T>::size()
{
	if (empty())
		return 0;
	else
	{
		if ((count + (mrear - mfront + 1)) % count != 0)
			return (count + (mrear - mfront + 1)) % count;
		else
			return count;
	}
	return -1;
}
template<typename T>
T Queue<T>::dequeue()
{
	if (empty())
	{
		cout << "Queue empty!!\n";
		exception e1;
		throw e1;
	}
	T f = arr[mfront];
	if (mfront == mrear)
	{
		mfront = mrear = -1;
	}
	else
	{
		mfront = (count + mfront + 1) % count;
	}
	return f;
}
template<typename T>
void Queue<T>::enQueue(T data)
{
	if (mfront == -1 && mrear == -1)
	{
		mfront++;
		mrear++;
	}
	else
	{
		int r = (count + mrear + 1) % count;
		if (r == mfront)
		{
			resize();
		}
		mrear = (count + mrear + 1) % count;
	}
	arr[mrear] = data;
}
template<typename T>
bool Queue<T>::empty()
{
	if (mfront == -1 && mrear == -1)
		return true;
	return false;
}
template<typename T>
T Queue<T>::front()
{
	if (empty())
	{
		cout << "Queue empty!!\n";
		exception e1;
		throw e1;
	}
	return arr[mfront];
}
int main()
{

	Queue<char> q;
	q.enQueue('a');
	q.enQueue('b');
	q.enQueue('c');
	q.enQueue('d');
	q.enQueue('e');
	q.enQueue('f');
	cout << q.size();
	cout << q.front();
	cout << q.dequeue();
	cout << q.dequeue();
	cout << q.dequeue();
	return 0;
}