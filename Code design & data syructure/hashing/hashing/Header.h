#pragma once
#include <functional>
#include <iostream>

namespace HashFuctions {
	typedef std::function< unsigned int(const char*, unsigned int)> HashFunc;
	

	unsigned int badHash(const char* data, unsigned int length);

	
	unsigned int RSHash(const char* str, unsigned int lenght);
	

	static HashFunc defaultHash = badHash;

}