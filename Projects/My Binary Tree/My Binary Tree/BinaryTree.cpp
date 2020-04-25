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
			ecRetCode = ErrorCodes::FAILURE;
			return ecRetCode;
		}
	}

	return ecRetCode;
}

ErrorCodes BinaryTree::printTree() {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;
	Node* pLeft = NULL;
	Node* pRight = NULL;

	return ecRetCode;
}