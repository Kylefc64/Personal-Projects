/*
UML Diagram of class Queue
_________________________________________________________________
|							Queue								|
|_______________________________________________________________|
| - list: LinkedList<T>											|
|_______________________________________________________________|
| + Queue()														|
| + enqueue(T): bool											|
| + dequeue(): T												|
| + front(): T													|
| + size(): size_t												|
|_______________________________________________________________|
*/
//#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"

using namespace std;

template<typename T>
class Queue
{
public:
	Queue() {}
	bool enqueue(T data = T()); //returns true if data was successfully added to the end of queue
	T dequeue(); //removes the next item in the queue and returns it
	T front(); //returns the next item in the queue without removing it
	//T back(); //returns the last item in the queue without removing it
	size_t size() { return list.getSize(); }


private:
	LinkedList<T> list;
};

#include "Queue.h"

template<typename T>
bool Queue<T>::enqueue(T data)
{
	if (list.addToTail(data))
	{
		return true;
	}
	return false;
}
template<typename T>
T Queue<T>::dequeue()
{
	if (!list.isEmpty())
	{
		return list.removeFromHead();
	}
	return T();
}
template<typename T>
T Queue<T>::front()
{
	if (!list.isEmpty())
	{
		return list.getHeadData();
	}
	return T();
}

#endif