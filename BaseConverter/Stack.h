/*
UML Diagram of class Stack
_________________________________________________________________
|							Stack								|
|_______________________________________________________________|
| - list: LinkedList<T>											|
|_______________________________________________________________|
| + Stack()														|
| + pop(): T													|
| + push(T): bool												|
| + top(): T													|
| + size(): size_t												|
|_______________________________________________________________|
*/
//#pragma once
#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"

using namespace std;

template<typename T>
class Stack
{
public:
	Stack() {}
	T pop(); //removes an element from the top of stack and returns the element
	bool push(T data = T()); //returns true if data was successfully added to the top of stack
	T top(); //returns the element at the top of the stack without removing it
	size_t size() { return list.getSize(); }


private:
	LinkedList<T> list;
};

#include "Stack.h"

template<typename T>
T Stack<T>::pop()
{
	if (!list.isEmpty())
	{
		return list.removeFromHead();
	}
	return T();
}
template<typename T>
bool Stack<T>::push(T data)
{
	if (list.addToHead(data))
	{
		return true;
	}
	return false;
}
template<typename T>
T Stack<T>::top()
{
	if (!list.isEmpty())
	{
		return list.getHeadData();
	}
	return T();
}
#endif