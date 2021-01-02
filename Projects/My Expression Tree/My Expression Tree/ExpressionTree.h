#pragma once
#include "StringVector.h"
#include "BinaryTree.h"

class ExpressionTree
{
public:
	ExpressionTree();
	~ExpressionTree();

	StringVector buildPrefix();
	StringVector buildPostFix();

private:
	
};

