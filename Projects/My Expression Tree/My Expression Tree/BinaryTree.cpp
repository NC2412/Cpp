#include "BinaryTree.h"

bool BinaryTree::insertPreOrder(string item) {
	return insertPreOrder(head, item);
}

// Pre order inserts values at the leftmost available node.
bool BinaryTree::insertPreOrder(Node* cur, string item) {
	// Head case
	if (NULL == cur) {
		cur = new Node(item);
		return 1;
	}
	else if (NULL == cur->pLeft) {
		cur->pLeft = new Node(item);
		return 1;
	}
	else if (isOperator(cur->pLeft->data)) {
		insertPreOrder(cur->pLeft, item);
	}
	else if (NULL == cur->pRight) {
		cur->pRight = new Node(item);
		return 1;
	}
	else if (isOperator(cur->pRight->data)) {
		insertPreOrder(cur->pRight, item);
	}
	else {
		return 0;
	}
}

bool BinaryTree::insertPostOrder(string item) {
	return insertPostOrder(head, item);
}

bool BinaryTree::insertPostOrder(Node* cur, string item) {
	// Head case
	if (NULL == head) {
		head = new Node(item);
		return 1;
	}
	else if (NULL == cur->pRight) {
		cur->pRight = new Node(item);
		return 1;
	}
	else if (isOperator(cur->pRight->data)) {
		insertPostOrder(cur->pRight, item);
	}
	else if (NULL == cur->pLeft) {
		cur->pLeft = new Node(item);
		return 1;
	}
	else if (isOperator(cur->pLeft->data)) {
		insertPostOrder(cur->pLeft, item);
	}
	else {
		return 0;
	}
}

bool BinaryTree::isOperator(string item) {
	if (item == "+" || item == "-" || item == "*" || item == "/" || item == "%" || item == "^")
		return true;
	else
		return false;
}

void BinaryTree::print(const int choice) {
	switch (choice) {
	case 0:
		printPreOrder(head);
		break;
	case 1:
		printPostOrder(head);
		break;
	case 2:
		printInfix(head);
		break;
	default:
		cout << "ERROR PRINTING, INCORRECT INPUT." << endl;
	}
}

void BinaryTree::printPreOrder(Node* cur) {
	cout << cur->data << flush;

	if (NULL != cur->pLeft)
		printPreOrder(cur->pLeft);

	if (NULL != cur->pRight)
		printPreOrder(cur->pRight);
}

void BinaryTree::printPostOrder(Node* cur) {
	cout << cur->data << flush;

	if (NULL != cur->pRight)
		printPostOrder(cur->pRight);

	if (NULL != cur->pLeft)
		printPostOrder(cur->pLeft);
}

void BinaryTree::printInfix(Node* cur) {
	if (isOperator(cur->data))
		cout << "(" << flush;

	if (NULL != cur->pLeft)
		printInfix(cur->pLeft);

	cout << cur->data << flush;

	if (NULL != cur->pRight)
		printInfix(cur->pRight);

	if (isOperator(cur->data))
		cout << ")" << flush;
}

bool BinaryTree::reset() {
	if (NULL == head) {
		return 1;
	}
	if (NULL != head->pLeft) {
		deleteTree(head->pLeft);
	}
	if (NULL != head->pRight) {
		deleteTree(head->pRight);
	}

	head->data = "";
	head->pLeft = NULL;
	head->pRight = NULL;

	return 1;
}

bool BinaryTree::deleteTree(Node* cur) {
	if (NULL == head) {
		delete head;
		return 1;
	}

	if (NULL != cur->pLeft) {
		deleteTree(cur->pLeft);
	}
	if (NULL != cur->pRight) {
		deleteTree(cur->pRight);
	}

	cur->pLeft = NULL;
	cur->pRight = NULL;
	delete cur;

	return 1;
}