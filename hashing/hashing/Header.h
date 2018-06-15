#pragma once
#include <functional>
#include <iostream>

namespace HashFuctions {
	typedef std::function< unsigned int(const char*, unsigned int)> HashFunc;
	

	unsigned int badHash(const char* data, unsigned int length);

	
	unsigned int RSHash(const char* str, unsigned int lenght)
	{
		unsigned int b = 378551;
		unsigned int a = 63689;
		unsigned int hash = 0;
		unsigned int i = 0;

		for (i = 0; i < lenght; ++str, ++i)
		{
			hash = hash * a + (*str);
			a = a * b;
		}
		return hash;

	}

	static HashFunc defaultHash = badHash;

}