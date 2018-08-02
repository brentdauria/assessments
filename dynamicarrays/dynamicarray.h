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
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}

	void Push(t value)
	{
		assert(m_array != NULL);
		int i = 0;
		if (m_numOfElements >= m_maxSize)
		{
			resize();
		}
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

	void resize()
	{
		assert(m_array != NULL);
		auto temp = new t [m_maxSize + m_growSize];
		memcpy(temp, m_array, sizeof(t) * m_numOfElements);
		
		delete[] m_array;

		m_array = temp;
		m_maxSize += m_growSize;
	}

	void remove(int index)
	{
		assert(m_array != NULL);
		if(index > sizeof(m_array))
		{
			return;
		}
		if (m_numOfElements > sizeof(m_array))
		{
			resize();
		}
		m_array--;
		if (m_numOfElements > sizeof(m_array))
		{
			m_numOfElements = sizeof(m_array) - 1;
		}
	}

	void sort()
	{
		assert(m_array != NULL);
		int temp = 0;
		int i = 0;
		for (int i = 0; i <= m_numOfElements - 1; i++);
		{
			if (m_array[i] > (m_array[i + 1]))
			{
				temp = m_array[i + 1];
				m_array[i + 1] = m_array[i];
				m_array[i] = temp;
			}
		}
	}

	void Pop()
	{
		assert(m_array != NULL);
		if (m_numOfElements > 0) {
			m_numOfElements--;
		}
	} 

	void insert(int index, t val)
	{
		assert(m_array != NULL);
		if (index >= m_maxSize)
		{
			return;
		}
		if (m_numOfElements >= m_maxSize)
		{
			resize();
		}
		for (int i = m_numOfElements; i > index; --i)
		{
			m_array[i] = m_array[i - 1];
		}
		m_array[index] = val;
		m_numOfElements++;
	}


	virtual t& operator [] (const int & index)
	{
		assert(m_array != NULL && index <= m_numOfElements);
		return m_array[index];
	}
	
	void clear()
	{
		m_numOfElements = 0;
	}

	int getsize()
	{
		std::cout << m_numOfElements << std::endl;
		return m_numOfElements;
	}

	void search(t val)
	{
		bool searchvalue = true;
		assert(m_array != NULL);
		while (searchvalue)
		{
			for (int i = 0; i <= m_numOfElements; ++i)
			{
				if (m_array[i] == val)
				{
					std::cout << "found the value " << m_array[i] << std::endl;
					searchvalue = false;
				}
			}
		}
	}

private:
	t* m_array; 
	int m_maxSize;
	int m_numOfElements;
	int m_growSize;
};

