#pragma once
#include "ListNode.h"
template <class T>
class Iterator
{
public:
	Iterator()
	{

	}

	Iterator(ListNode<T>* node)
	{
		m_node = node;
	}

	bool operator == (const Iterator& other)
	{
		return m_node == other.m_node;
	}

	bool operator != (const Iterator& other)
	{
		return m_node != other.m_node;
	}

	Iterator operator ++ ()
	{
		m_node = m_node->next;
		return *this;
	}

	Iterator operator -- ()
	{
		m_node = m_node->prev;
		return *this;
	}

	T& operator *() { return m_node->value; }

	T Get() { return m_node->value; }

	~Iterator()
	{
		//delete m_node;
	}
private:
	ListNode<T>* m_node = nullptr;
};

