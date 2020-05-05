#include <iostream>
#include "BinaryTree.h"
#include "Queue.h"

using namespace std;

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

	if (m_fIsAVL == true) {
		// Helper methods for AVL:
		// balanceTree, findHeight, rotateLeft, rotateRight
		m_pHead = balanceTree(m_pHead);
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

//
// METHOD: sortList
//
// - balanceTree will follow a postorder method to compare the heights of the 
// - balanceTree will use helper methods: findHeight, rotateLeft, rotateRight
//
BinaryTree::Node* BinaryTree::balanceTree(Node* pRoot) {

	if (pRoot->pLeft)
		pRoot->pLeft = balanceTree(pRoot->pLeft);

	if (pRoot->pRight)
		pRoot->pRight = balanceTree(pRoot->pRight);

	// Left - right heights of the tree. if iHDiff is -, right side has greater height, if iHDiff is +, left side has greater height.
	int iHDiff = findHeight(pRoot->pLeft) - findHeight(pRoot->pRight);

	// Becuase the difference is greater than one, there MUST be at least two nodes on one of the sides of the tree
	if  (1 < iHDiff && NULL != pRoot->pLeft) {
		// Left Right Case
		if (NULL != pRoot->pLeft->pRight && (pRoot->pLeft->pRight->pLeft || pRoot->pLeft->pRight->pRight)) {
			pRoot->pLeft = rotateLeft(pRoot->pLeft);
			pRoot = rotateRight(pRoot);
		}
		else {
			// Left Left Case
			pRoot = rotateRight(pRoot);
		}
	}
	else if (-1 > iHDiff && NULL != pRoot->pRight) {
		if (NULL != pRoot->pRight->pLeft && (pRoot->pRight->pLeft->pLeft || pRoot->pRight->pLeft->pRight)) {
			// Right Left Case
			pRoot->pRight = rotateRight(pRoot->pRight);
			pRoot = rotateLeft(pRoot);
		}
		else {
			// Right Right Case
			pRoot = rotateLeft(pRoot);
		}
		
	}
	else {
		return pRoot;
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
			cout << "In-order: " << flush;
			printInOrder(m_pHead);
			break;
		case 2:
			cout << "Pre-order: " << flush;
			printPreOrder(m_pHead);
			break;
		case 3:
			cout << "Post-order: " << flush;
			printPostOrder(m_pHead);
			break;
		case 4:
			cout << "Level-order: " << flush;
			printLevelOrder();
			break;
		default:
			ecRetCode = ErrorCodes::FAILURE;
			return ecRetCode;
	}
	
	return ecRetCode;
}

bool BinaryTree::hasValue(int value) {
	Node* pCur = m_pHead;

	while (NULL != pCur) {
		if (pCur->value = value)
			return true;
		else if (value < pCur->value)
			pCur = pCur->pLeft;
		else
			pCur = pCur->pRight;
	}

	return false;
}

//-----------------------------------------------------------------
//
// Private Helper Methods
//
//-----------------------------------------------------------------

ErrorCodes BinaryTree::setToPredecessor(Node* rootNode, Node* pCur, Node* pPrev)
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

ErrorCodes BinaryTree::setToSuccessor(Node* rootNode, Node* pCur, Node* pPrev)
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

ErrorCodes BinaryTree::deleteGivenNode(Node* pDelNode, Node* pDelPrev, Node* pCur, Node* pPrev) {
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

int BinaryTree::findHeight(Node* pNode) {
	if (NULL == pNode)
		return 0; 

	if (NULL == pNode->pLeft && NULL == pNode->pRight) {
		return 1;
	}
	else if (pNode->pLeft && pNode->pRight) {
		int iLHeight = ( findHeight(pNode->pLeft) + 1 );
		int iRHeight = ( findHeight(pNode->pRight) + 1 );
		return (iLHeight > iRHeight) ? iLHeight : iRHeight;
	}
	else if (pNode->pLeft && NULL == pNode->pRight)
		return ( findHeight(pNode->pLeft) + 1 );
	else
		return ( findHeight(pNode->pRight) + 1 );
}

BinaryTree::Node* BinaryTree::rotateLeft(Node* pCur) {
	Node* pNext = pCur->pRight;
	pCur->pRight = pNext->pLeft;
	pNext->pLeft = pCur;
	return pNext;
}

BinaryTree::Node* BinaryTree::rotateRight(Node* pCur) {
	Node* pNext = pCur->pLeft;
	pCur->pLeft = pNext->pRight;
	pNext->pRight = pCur;
	return pNext;
}

//-----------------------------------------------------------------
//
// Mutator Methods
//
//-----------------------------------------------------------------
void BinaryTree::toggleAVL() {
	cout << findHeight(m_pHead) << endl;

	if (m_fIsAVL == false) {
		m_fIsAVL = true;

		Node* newHead = balanceTree(m_pHead);
		do {
			m_pHead = newHead;
			newHead = balanceTree(m_pHead);
		} while (m_pHead != newHead);
	}
	else 
		m_fIsAVL = false;
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

	Node* pCur;
	Queue<Node*> q;
	q.enqueue(m_pHead);

	while (!q.isEmpty()) {
		try {
			pCur = q.dequeue();
			cout << pCur->value << ", " << flush;
		}
		catch (int e) {
			cout << "Exception caught: " << e << ", empty queue." << endl;
			return ecRetCode;
		}

		if (pCur->pLeft)
			q.enqueue(pCur->pLeft);
		if (pCur->pRight)
			q.enqueue(pCur->pRight);
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