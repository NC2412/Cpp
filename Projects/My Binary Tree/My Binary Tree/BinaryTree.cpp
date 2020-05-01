#include <iostream>
#include "BinaryTree.h"
#include "Queue.h"

using namespace std;

BinaryTree::BinaryTree() {
	m_pHead = NULL;
}

BinaryTree::~BinaryTree() {
	deleteTree(m_pHead);
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

	
	Node* pDelNode = m_pHead;	// delete node for placeholding the node to be deleted
	Node* pDelPrev = NULL;		// delete previous node for placeholding the node to assign a new value
	Node* pCur = m_pHead;		// pCur and pPrev for holding the place of the new node to replace the deleted node.
	Node* pPrev = NULL;

	if (NULL == pDelNode || NULL == pCur)
		return ecRetCode;

	if (pDelNode->value == delValue) {
		// Head Case
		setToSuccessor(pDelNode, pCur, pPrev); // pCur = successor, pPrev = Node->pLeft = pCur
		deleteGivenNode(pDelNode, pDelPrev, pCur, pPrev);
		m_pHead = pCur;
		return ecRetCode;
	}

	while (NULL != pDelNode) {
		if (delValue == pDelNode->value) {
			if (NULL != pDelNode->pLeft && NULL != pDelNode->pRight) {
				// Two child case
				setToSuccessor(pDelNode, pCur, pPrev); // pCur = successor, pPrev = Node-> pCur
				deleteGivenNode(pDelNode, pDelPrev, pCur, pPrev);
				return ecRetCode;
			}
			else if (NULL != pDelNode->pLeft && NULL == pDelNode->pRight) {
				// Only left child case
				setToPredecessor(pDelNode, pCur, pPrev); // pCur = predecessor, pPrev = Node->pRight = pCur
				deleteGivenNode(pDelNode, pDelPrev, pCur, pPrev);
				return ecRetCode;
			}
			else if (NULL == pDelNode->pLeft && NULL != pDelNode->pRight) {
				// Only right child case
				setToSuccessor(pDelNode, pCur, pPrev);
				deleteGivenNode(pDelNode, pDelPrev, pCur, pPrev);
				return ecRetCode;
			}
			else {
				// Leaf node case
				deleteGivenNode(pDelNode, pDelPrev, pCur, pPrev);
				return ecRetCode;
			}
		}

		pDelPrev = pDelNode;
		if (delValue < pDelNode->value)
			pDelNode = pDelNode->pLeft;
		else
			pDelNode = pDelNode->pRight;
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
			printLevelOrder();
			break;
		default:
			ecRetCode = ErrorCodes::FAILURE;
			return ecRetCode;
	}
	
	return ecRetCode;
}

//-----------------------------------------------------------------
//
// Private Helper Methods
//
//-----------------------------------------------------------------

ErrorCodes BinaryTree::setToPredecessor(Node* rootNode, Node*& pCur, Node*& pPrev)
{
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	if (NULL == rootNode->pLeft)
		return ecRetCode;
	else { 
		pCur = rootNode->pLeft; 
		pPrev = rootNode; 
	}

	while (NULL != pCur->pRight) {
		pPrev = pCur;
		pCur = pCur->pRight;
	}

	return ecRetCode;
}

ErrorCodes BinaryTree::setToSuccessor(Node* rootNode, Node*& pCur, Node*& pPrev)
{
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	if (NULL == rootNode->pRight)
		return ecRetCode;
	else {
		pPrev = rootNode;
		pCur = rootNode->pRight;
	}

	while (NULL != pCur->pLeft) {
		pPrev = pCur;
		pCur = pCur->pLeft;
	}

	return ecRetCode;
}

ErrorCodes BinaryTree::deleteGivenNode(Node*& pDelNode, Node*& pDelPrev, Node*& pCur, Node*& pPrev) {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	if (NULL != pDelNode->pLeft || NULL != pDelNode->pRight) {
		if (NULL != pPrev && pPrev != pDelNode) {
			if (pPrev->pLeft == pCur)
				pPrev->pLeft = pCur->pRight;
			else
				pPrev->pRight = pCur->pLeft;
		}

		if (NULL != pDelPrev && pCur != m_pHead) {
			if (pDelPrev->pLeft == pDelNode)
				pDelPrev->pLeft = pCur;
			else
				pDelPrev->pRight = pCur;
		}

		if (pDelNode->pRight != pCur)
			pCur->pRight = pDelNode->pRight;
		if (pDelNode->pLeft != pCur)
			pCur->pLeft = pDelNode->pLeft;
	}
	else {
		if (pDelPrev->pLeft == pDelNode)
			pDelPrev->pLeft = NULL;
		if (pDelPrev->pRight == pDelNode)
			pDelPrev->pRight = NULL;
	}

	delete pDelNode;

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

//
// printLevelOrder is an iterative method to print the tree in level order.
//
ErrorCodes BinaryTree::printLevelOrder() {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	if (NULL == m_pHead)
		return ecRetCode;

	Queue queue;
	queue.enqueue(m_pHead->value);

	int value = 0;
	while (true) {
		value = queue.dequeue();

		if (value == INT_MIN)
			break;
		else
			cout << value << ", " << flush;

		// Navigating list until pNode->value == value
		Node* pNode = m_pHead;
		while (value != pNode->value) {
			if (value < pNode->value)
				pNode = pNode->pLeft;
			else
				pNode = pNode->pRight;
		}

		if (NULL != pNode && NULL != pNode->pLeft)
			queue.enqueue(pNode->pLeft->value);

		if (NULL != pNode && NULL != pNode->pRight)
			queue.enqueue(pNode->pRight->value);
	}

	return ecRetCode;
}

//
// deleteList will take a node as a parameter
// deleteList is a recursive method using post-order to delete the nodes, so we don't have to do any rebalancing.
ErrorCodes BinaryTree::deleteTree(Node* pNode) {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	if (NULL == pNode)
		return ecRetCode;

	if (pNode->pLeft)
		deleteTree(pNode->pLeft);

	if (pNode->pRight)
		deleteTree(pNode->pRight);

	delete pNode;

	return ecRetCode;
}