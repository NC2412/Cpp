#include <limits>
#include "Queue.h"

Queue::Queue() {
	m_pHead = NULL;
	m_pTail = NULL;
}

Queue::~Queue() {
	deleteQueue();
}

ErrorCodes Queue::enqueue(int value)
{
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;
	Node* newNode = new Node;
	newNode->value = value;

	if (NULL == m_pHead) {
		m_pHead = newNode;
		m_pTail = m_pHead;
	}
	else {
		m_pTail->pNext = newNode;
		m_pTail = m_pTail->pNext;
	}

	return ecRetCode;
}

//
// TODO 
// 
// How will i return a NULL value?
//
int Queue::dequeue()
{
	int value = m_pHead->value;
	Node* temp = m_pHead;

	if (NULL == m_pHead) {
		return INT_MIN;
	}

	m_pHead = m_pHead->pNext;
	temp->pNext = NULL;
	delete temp;

	return value;
}

ErrorCodes Queue::deleteQueue() {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	if (NULL == m_pHead)
		return ecRetCode;

	while (NULL != m_pHead) {
		Node* tempNode = m_pHead;
		m_pHead = m_pHead->pNext;
		tempNode->pNext = NULL;
		delete tempNode;
	}

	return ecRetCode;
}