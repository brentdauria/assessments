#include "BinaryTree.h"



BinaryTree::BinaryTree()
{
	m_pRoot = nullptr;
}


BinaryTree::~BinaryTree()
{
}

bool BinaryTree::isEmpty() const
{
	if (m_pRoot == nullptr)
	{
		return true;
	}
	return false;
}




void BinaryTree::insert(int a_nValue)
{
	if (isEmpty()) {
		m_pRoot = new TreeNode(a_nValue);
		//m_pRoot->setData(a_nValue);
	}
	else
	{
		TreeNode* currentnode = m_pRoot;

		while (currentnode != nullptr)
		{
			if (a_nValue < currentnode->getData())
			{
				if (currentnode->hasLeft())
				{
					currentnode = currentnode->getLeft();
					continue;
				}
				{
					TreeNode* node = new TreeNode();
					node->setData(a_nValue);
					currentnode->setLeft(node);
					break;
				}
			}
			if (a_nValue > currentnode->getData())
			{
				if (currentnode->hasRight())
				{
					currentnode = currentnode->getRight();
					continue;
				}
				{
					TreeNode* node = new TreeNode();
					node->setData(a_nValue);
					currentnode->setRight(node);
					break;
				}
			}
			if (a_nValue == currentnode->getData())
			{
				break;
			}
		}
	}
}

void BinaryTree::remove(int a_nValue)
{
	TreeNode* currnetnode = nullptr;
	TreeNode* parentnode = nullptr;
	find(currnetnode->getData());

	if (currnetnode->hasRight())
	{
		//	findNode();
	}

}

TreeNode * BinaryTree::find(int a_nValue)
{
	TreeNode* currentNode = nullptr;
	TreeNode* parentNode = nullptr;
	if (findNode(a_nValue, &currentNode, &parentNode))
		return currentNode;
	else
		return nullptr;
}


bool BinaryTree::findNode(int a_nsearchValue, TreeNode ** ppOutNode, TreeNode ** ppOutParent)
{
	TreeNode* currentnode = m_pRoot;
	TreeNode* parentnode = nullptr;

	while (currentnode != nullptr)
	{
		if (a_nsearchValue == currentnode->getData())
		{
			*ppOutNode = currentnode;
			*ppOutParent = parentnode;
			return true;
		}
		else if (a_nsearchValue < currentnode->getData())
		{
			currentnode = currentnode->getLeft();
		}
		else
		{
			currentnode = currentnode->getRight();
		}
	}

	return false;
}
