#include <iostream>
#include "LinkedList.h"
#include "Util.h"
using namespace std;

//--------------------------------------------------------------
//
// Public methods
//
//

LinkedList::LinkedList() {
	m_pHead = NULL;
	m_pTail = NULL;
	m_fisSorted = false;
}

LinkedList::LinkedList(bool isSorted) {
	m_pHead = NULL;
	m_pTail = NULL;
	m_fisSorted = isSorted;
}

LinkedList::~LinkedList() {
	deleteList();
}

ErrorCodes LinkedList::insertNode(int value) {
	if (true == m_fisSorted)
		return insertSorted(value);
	else
		return addToEnd(value);
}

ErrorCodes LinkedList::deleteNode(int value) {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;
	Node* pCur = m_pHead;
	Node* pPrev = NULL;

	// Make sure there is actually something to delete.
	if (NULL == m_pHead) {
		cout << "No list to delete." << endl;
		return ecRetCode;
	}

	while (NULL != pCur) {
		if (pCur->value == value) {
			if (NULL == pPrev) {
				// Remove the head of the list.
				m_pHead = m_pHead->pNext;
			} 
			else {
				// Remove a node in the list.
				pPrev->pNext = pCur->pNext;
			}

			delete pCur;
			pCur = pPrev;

			if (NULL == pPrev) {
				pCur = m_pHead;
				continue;
			}
		}

		pPrev = pCur;
		pCur = pCur->pNext;
	}

	return ecRetCode;
}

ErrorCodes LinkedList::deleteIndex(unsigned int removeIndex) {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;
	Node* pCur = m_pHead;
	Node* pPrev = NULL;

	for (unsigned int i = 0; i < removeIndex; i++) {
		pPrev = pCur;

		if (pCur->pNext)
			pCur = pCur->pNext;
		else {
			ecRetCode = ErrorCodes::FAILURE;
			return ecRetCode;
		}
	}

	if (pPrev)
		pPrev->pNext = pCur->pNext;

	delete pCur;

	return ecRetCode;
}

ErrorCodes LinkedList::removeDuplicates() {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	Node* pCur = m_pHead;
	Node* pNext = pCur->pNext;
	
	if (NULL == pNext)
		return ecRetCode;

	while (NULL != pNext) {
		if (pCur->value == pNext->value) {
			pCur->pNext = pNext->pNext;
			pNext->pNext = NULL;
			delete pNext;
			pNext = pCur->pNext;
			continue;
		}

		pCur = pCur->pNext;
		pNext = pNext->pNext;
	}

	return ecRetCode;
}

ErrorCodes LinkedList::sortList() {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	if (m_fisSorted == true)
		// Already sorted
		return ecRetCode;
	else if (NULL == m_pHead->pNext)
		// Single node?
		return ecRetCode;
	else
		mergeSort(m_pHead);

	return ecRetCode;
}

ErrorCodes LinkedList::mergeLists(Node* other) {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	if (m_pHead)
		merge(m_pHead, other);
	else {
		ecRetCode = ErrorCodes::FAILURE;
	}

	return ecRetCode;
}

ErrorCodes LinkedList::reverseList() {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;
	Node* pPrev = NULL;
	Node* pCur = m_pHead;
	Node* pNext = pCur->pNext;

	if (NULL == pCur)
		return ecRetCode;

	while (NULL != pNext) {
		pCur->pNext = pPrev;
		pPrev = pCur;
		pCur = pNext;
		pNext = pNext->pNext;
	}

	pCur->pNext = pPrev;
	m_pHead = pCur;

	return ecRetCode;
}

bool LinkedList::hasCycle() {
	// I needed a hint(s) for this one :/
	Node* pBack = m_pHead;
	Node* pFront = m_pHead->pNext;
	int iBack = 2;
	int cur = 1;

	while (NULL != pFront) {

		if (pFront == pBack)
			return true;

		if (cur == iBack) {
			pBack = pBack->pNext;
			cur = 1;
		}
	
		pFront = pFront->pNext;
		cur++;
	}

	return false;
}

