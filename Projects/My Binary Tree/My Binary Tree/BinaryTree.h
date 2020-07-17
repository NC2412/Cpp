#pragma once
#include <iostream>
#include "Util.h"
#include "Queue.h"
using namespace std;

template <class T>
class BinaryTree
{
private:
	struct Node {
		T value;

		Node* pLeft = NULL;
		Node* pRight = NULL;
		Node* pNext = NULL;
	};

public:
	// CTORs and DTORs
	BinaryTree<T>() : m_pHead(NULL), m_fIsAVL(false) {};
	BinaryTree<T>(bool avl) : m_pHead(NULL), m_fIsAVL(avl) {};
	~BinaryTree() { deleteTree(m_pHead); }

	// Operating methods
	ErrorCodes  insertNode(T);
	ErrorCodes  deleteNode(T);
	ErrorCodes  printTree(int);
	int			findClosestCommonAncestor(T, T);
	bool		hasValue(T);

	// Mutator methods
	inline void toggleAVL() { if (m_fIsAVL) m_fIsAVL = false; else { m_fIsAVL = true; balanceTree(); } }

	// Getter methods
	inline int getSize() { return countNodes(m_pHead); }

private:
	// Private helper methods
	ErrorCodes	handleNodeDelete(Node*, Node*, Node*);
	int			getHeight(Node*);
	int			getDepth(Node*);
	Node*		rotateLeft(Node*);
	Node*		rotateRight(Node*);
	
	// Private getter methods
	Node*		getPredecessor(Node*);
	Node*		getSuccessor(Node*);
	Node*		getNode(T);

	// Private operating methods
	int			countNodes(Node*);
	ErrorCodes  threadTree();
	ErrorCodes	balanceTree();
	Node*		balanceSubTree(Node*);
	ErrorCodes  printInOrder(Node*);
	ErrorCodes  printPreOrder(Node*);
	ErrorCodes  printPostOrder(Node*);
	ErrorCodes  printLevelOrder();
	ErrorCodes  deleteTree(Node*);

private:
	// Member variables
	Node* m_pHead;
	bool m_fIsAVL;
};



//==============================================================================================
//
//		BINARY TREE IMPLEMENTATION
//
//==============================================================================================

template <class T>
ErrorCodes BinaryTree<T>::insertNode(T value) {
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
		m_pHead = balanceSubTree(m_pHead);
	}

	threadTree();
	return ecRetCode;
}

template <class T>
ErrorCodes BinaryTree<T>::deleteNode(T delValue) {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;
	Node* pDelNode = m_pHead;
	Node* pDelPrev = NULL;
	Node* pReplNode = NULL;

	while (pDelNode->value != delValue) {
		pDelPrev = pDelNode;

		if (delValue < pDelNode->value && pDelNode->pLeft)
			pDelNode = pDelNode->pLeft;
		else if (delValue > pDelNode->value && pDelNode->pRight)
			pDelNode = pDelNode->pRight;
		else
			return ecRetCode;
	}

	if (pDelNode->pLeft && pDelNode->pRight) {
		// TWO CHILD CASE
		pReplNode = getSuccessor(pDelNode);

		if (m_pHead == pDelNode)
			m_pHead = pReplNode;
	}
	else if (NULL == pDelNode->pRight && pDelNode->pLeft) {
		// LEFT CHILD CASE
		pReplNode = getPredecessor(pDelNode);
	}
	else if (NULL == pDelNode->pLeft && pDelNode->pRight) {
		// RIGHT CHILD CASE
		pReplNode = getSuccessor(pDelNode);
	}

	ecRetCode = handleNodeDelete(pDelNode, pDelPrev, pReplNode);

	if (m_fIsAVL == true)
		balanceTree();

	threadTree();
	return ecRetCode;
}

template <class T>
ErrorCodes BinaryTree<T>::balanceTree() {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	Node* newHead = balanceSubTree(m_pHead);
	do {
		m_pHead = newHead;
		newHead = balanceSubTree(m_pHead);
	} while (m_pHead != newHead);

	return ecRetCode;
}

//
// METHOD: balanceSubTree
//
// - balanceSubTree will follow a postorder method to compare the heights of the 
// - balanceSubTree will use helper methods: findHeight, rotateLeft, rotateRight
//
template <class T>
typename BinaryTree<T>::Node*
BinaryTree<T>::balanceSubTree(Node* pRoot) {

	if (pRoot->pLeft)
		pRoot->pLeft = balanceSubTree(pRoot->pLeft);

	if (pRoot->pRight)
		pRoot->pRight = balanceSubTree(pRoot->pRight);

	// Left - right heights of the tree. if iHDiff is -, right side has greater height, if iHDiff is +, left side has greater height.
	int iHDiff = getHeight(pRoot->pLeft) - getHeight(pRoot->pRight);

	// Becuase the difference is greater than one, there MUST be at least two nodes on one of the sides of the tree
	if (1 < iHDiff && NULL != pRoot->pLeft) {
		if (NULL != pRoot->pLeft->pRight && (pRoot->pLeft->pRight->pLeft || pRoot->pLeft->pRight->pRight))
			// Left Right Case
			pRoot->pLeft = rotateLeft(pRoot->pLeft);

		pRoot = rotateRight(pRoot);
	}
	else if (-1 > iHDiff && NULL != pRoot->pRight) {
		if (NULL != pRoot->pRight->pLeft && (pRoot->pRight->pLeft->pLeft || pRoot->pRight->pLeft->pRight))
			// Right Left Case
			pRoot->pRight = rotateRight(pRoot->pRight);

		pRoot = rotateLeft(pRoot);
	}

	return pRoot;
}

