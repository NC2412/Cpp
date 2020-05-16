#pragma once
#include <iostream>
#include "Util.h"
using namespace std;

class BinaryTree
{
private:
	struct Node {
		int value = -1;

		Node* pLeft = NULL;
		Node* pRight = NULL;
		Node* pNext = NULL;
	};

public:
	// CTORs and DTORs
	BinaryTree() : m_pHead(NULL), m_fIsAVL(false) {};
	BinaryTree(bool avl) : m_pHead(NULL), m_fIsAVL(avl) {};
	~BinaryTree() { deleteTree(m_pHead); }

	// Operating methods
	ErrorCodes  insertNode(int);
	ErrorCodes  deleteNode(int);
	ErrorCodes  printTree(int);
	int			findClosestCommonAncestor(int, int);
	bool		hasValue(int);

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
	Node*		getNode(int);

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

