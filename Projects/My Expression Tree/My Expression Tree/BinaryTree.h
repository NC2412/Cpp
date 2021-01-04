#pragma once
#include <iostream>
#include <string>
using namespace std;

class BinaryTree
{
public:
	BinaryTree() { head = NULL; }
	~BinaryTree() { deleteTree(head); }

	bool insertPreOrder(string);
	bool insertPostOrder(string);
	bool reset();

	// 0 for preorder
	// 1 for postorder
	// 2 for infix;
	void print(const int);

private:
	struct Node {
		Node(string data) {
			this->data = data;
			pRight = NULL;
			pLeft = NULL;
		}

		string data;
		Node* pRight;
		Node* pLeft;
	};

	Node* head;

	bool insertPreOrder(Node*, string);
	bool insertPostOrder(Node*, string);

	// Prints by traversing preorder
	void printPreOrder(Node*);
	// Prints by traversing reverse preorder
	void printPostOrder(Node*);
	// Prints by traversing inorder
	void printInfix(Node*);

	bool isOperator(string);

	bool deleteTree(Node*);
};

