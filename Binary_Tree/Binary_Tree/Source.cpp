#include <iostream>
#include "BinaryTree.h"
int main()
{
	BinaryTree* newTree = new BinaryTree();
	newTree->insert(20);
	newTree->insert(10);
	newTree->insert(50);
	TreeNode* foundNode = newTree->find(10);

	std::cout << foundNode->getData() << "\n";

	system("pause");
}