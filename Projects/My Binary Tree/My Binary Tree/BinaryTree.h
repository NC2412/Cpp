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
		//Node* pNext = NULL;
	};

public:
	// CTORs and DTORs
	BinaryTree() : m_pHead(NULL), m_fIsAVL(false) {};
	BinaryTree(bool avl) : m_pHead(NULL), m_fIsAVL(avl) {};
	// DELETE COUT WHEN DONE WITH TESTING
	~BinaryTree() { cout << findHeight(m_pHead) << endl; deleteTree(m_pHead); }

	// Operating methods
	ErrorCodes insertNode(int value);
	ErrorCodes deleteNode(int delValue);
	ErrorCodes printTree(int iPrintType);
	bool hasValue(int value);

	// Mutator methods
	void toggleAVL();

	// TODO
	// use delete node as recursive
	//		- use helper methods
	// 
	// closest common ancestor
	//	- given two nodes, what is their common parent?
	//
	// threading siblings
	//  - left right next

private:
	// Private helper methods
	ErrorCodes setToPredecessor(Node* rootNode, Node* pCur, Node* pPrev);
	ErrorCodes setToSuccessor(Node* rootNode, Node* pCur, Node* pPrev);
	ErrorCodes deleteGivenNode(Node* pDelNode, Node* pDelPrev, Node* pCur, Node* pPrev);
	int findHeight(Node*);
	Node* rotateLeft(Node*);
	Node* rotateRight(Node*);

	// Private operating methods
	Node* balanceTree(Node*);
	ErrorCodes printInOrder(Node* pNode);
	ErrorCodes printPreOrder(Node* pNode);
	ErrorCodes printPostOrder(Node* pNode);
	ErrorCodes printLevelOrder();
	ErrorCodes deleteTree(Node* pNode);

private:
	// Member variables
	Node* m_pHead;
	bool m_fIsAVL;
};