int LinkedList::nFromTail(int nthfromtail)
{
	Node* pFront = m_pHead->pNext;
	Node* pBack = m_pHead;

	for (int i = 0; i < nthfromtail; i++) {
		if (NULL == pFront->pNext)
			return 0;
		else
			pFront = pFront->pNext;
	}

	while (NULL != pFront) {
		pFront = pFront->pNext;
		pBack = pBack->pNext;
	}
	
	return pBack->value;
}

ErrorCodes LinkedList::printList() {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;
	Node* pIterNode = m_pHead;

	while (NULL != pIterNode) {
		cout << pIterNode->value << ", " << flush;

		if (NULL == pIterNode->pNext) {
			goto Exit;
		}
		
		pIterNode = pIterNode->pNext;
	}

Exit:
	cout << endl;
	return ecRetCode;
}

ErrorCodes LinkedList::deleteList() {
	ErrorCodes ecRetCodes = ErrorCodes::SUCCESS;
	
	// Check to see if there is anything to delete.
	if (NULL == m_pHead) {
		ecRetCodes = ErrorCodes::FAILURE;
		return ecRetCodes;
	}

	while (NULL != m_pHead) {
		Node* delNode = m_pHead;
		m_pHead = m_pHead->pNext;
		delete delNode;
	}
	return ecRetCodes;
}

//-----------------------------------------------------------------------
//
// Private methods
//
//

ErrorCodes LinkedList::insertSorted(int value) {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;
	Node* pCur = m_pHead;
	Node* newNode = new Node;
	newNode->value = value;

	if (NULL == pCur) {
		m_pHead = newNode;
		m_pTail = m_pHead;
	}

	while (NULL != pCur) {
		if (value <= pCur->value) {
			// Check if value is less than the head value.
			m_pHead = newNode;
			m_pHead->pNext = pCur;
			return ecRetCode;
		}
		else if (pCur->value < value && ((NULL == pCur->pNext) || (value <= pCur->pNext->value))) {
			// Check if the value is greater than pCur's and less than or equal to the next value. Or if pCur is the tail.
			// The NULL check must be first as not to accedentally point to NULL memory.
			newNode->pNext = pCur->pNext;
			pCur->pNext = newNode;
			if (NULL == newNode->pNext)
				m_pTail = newNode;
			return ecRetCode;
		}

		pCur = pCur->pNext;
	}

	return ecRetCode;
}

ErrorCodes LinkedList::addToEnd(int value) {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;
	Node* newNode = new Node;
	newNode->value = value;

	if (NULL == m_pHead) {
		m_pHead = newNode;
		m_pTail = m_pHead;
	}
	else {
		m_pTail->pNext = newNode;
		m_pTail = newNode;
	}

	return ecRetCode;
}

LinkedList::Node* LinkedList::mergeSort(Node* pListHead) {
	if ((NULL == pListHead) || (NULL == pListHead->pNext))
		return pListHead;

	int m = 0;
	Node* pCur = pListHead;
	Node* pListL = pListHead;
	Node* pListR = new Node;
	Node* pPrev = NULL;

	while (NULL != pCur) {
		m++;
		pCur = pCur->pNext;
	}

	m /= 2;
	pCur = pListHead;
	
	for (int i = 0; i < m; i++) {
		pPrev = pCur;
		pCur = pCur->pNext;
	}

	pListR = pCur;
	pPrev->pNext = NULL;

	pListL = mergeSort(pListL);
	pListR = mergeSort(pListR);

	m_pHead = merge(pListL, pListR);

	return m_pHead;
}

LinkedList::Node* LinkedList::merge(Node* pL, Node* pR) {
	if (NULL == pL)
		return pR;
	else if (NULL == pR)
		return pL;

	Node* pNewList = (pL->value <= pR->value) ? pL : pR;
	if (pL == pNewList)
		pL = pL->pNext;
	else
		pR = pR->pNext;
	Node* pNewEnd = pNewList;

	while ((NULL != pL) && (NULL != pR)) {
		if (pL->value <= pR->value) {
			pNewEnd->pNext = pL;
			pL = pL->pNext;
		}
		else {
			pNewEnd->pNext = pR;
			pR = pR->pNext;
		}

		pNewEnd = pNewEnd->pNext;
	}

	pNewEnd->pNext = (NULL == pL) ? pR : pL;
	
	return pNewList;
}