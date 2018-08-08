#include <iostream>
#include <string>
#include "header.h"

using std::endl;

int main(int argc, char* argv[])
{
	std::cout << "General Purpose Hash Function Algorithms Test" << endl;
	std::cout << " 1. RS-Hash Function Value:   " << HashFuctions::RSHash("brent", 10) << endl;/*HashFuctions::RSHash(key, 36) << std::endl;*/
	system("pause");
	

	return 1;
}
