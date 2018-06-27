#pragma once
#include "Iterator.h"
template <class T>
class LinkedList
{
public:

	LinkedList() : m_elements(0), m_first(nullptr), m_last(nullptr)
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
				m_first->prev = node;
			// new node will be the first item
			m_first = node;

		}

	}

	~LinkedList() 
	{
		while (m_first != nullptr)
		{
			auto* temp = m_first->next;
			delete m_first;
			m_first = temp;
		}
	}

	void Push_Front(T val)
	{
		ListNode<T>* n = new ListNode<T>();
		n->next = m_first;
		n->prev = nullptr;
		n->value = val;
		//if list.last is null then
		if (m_last == nullptr)
			// set list.last to N
			m_last = n;

		else
			m_first->prev = n;

		m_first = n;

		m_elements++;
	}

	void Pop_Front()
	{
		// let N be list.first
		ListNode<T>* n = m_first;

		// if list.first.next is not null then
		if (m_first->next != NULL)
			// set list.first.next.previous to list.first.previous
			m_first->next->prev = m_first->prev;
		// set list.first to list.first.next
		m_first = m_first->next;
		// delete n
		delete n;
		m_elements--;
	}

	void Pop_Back()
	{
		

	void Push_Back()
	{
		

	}

	void Remove(T val)
	{
	}

	Iterator<T> Begin() { return Iterator<T>(m_first); }
	Iterator<T> End() { return Iterator<T>(); }

	void Insert(Iterator<T> itr, int value)
	{
		ListNode<T>* n = itr.m_node;
	}

private:
	int m_elements;
	ListNode<T>* m_first;
	ListNode<T>* m_last;
};