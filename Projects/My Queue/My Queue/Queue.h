#pragma once

#include "Util.h"
using namespace std;

template <class T>
class Queue
{
public:
	struct Node {
		T value;
		Node* pNext = NULL;
	};

public:
	// CTOR and DTOR
	Queue();
	~Queue();

	// Operating methods
	ErrorCodes enqueue(T value);
	T dequeue();

	// Getter methods
	bool isEmpty();

private:
	// Private methods
	ErrorCodes deleteQueue();

private:
	Node* m_pHead;
	Node* m_pTail;
};