//
// File name and a quick description of the purpose
//

#pragma once
#include <iostream>
#include "Util.h"
using namespace std;

//
//
//
//
//

class LinkedList
{
public:
	// Creating the Node struct.
	struct Node {

		int value = 0;

		// next must be a pointer because it will point to the next Node object.
		Node* pNext = NULL;
	};

public: 
	// CTORs and DTORs
	LinkedList();
	LinkedList(bool isSorted);
	~LinkedList();

	// Operating methods
	ErrorCodes insertNode(int value);
	ErrorCodes deleteNode(int value);
	ErrorCodes deleteIndex(unsigned int removeIndex);
	ErrorCodes removeDuplicates();
	ErrorCodes sortList();
	ErrorCodes mergeLists(Node* other);
	ErrorCodes reverseList();
	bool hasCycle();
	int nFromTail(int nthfromtail);
	ErrorCodes printList();
	
	// Accessor methods
	inline bool isSorted() { return m_fisSorted ? true : false; }

	// Mutator methods
	inline void toggleSort() { if (m_fisSorted) { m_fisSorted = false; } else { m_fisSorted = true; /*sortList();*/ } }

private:
	// Private operating methods
	ErrorCodes insertSorted(int value);
	ErrorCodes addToEnd(int value);
	Node* mergeSort(Node* pList);
	Node* merge(Node* pListL, Node* pListR);
	ErrorCodes deleteList();

private:
	// Member variables
	Node*	m_pHead;
	Node*	m_pTail;
	bool	m_fisSorted;
};