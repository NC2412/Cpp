#pragma once

#include "Util.h"
using namespace std;

class Queue
{
public:
	struct Node {
		int value = 0;
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