template <class T>
ErrorCodes BinaryTree<T>::printTree(int iPrintType)
{
	/*
		iPrintType values:
		1 - in-order
		2 - pre-order
		3 - post-order
		4 - level-order
	*/

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
		cout << "Level-order: " << endl << flush;
		printLevelOrder();
		break;
	default:
		ecRetCode = ErrorCodes::FAILURE;
		return ecRetCode;
	}

	return ecRetCode;
}

template <class T>
int BinaryTree<T>::findClosestCommonAncestor(T val1, T val2)
{
	Node* pCur = m_pHead;
	int commonAncestorVal = -1;

	if (NULL == pCur || NULL == getNode(val1) || NULL == getNode(val2))
		return -1;

	while (NULL != pCur) {
		if (val1 <= pCur->value && pCur->value <= val2)
			commonAncestorVal = pCur->value;
		else if (val1 >= pCur->value && pCur->value >= val2)
			commonAncestorVal = pCur->value;

		if (val1 < pCur->value && pCur->value > val2)
			pCur = pCur->pLeft;
		else if (val1 > pCur->value && pCur->value < val2)
			pCur = pCur->pRight;
		else
			break;
	}

	return commonAncestorVal;
}

template <class T>
bool BinaryTree<T>::hasValue(T value) {
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

//-----------------------------------------------------------------
//
// Private Getter Methods
//
//-----------------------------------------------------------------

// getPredecessor/getSuccessor will break off the wanted node and handle the reconstruction of the subtree.
// Both methods return the needed node.
template <class T>
typename BinaryTree<T>::Node*
BinaryTree<T>::getPredecessor(Node* pRootNode) {
	Node* pCur = pRootNode;
	Node* pPrev = NULL;

	if (NULL == pCur)
		return pCur;

	if (pCur->pLeft) {
		pPrev = pCur;
		pCur = pCur->pLeft;
	}
	else
		return pCur;

	if (NULL == pCur->pRight) {
		pPrev->pLeft = pCur->pLeft;
		return pCur;
	}

	while (NULL != pCur->pRight) {
		pPrev = pCur;
		pCur = pCur->pLeft;
	}

	pPrev->pRight = pCur->pLeft;
	pCur->pLeft = NULL;

	return pCur;
}

template <class T>
typename BinaryTree<T>::Node*
BinaryTree<T>::getSuccessor(Node* pRootNode) {
	Node* pCur = pRootNode;
	Node* pPrev = NULL;

	if (NULL == pCur)
		return pCur;

	if (pCur->pRight) {
		pPrev = pCur;
		pCur = pCur->pRight;
	}
	else
		return pCur;

	if (NULL == pCur->pLeft) {
		pPrev->pRight = pCur->pRight;
		return pCur;
	}

	while (NULL != pCur->pLeft) {
		pPrev = pCur;
		pCur = pCur->pLeft;
	}

	pPrev->pLeft = pCur->pRight;
	pCur->pRight = NULL;

	return pCur;
}

template <class T>
typename BinaryTree<T>::Node*
BinaryTree<T>::getNode(T value) {
	Node* node = m_pHead;

	while (node->value != value) {
		if (value < node->value && node->pLeft)
			node = node->pLeft;
		else if (value > node->value && node->pRight)
			node = node->pRight;
		else
			return NULL;
	}

	return node;
}

/*
	getHeight takes in a node and traversess its subtree to find the height.
*/
template <class T>
int BinaryTree<T>::getHeight(Node* pNode) {
	if (NULL == pNode)
		return 0;

	if (NULL == pNode->pLeft && NULL == pNode->pRight) {
		return 1;
	}
	else if (pNode->pLeft && pNode->pRight) {
		int iLHeight = (getHeight(pNode->pLeft) + 1);
		int iRHeight = (getHeight(pNode->pRight) + 1);
		return (iLHeight >= iRHeight) ? iLHeight : iRHeight;
	}
	else if (pNode->pLeft && NULL == pNode->pRight)
		return (getHeight(pNode->pLeft) + 1);
	else
		return (getHeight(pNode->pRight) + 1);
}

/*
	getDepth returns the depth of the given node from the root node.
*/
template <class T>
int BinaryTree<T>::getDepth(Node* pNode) {
	Node* pCur = m_pHead;
	int depth = 0;

	if (NULL == pCur || NULL == pNode)
		return -1;

	while (NULL != pCur && pCur->value != pNode->value) {
		if ((NULL == pCur->pLeft && pNode->value < pCur->value) || (NULL == pCur->pRight && pNode->value > pCur->value))
			return -1;

		if (pNode->value < pCur->value)
			pCur = pCur->pLeft;
		else
			pCur = pCur->pRight;
	}

	return depth;
}

template <class T>
typename BinaryTree<T>::Node*
BinaryTree<T>::rotateLeft(Node* pCur) {
	Node* pNext = pCur->pRight;
	pCur->pRight = pNext->pLeft;
	pNext->pLeft = pCur;
	return pNext;
}

template <class T>
typename BinaryTree<T>::Node*
BinaryTree<T>::rotateRight(Node* pCur) {
	Node* pNext = pCur->pLeft;
	pCur->pLeft = pNext->pRight;
	pNext->pRight = pCur;
	return pNext;
}

//-----------------------------------------------------------------
//
// Private Operating Methods
//
//-----------------------------------------------------------------
template <class T>
ErrorCodes BinaryTree<T>::handleNodeDelete(Node* pDelNode, Node* pDelPrev, Node* pReplNode) {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;
	if (NULL == pReplNode) {
		if (NULL == pDelNode->pLeft && NULL == pDelNode->pRight) {
			// Leaf delete
			if (pDelPrev->pLeft == pDelNode)
				pDelPrev->pLeft = NULL;
			else
				pDelPrev->pRight = NULL;
		}
	}
	else {
		// Delete anything else
		pReplNode->pLeft = pDelNode->pLeft;
		pReplNode->pRight = pDelNode->pRight;

		pDelNode->pLeft = NULL;
		pDelNode->pRight = NULL;

		if (pDelPrev) {
			if (pDelPrev->pLeft == pDelNode)
				pDelPrev->pLeft = pReplNode;
			else
				pDelPrev->pRight = pReplNode;
		}
	}

	delete pDelNode;

	return ecRetCode;
}

template <class T>
int BinaryTree<T>::countNodes(Node* pNode) {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	int count = 1;

	if (pNode->pLeft)
		count += countNodes(pNode->pLeft);

	if (pNode->pRight)
		count += countNodes(pNode->pRight);

	return count;
}

template <class T>
ErrorCodes BinaryTree<T>::threadTree()
{
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	if (NULL == m_pHead)
		return ecRetCode;

	Node* pCur = NULL;
	Node* pPrev = NULL;
	Node* endLine = NULL;
	Queue<Node*> q;

	q.enqueue(m_pHead);

	while (!q.isEmpty()) {
		pPrev = pCur;

		try {
			pCur = q.dequeue();
		}
		catch (int e) {
			cout << "Exception caught: " << e << ", empty queue." << endl;
			return ecRetCode;
		}

		if (pPrev && pCur)
			pPrev->pNext = pCur;

		if (NULL == pCur)
			endLine = pPrev;
		if (NULL == pPrev && NULL != endLine)
			endLine->pNext = pCur;

		pPrev = pCur;

		if (NULL == pCur) {
			if (!q.isEmpty())
				q.enqueue(pCur);

			continue;
		}

		if (q.isEmpty()) {
			// Creating sentinel
			Node* sentinel = NULL;
			q.enqueue(sentinel);
		}
		if (pCur->pLeft)
			q.enqueue(pCur->pLeft);
		if (pCur->pRight)
			q.enqueue(pCur->pRight);
	}

	return ecRetCode;
}

template <class T>
ErrorCodes BinaryTree<T>::printInOrder(Node* pNode)
{
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	if (pNode->pLeft)
		printInOrder(pNode->pLeft);

	cout << pNode->value << ", " << flush;

	if (pNode->pRight)
		printInOrder(pNode->pRight);

	return ecRetCode;
}

template <class T>
ErrorCodes BinaryTree<T>::printPreOrder(Node* pNode) {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	cout << pNode->value << ", " << flush;

	if (pNode->pLeft)
		printPreOrder(pNode->pLeft);

	if (pNode->pRight)
		printPreOrder(pNode->pRight);

	return ecRetCode;
}

template <class T>
ErrorCodes BinaryTree<T>::printPostOrder(Node* pNode) {
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
template <class T>
ErrorCodes BinaryTree<T>::printLevelOrder() {
	ErrorCodes ecRetCode = ErrorCodes::SUCCESS;

	if (NULL == m_pHead)
		return ecRetCode;

	Node* pCur;
	Queue<Node*> q;
	q.enqueue(m_pHead);

	while (!q.isEmpty()) {
		try {
			pCur = q.dequeue();

			if (NULL == pCur) {
				if (!q.isEmpty())
					q.enqueue(pCur);
				cout << endl;
				continue;
			}
			else
				cout << pCur->value << ", " << flush;
		}
		catch (int e) {
			cout << "Exception caught: " << e << ", empty queue." << endl;
			return ecRetCode;
		}

		if (q.isEmpty()) {
			// Creating sentinel
			Node* sentinel = NULL;
			q.enqueue(sentinel);
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
template <class T>
ErrorCodes BinaryTree<T>::deleteTree(Node* pNode) {
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