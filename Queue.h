#pragma once
#include <iostream>

const int capacity = 100;

using namespace std;
template <class T>
class Queue
{
private:
	int back;
	T* container = new T[capacity];
public:
	Queue();
	bool enqueue(T);
	T dequeue();
	bool empty();
	void print();
};
template <class T>
Queue<T>::Queue()
 {
	back = -1;
}
template <class T>
bool Queue<T>::enqueue(T value)
{
	if (back >= (capacity - 1))
		return false;
	else
	{
		back++;
		container[back] = value;
		return true;
	}
}
template <class T>
T Queue<T>::dequeue()
{
	if (back < 0)
		return T();
	else
	{
		T value = container[0];
		for (int i = 1; i <= back; i++)
			container[i - 1] = container[i];
		back--;
		return value;
	}
}
template <class T>
bool Queue<T>::empty()
{
	return (back < 0);
}
template <class T>
void Queue<T>::print()
{
	for (int i = 0; i <= back; i++)
		cout << container[i] << " ";
	cout << endl;
}