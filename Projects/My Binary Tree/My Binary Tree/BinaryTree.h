#pragma once
#include <iostream>
#include "Util.h"
using namespace std;

class BinaryTree
{

	struct Node {
		int value;

		Node* pLeft  = NULL;
		Node* pRight = NULL;
	};

public:
	// CTORs and DTORs
	BinaryTree();
	~BinaryTree();

	// Operating methods
	ErrorCodes insertNode(int value);

	// TODO
	// - fix internal node case insert
	// - implement in order, post order, pre order, level order.
	ErrorCodes printTree();

private:
	// Member variables
	Node* m_pHead;
};

