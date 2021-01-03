#include "BinaryTree.h"

bool BinaryTree::insertPreOrder(string item) {
	return insertPreOrder(head, item);
}

bool BinaryTree::insertPreOrder(Node* cur, string item) {
	int result = 0;

	// Root node needs to be inserted
	if ("" == cur->data) {
		cur->data = item;
		return 1;
	}

}

bool BinaryTree::insertPostOrder(string item) {
	return false;
}

bool BinaryTree::isOperator(string item) {
	if (item == "+" || item == "-" || item == "*" || item == "/" || item == "%" || item == "^")
		return true;
	else
		return false;
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