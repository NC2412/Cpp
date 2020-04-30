#pragma once
#include <iostream>
#include "Util.h"
using namespace std;

class BinaryTree
{
	struct Node {
		int value = -1;

		Node* pLeft = NULL;
		Node* pRight = NULL;
		//Node* pNext = NULL;
	};

public:
	// CTORs and DTORs
	BinaryTree();
	~BinaryTree();

	// Operating methods
	ErrorCodes insertNode(int value);
	ErrorCodes deleteNode(int delValue);

	// TODO
	// - implement in order, post order, pre order, level order.
	ErrorCodes printTree(int iPrintType);
	// use a queue to iteratively print level order
	// use delete node as recursive
	//		- use helper methods
	// 
	// closest common ancestor
	//	- given two nodes, what is their common parent?
	//
	// threading siblings
	//  - left right next

private:
	ErrorCodes printInOrder(Node* pNode);
	ErrorCodes printPreOrder(Node* pNode);
	ErrorCodes printPostOrder(Node* pNode);
	ErrorCodes printLevelOrder();

	ErrorCodes deleteList(Node* pNode);

private:
	// Member variables
	Node* m_pHead;
};

