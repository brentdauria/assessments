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



	void Push_Front(T val)
	{
		ListNode<T>* n = new ListNode<T>();
		n->value = val;

		if(n->next)
		m_firstnode = n->next;

		n->prev = nullptr;
		//if list.last is null then
		if (m_lastnode == nullptr)
		{
			// set list.last to N
			m_lastnode = n;
	
		}
		else
		{
			if(m_firstnode)
			m_firstnode->prev = n;

			m_firstnode = n;
		}
		m_elements++;
	}
	


	void pushBack(T val)
	{
		ListNode<T>* n = new ListNode<T>();
		n->prev = m_lastnode;
		n->next = nullptr;
		n->Value = Val;

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
		//Delete all and reset
		while (m_first != nullptr)
		{
			auto* temp = m_firstnode->next;
			delete m_first;
			m_first = temp;
		}
		m_nodeCount = 0;
	}
	
	void insert_back(const T& value)
	{
		ListNode<T> * n = new ListNode<T>();
		n->value = value;

		n->prev = m_lastnode;
		n->next = nullptr;

	
		if (m_firstnode == nullptr) {
			m_firstnode = n;
		}

		if (m_lastnode != nullptr) {
			m_lastnode->next = n;
		}
		m_lastnode = n;
		m_elements++;
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


		void Insert(Iterator<T> itr, int value)
		{
			ListNode<T>* n = itr.m_node;
		}
private:
		int m_elements;
		ListNode<T>* m_firstnode;
		ListNode<T>* m_lastnode;
};