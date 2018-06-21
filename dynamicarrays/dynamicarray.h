#pragma once
#include <assert.h>
template<class t>

class dynamicarray
{
public:
	dynamicarray(int size, int growBy = 1) : m_array(NULL), m_maxSize(0), m_numOfElements(0)
	{
		m_maxSize = size;
		m_array = new t[m_maxSize];
		m_growSize = ((growBy >= 1) ? growBy : 0);
	}
	~dynamicarray()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}
	void Push(t value)
	{
		assert(m_array != NULL);

		int i = 0;

		for (i = 0; i < m_numOfElements; ++i)
		{
			if (m_array[i] > value)
				break;
		}

		for (int j = m_numOfElements; j > i; --j)
		{
			m_array[j] = m_array[j - 1];
		}

		m_array[i] = value;
		m_numOfElements++;
	}


	void Pop(t value)
	{
		// 1. delete the first element
		// 2. shift all other elements one to the left

		assert(m_array != NULL);
		if (m_numOfElements > 0) {
	
			m_array[m_numOfElements] = value;
			m_numOfElements--;
			// delete[] m_array;
		}
	} 

	virtual t& operator [] (const int & index)
	{
		assert(m_array != NULL && index <= m_numOfElements);
		return m_array[index];
	}
	

private:
	t* m_array; 
	int m_maxSize;
	int m_numOfElements;
	int m_growSize;
};

