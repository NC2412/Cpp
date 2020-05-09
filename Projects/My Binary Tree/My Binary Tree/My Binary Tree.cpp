#include <iostream>
#include <stdlib.h>
#include "BinaryTree.h"
#include "Util.h"
#include "Queue.h"
using namespace std;

int main() {
	BinaryTree tree(true);

	int addArray[] = { 20, 3, 1, 5, 15, 6, 88, 14, 2, 12, 4, 123, 5, 6, 7 };
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

	tree.deleteNode(1);

	for (int i = 1; i <= 4; i++) {
		tree.printTree(i);
		cout << endl;
	}

	cout << endl << "NUMBER OF NODES: " << tree.getSize() << endl;

	return 0;
}