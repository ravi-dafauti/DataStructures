#include<iostream>
using namespace std;
template <typename T>
class Stack
{
	int sTop;
	int count;
	T *arr;
public:
	Stack();
	void push(T);
	T pop();
	T top();
	int size();
};

template <typename T>
Stack<T>::Stack()
{
	sTop = -1;
	count = 1;
	arr = (T *)malloc(sizeof(T));
}
template <typename T>
void Stack<T>::push(T data)
{
	
	if (count == sTop + 1)
	{
		count = count * 2;
		arr = (T *)realloc(arr, sizeof(T)*count);
	}
	sTop++;
	arr[sTop] = data;
}
template <typename T>
T Stack<T>::pop()
{
	if (sTop == -1)
	{
		cout << "stack empty!!\n";
		exception e1;
		throw e1;
	}
	T data = arr[sTop];
	sTop--;
	return data;
}
template <typename T>
int Stack<T>::size()
{
	return sTop + 1;
}
template <typename T>
T Stack<T>::top()
{
	if (sTop == -1)
	{
		cout << "stack empty!!\n";
		exception e1;
		throw e1;
	}
	return arr[sTop];
}
int main()
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.top();
	s.pop();
	cout << s.size();
	cout << s.top();
	s.pop();
	cout << s.top();
	return 0;
}