#include <iostream>
#include <stdlib.h>
#include "BinaryTree.h"
#include "Util.h"
#include "Queue.h"
using namespace std;

int main() {
	BinaryTree tree(false);

	int addArray[] = { 10, 5, 15, 12, 4, 5, 19, 13, 1, 2, 20, 123, 1432, 54, 12, 541, 76, 56, 345, 24, 56, 345, 634, 5634, 5634, 2, 312 };
	int addNum = 0;

	for (int addNum : addArray) {
		//addNum = rand() % 100;
 		if (ErrorCodes::FAILURE == tree.insertNode(addNum)) {
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

	tree.toggleAVL();

	for (int i = 1; i <= 4; i++) {
		tree.printTree(i);
		cout << endl;
	}

	cout << endl << "NUMBER OF NODES: " << tree.getSize() << endl;

	tree.deleteNode(119);

	for (int i = 1; i <= 4; i++) {
		tree.printTree(i);
		cout << endl;
	}

	cout << "Closest common ancestor: " << tree.findClosestCommonAncestor(24, 541) << endl;

	cout << endl << "NUMBER OF NODES: " << tree.getSize() << endl;

	return 0;
}