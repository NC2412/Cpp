#pragma once

#include "Util.h"
using namespace std;

class Queue
{
public:
	template <class T>
	struct Node {
		T value;
		Node* pNext = NULL;
	};

public:
	// CTOR and DTOR
	Queue();
	~Queue();

	// Operating methods
	template <typename T>
	ErrorCodes enqueue(T value);
	template <typename T>
	T dequeue();

	// Getter methods
	bool isEmpty();

private:
	// Private methods
	ErrorCodes deleteQueue();

private:
	Node<int>* m_pHead;
	Node<int>* m_pTail;
};