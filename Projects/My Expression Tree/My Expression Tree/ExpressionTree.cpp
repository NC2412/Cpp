#include "ExpressionTree.h"

bool ExpressionTree::buildTree(int choice, string expression) {
	switch (choice) {
	case 1:
		buildPrefix(expression);
		break;
	case 2:
		buildPostFix(expression);
		break;
	default:
		return 0;
	}

	return 1;
}

void ExpressionTree::buildPrefix(string expression) {

}

void ExpressionTree::buildPostFix(string expression) {
	StringVector vector = tokenize(expression);
}

StringVector ExpressionTree::tokenize(const string expression) {
	StringVector vector;
	string token = "";

	for (unsigned int i = 0; i < expression.length(); i++) {
		if (expression[i] != ' ') {
			if (isOperator(expression[i])) {
				vector.add(token);
				token = "";
			}

			token += expression[i];
		}
		else {
			if (token != "")
				vector.add(token);

			token = "";
		}
	}

	cout << token << endl;

	return vector;
}

bool ExpressionTree::isOperator(char item) {
	if (item == '+' || item == '-' || item == '*' || item == '/' || item == '%' || item == '^')
		return true;
	else
		return false;
}
