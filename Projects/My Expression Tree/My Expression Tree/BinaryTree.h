#pragma once
#include <string>
using namespace std;

class BinaryTree
{
public:
	BinaryTree() { size = 0; head = NULL; }
	~BinaryTree() { deleteTree(head); }

	bool insertPreOrder(string);
	bool insertPostOrder(string);
	bool reset();

	int getSize() { return size; }

private:
	struct Node {
		string data = "";
		Node* pRight = NULL;
		Node* pLeft = NULL;
	};

	Node* head;
	int size;

	bool insertPreOrder(Node*, string);
	bool insertPostOrder(Node*, string);

	bool isOperator(string);

	bool deleteTree(Node*);
};

