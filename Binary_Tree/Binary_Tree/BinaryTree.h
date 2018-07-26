#pragma once
#include "TreeNode.h"
class BinaryTree
{
public:
	BinaryTree();
	bool isEmpty() const;
	void insert(int a_nValue);
	void remove(int a_nValue);
	TreeNode* find(int a_nValue);
	~BinaryTree();
private:
	bool findNode(int a_nsearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent);
	TreeNode* m_pRoot;
};

