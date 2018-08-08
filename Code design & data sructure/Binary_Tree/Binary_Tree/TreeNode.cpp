#include "TreeNode.h"



TreeNode::TreeNode()
{
	m_value = 0;
	m_left = nullptr;
	m_right = nullptr;
}


TreeNode::~TreeNode()
{
}

TreeNode::TreeNode(int value)
{
	m_value = value;
	m_left = nullptr;
	m_right = nullptr;
}