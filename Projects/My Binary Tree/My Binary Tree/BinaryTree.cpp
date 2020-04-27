#include <iostream>
#include "BinaryTree.h"
using namespace std;

BinaryTree::BinaryTree() {
	m_pHead = NULL;
}

BinaryTree::~BinaryTree() {
	//deleteList();
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

	if (NULL == pCur)
		return ecRetCode;

	while (pCur) {
		if (pCur->value == delValue) {
			break;
		}
		
		if (delValue < pCur->value)
			pCur = pCur->pLeft;
		else
			pCur = pCur->pRight;
	}

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

	return ecRetCode;
}