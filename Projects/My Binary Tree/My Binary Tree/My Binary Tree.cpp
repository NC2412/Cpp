#include <iostream>
#include <stdlib.h>
#include "BinaryTree.h"
#include "Util.h"
#include "Queue.h"
using namespace std;

int main() {
	BinaryTree tree(false);

	int addArray[] = { 10, 15, 20, 25, 30, 35, 40, 45, 50};
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

	/*
		ROOT: 10
		LEAF: 3, 9, 11, 13, 15
		LEFT CHILD: 16
		RIGHT CHILD: 7
		2 CHILD: 5, 12, 14
	*/
	//tree.deleteNode(7);

	for (int i = 1; i <= 4; i++) {
		tree.printTree(i);
		cout << endl;
	}

	return 0;
}