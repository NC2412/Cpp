#include <iostream>
#include "BinaryTree.h"
#include "Util.h"
using namespace std;

int main() {
	BinaryTree tree;

	int addArray[] = { 10, 5, 3, 7, 9, 12, 14, 16, 11, 13, 15 };
	for (int v : addArray) {
 		if (ErrorCodes::FAILURE == tree.insertNode(v)) {
			return 1;
		}
	}

	/*
		iPrintType values:
		1 - in-order
		2 - pre-order
		3 - post-order
		4 - level-order
	*/
	for (int i = 1; i <= 4; i++) {
		tree.printTree(i);
		cout << endl;
	}

	/*
		ROOT: 10
		LEAF: 3, 9, 11, 13, 15
		LEFT CHILD: 16
		RIGHT CHILD: 7
		2 CHILD: 5, 12, 14
	*/
	tree.deleteNode(12);

	for (int i = 1; i <= 4; i++) {
		tree.printTree(i);
		cout << endl;
	}

	return 0;
}