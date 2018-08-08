#pragma once
#include "Iterator.h"
template <class T>
class LinkedList
{
public:
	Iterator<T> Begin() { return Iterator<T>(m_firstnode); }
	Iterator<T> End() { return Iterator<T>(); }

	~LinkedList()
	{
		while (m_firstnode != nullptr)
		{
			auto* temp = m_firstnode->next;
			delete m_firstnode;
			m_firstnode = temp;
		}
	}
	LinkedList() : m_elements(0), m_firstnode(nullptr), m_lastnode(nullptr)
	{

	}

	LinkedList(int startingElements) : m_elements(startingElements)
	{

		for (int i = 0; i < m_elements; ++i)
		{
			ListNode<T>* node = new ListNode<T>();
			// if the first item eve?
			if (i == 0)
				m_first = node;
			// make it point to the first item
			node->next = m_first;
			node->value = 0;
			// make the first item point back to the new first
			if (m_first != nullptr)
				m_firstnode->prev = node;
			// new node will be the first item
			m_firstnode = node;

		}

	}

	void count()
	{
		std::cout << "There is " << m_elements << " Elements" << std::endl;
	}


	bool empty()
	{
		if (m_elements <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	ListNode<T>* nodefirst()
	{
		return m_firstnode;
	}

	ListNode<T>* nodelast()
	{
		return m_lastnode;
	}

	void PushFront(T val)
	{
		ListNode<T>* n = new ListNode<T>();
		n->value = val;

		if(m_firstnode == nullptr)
			m_firstnode = n;

		//if list.last is null then
		if (m_lastnode == nullptr)
		{
			// set list.last to N
			m_lastnode = n;
		}
		if (!empty())
		{
			ListNode<T>* prevNode = m_firstnode;
			m_firstnode = n;
			m_firstnode->next = prevNode;
			prevNode->prev = m_firstnode;
		}
		m_elements++;
	}
	


	void pushBack(T val)
	{
		ListNode<T>* n = new ListNode<T>();
		n->prev = m_lastnode;
		n->next = nullptr;
		n->value = val;

		if (m_firstnode == NULL)
		{
			m_firstnode = n;
		}
		else if (m_lastnode != NULL)
		{
			m_lastnode->next = n;
		}
		m_lastnode = n;
		m_elements++;
	}

	void clear()	//Remove all elements from the list
	{
		
		while (m_firstnode != nullptr)
		{
			auto* temp = m_firstnode->next;
			delete m_firstnode;
			m_firstnode = temp;
		}
		m_elements = 0;
	}
	

	void PopBack()
	{
		ListNode<T>* node = new ListNode<T>();
		if (m_lastnode->prev != NULL)
		{
			m_lastnode->prev->next = m_lastnode->next; 
			m_lastnode = m_lastnode->prev;
			delete node;
			m_elements--;
		}
	}

	void PopFront()
	{
		if (m_firstnode != nullptr)	
		{
			ListNode<T>* temp = m_firstnode;
			m_firstnode->next->prev = m_firstnode->prev;
			m_firstnode = m_firstnode->next;
			delete temp;
			m_elements--;
		}
	}

	void Insert(Iterator<T> itr, int value)
	{
		ListNode<T>* n = itr.m_node;
	}

private:
	int m_elements;
	ListNode<T>* m_firstnode;
	ListNode<T>* m_lastnode;
};