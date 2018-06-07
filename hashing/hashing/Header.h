#pragma once
#include <functional>
#include <iostream>

namespace HashFuctions {
	typedef std::function< unsigned int(const char*, unsigned int)> hashFunc;
	

	unsigned int badHash(const char* str, unsigned int length )
	{
		unsigned int hash = 0;
		int c;
	
		while (c = *str++)
			hash += c;
	
		return hash;
	}

	// static hashFunc default = badHash;

}