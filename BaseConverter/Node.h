/*
UML Diagram of struct Node
_________________________________________________________________
|							Node								|
|_______________________________________________________________|
| - data_: T													|
| - Node(T, Node*)												|
| - next: Node*													|
|_______________________________________________________________|
| + Node()														|
|_______________________________________________________________|
*/
//#pragma once
#ifndef NODE_H
#define NODE_H
#include <string>
#include <iostream>

using namespace std;

template<typename T>
struct Node
{
	T data_;
	Node* next_;
	Node(T data = T(), Node* ptr = nullptr) :data_(data), next_(ptr) {}
	~Node() {}
};
#endif