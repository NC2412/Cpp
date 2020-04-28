#include <iostream>
#include "BinaryTree.h"
using namespace std;

BinaryTree::BinaryTree() {
	m_pHead = NULL;
}

BinaryTree::~BinaryTree() {
	deleteList(m_pHead);
}

ErrorCodes BinaryTree::insertNode(int value) {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;
	Node* pCur = NULL;
	Node* newNode = new Node;
	newNode->value = value;

	if (NULL == m_pHead) {
		// Head case.
		m_pHead = newNode;
		return ecRetCode;
	}

	pCur = m_pHead;
	while (NULL != pCur) {
		if (value < pCur->value) {
			if (NULL == pCur->pLeft) {
				pCur->pLeft = newNode;
				break;
			} 
			else
				pCur = pCur->pLeft;
		}
		else if (value > pCur->value) {
			if (NULL == pCur->pRight) {
				pCur->pRight = newNode;
				break;
			}
			else
				pCur = pCur->pRight;
		}
		else {
			return ecRetCode;
		}
	}

	return ecRetCode;
}

ErrorCodes BinaryTree::deleteNode(int delValue) {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;
	Node* pCur = m_pHead;
	Node* pPrev = NULL;

	if (NULL == pCur)
		return ecRetCode;

	if (m_pHead->value == delValue) {
		// Do a TON
	}

	while (pCur) {
		if (pCur->value == delValue) {
			if (NULL == pCur->pLeft && NULL == pCur->pRight)
				// Leaf case
				delete pCur;

			if (NULL == pCur->pLeft) {
				// Left child case
				if (pPrev->pLeft == pCur) {
					// pCur is left child
					pPrev->pLeft = pCur->pLeft;
				}
				else {
					// pCur is right child
					pPrev->pRight = pCur->pLeft;
				}
			}
			else if (NULL == pCur->pRight) {
				// Right child case
			}
		}
		
		pPrev = pCur;
		if (delValue < pCur->value)
			pCur = pCur->pLeft;
		else
			pCur = pCur->pRight;
	}

	return ecRetCode;
}

/*
	iPrintType values:
	1 - in-order
	2 - pre-order
	3 - post-order
	4 - level-order
*/
ErrorCodes BinaryTree::printTree(int iPrintType)
{
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	if (NULL == m_pHead)
		return ecRetCode;

	switch (iPrintType) {
		case 1:
			printInOrder(m_pHead);
			break;
		case 2:
			printPreOrder(m_pHead);
			break;
		case 3:
			printPostOrder(m_pHead);
			break;
		case 4:
			printLevelOrder(m_pHead);
			break;
		default:
			ecRetCode = ErrorCodes::FAILURE;
			return ecRetCode;
	}
	

	return ecRetCode;
}

//-----------------------------------------------------------------
//
// Private Methods
//
//-----------------------------------------------------------------

ErrorCodes BinaryTree::printInOrder(Node* pNode)
{
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	if (pNode->pLeft)
		printInOrder(pNode->pLeft);

	cout << pNode->value << ", " << flush;

	if (pNode->pRight)
		printInOrder(pNode->pRight);

	return ecRetCode;
}

ErrorCodes BinaryTree::printPreOrder(Node* pNode) {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;
	
	cout << pNode->value << ", " << flush;
	
	if (pNode->pLeft)
		printPreOrder(pNode->pLeft);

	if (pNode->pRight)
		printPreOrder(pNode->pRight);

	return ecRetCode;
}

ErrorCodes BinaryTree::printPostOrder(Node* pNode) {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;
	
	if (pNode->pLeft)
		printPostOrder(pNode->pLeft);

	if (pNode->pRight)
		printPostOrder(pNode->pRight);
	
	cout << pNode->value << ", " << flush;

	return ecRetCode;
}

ErrorCodes BinaryTree::printLevelOrder(Node* pNode) {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	if (pNode->pNext)
		printLevelOrder(pNode->pNext);

	cout << pNode->value << endl;

	return ecRetCode;
}

//
// deleteList will take a node as a parameter
// deleteList is a recursive method using post-order to delete the nodes, so we don't have to do any rebalancing.
ErrorCodes BinaryTree::deleteList(Node* pNode) {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	if (NULL == pNode)
		return ecRetCode;

	if (pNode->pLeft)
		deleteList(pNode->pLeft);

	if (pNode->pRight)
		deleteList(pNode->pRight);

	delete pNode;

	return ecRetCode;
}