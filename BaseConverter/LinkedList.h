/*
UML Diagram of class LinkedList
_________________________________________________________________
|							LinkedList							|
|_______________________________________________________________|
| - headPtr: Node<T>*											|
| - tailPtr: Node<T>*											|
| - size_: size_t												|
|_______________________________________________________________|
| + LinkedList()												|
| + ~LinkedList()												|
| + addToHead(T): bool											|
| + addToTail(T): bool											|
| + removeFromHead(): T											|
| + isEmpty(): bool												|
| + getHeadData(): bool											|
| + getSize(): size_t											|
| + deleteAllNodes(): void										|
|_______________________________________________________________|
*/
//#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

using namespace std;

template<typename T>
class LinkedList
{
public:
	LinkedList():headPtr(nullptr), tailPtr(nullptr), size_(0) {} //constructor
	~LinkedList() { deleteAllNodes(); } //destructor
	bool addToHead(T data = T()); //stack only
	bool addToTail(T data = T()); //queue only
	T removeFromHead(); //queue and stack
	bool isEmpty(); //returns true is headPtr is NULL
	T getHeadData(); //returns the data_ in the Node pointed to by headPtr
	size_t getSize() { return size_; }
	//T getTailData();
	void deleteAllNodes(); //deletes all Nodes beginning with the head

private:
	Node<T>* headPtr;
	Node<T>* tailPtr;
	size_t size_;
};

#include "LinkedList.h"

template<typename T>
bool LinkedList<T>::addToHead(T data)
{
	Node<T>* tempPtr = new Node<T>();
	tempPtr->data_ = data;
	tempPtr->next_ = headPtr;
	headPtr = tempPtr;
	if (!tailPtr) //if tailPtr is NULL
	{
		tailPtr = headPtr;
	}
	size_++;
	return true; //return false if memory fails to allocate
}
template<typename T>
bool LinkedList<T>::addToTail(T data)
{
	Node<T>* tempPtr = new Node<T>();
	tempPtr->data_ = data;
	if (tailPtr) //if tailPtr is not NULL
	{
		tailPtr->next_ = tempPtr;
	}
	tailPtr = tempPtr;
	if (!headPtr) //if headPtr is NULL
	{
		headPtr = tailPtr;
	}
	size_++;
	return true; //return false if memory fails to allocate
}
template<typename T>
T LinkedList<T>::removeFromHead()
{
	T data = T();
	if (!headPtr) //if headPtr is NULL
	{
		cerr << "The Linked List is empty.\n";
		return data;
	}
	data = headPtr->data_;
	Node<T>* tempPtr = headPtr;
	headPtr = headPtr->next_;
	if (tempPtr == tailPtr)
	{
		tailPtr = NULL;
	}
	delete tempPtr;
	tempPtr = nullptr;
	size_--;
	return data;
}
template<typename T>
bool LinkedList<T>::isEmpty()
{
	if (headPtr)
	{
		return false;
	}
	return true;
}
template<typename T>
T LinkedList<T>::getHeadData()
{
	if (headPtr)
	{
		return headPtr->data_;
	}
	return T();
}
/*template<typename T>
T LinkedList<T>::getTailData()
{
	return tailPtr->data_;
}*/
template<typename T>
void LinkedList<T>::deleteAllNodes()
{
	Node<T>* tempPtr = headPtr;
	while (tempPtr)
	{
		headPtr = tempPtr->next_;
		delete tempPtr;
		tempPtr = headPtr;
	}
	tailPtr = NULL;
	size_ = 0;
}
#endif