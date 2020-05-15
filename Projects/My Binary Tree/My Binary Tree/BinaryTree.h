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
	// DELETE COUT WHEN DONE WITH TESTING
	~BinaryTree() { cout << findHeight(m_pHead) << endl; deleteTree(m_pHead); }

	// Operating methods
	ErrorCodes insertNode(int);
	ErrorCodes deleteNode(int);
	ErrorCodes printTree(int);
	bool hasValue(int);

	// Mutator methods
	inline void toggleAVL() { if (m_fIsAVL) m_fIsAVL = false; else { m_fIsAVL = true; balanceTree(); } }

	// Getter methods
	inline int getSize() { return countNodes(m_pHead); }

	// TODO
	// closest common ancestor
	//	- given two nodes, what is their common parent?
	//  - check for the heights of the nodes, if theyre the same, walk up the list until a parent matches.
	//
	// threading siblings
	//  - left right next

private:
	// Private helper methods
	ErrorCodes handleNodeDelete(Node*, Node*, Node*);
	int findHeight(Node*);
	Node* rotateLeft(Node*);
	Node* rotateRight(Node*);
	
	// Private getter methods
	Node* getPredecessor(Node*);
	Node* getSuccessor(Node*);

	// Private operating methods
	int countNodes(Node*);
	ErrorCodes threadTree();
	ErrorCodes balanceTree();
	Node* balanceSubTree(Node*);
	ErrorCodes printInOrder(Node*);
	ErrorCodes printPreOrder(Node*);
	ErrorCodes printPostOrder(Node*);
	ErrorCodes printLevelOrder();
	ErrorCodes deleteTree(Node*);

private:
	// Member variables
	Node* m_pHead;
	bool m_fIsAVL;
};

