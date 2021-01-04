#pragma once
#include "StringVector.h"
#include "BinaryTree.h"

class ExpressionTree
{
public:
	ExpressionTree() {}
	~ExpressionTree() {}
	
	// 1 for prefix
	// 2 for postfix
	bool buildTree(int choice, string expression);

	string printTree() { bTree.print(0); }

private:
	BinaryTree bTree;

	StringVector prefix;
	StringVector postfix;
	StringVector infix;

	StringVector tokenize(string);
	void buildPrefix(string);
	void buildPostFix(string);

	bool isOperator(char);

	int getPrecedence(string);
};

