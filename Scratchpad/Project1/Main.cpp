#include <iostream>
#include <string>
#include "BinarySearchTree.h"


int main() {
	BinarySearchTree<int> bst;
	bst.insert(5);
	bst.insert(1);
	bst.insert(2);
	bst.insert(6);
	bst.traverse();
	std::cin.get();

	std::string str = "abcdefghijklmnop";


}