#pragma once

#include "Util.h"

class Queue
{
public:
	struct Node {
		int value;
		Node* pNext = NULL;
	};

public:
	// CTOR and DTOR
	Queue();
	~Queue();

	// Operating methods
	ErrorCodes enqueue(int value);
	int dequeue();

private:
	// Private methods
	ErrorCodes deleteQueue();

private:
	Node* m_pHead;
	Node* m_pTail;
};