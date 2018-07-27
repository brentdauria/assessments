#include <iostream>
#include "dynamicarray.h"
#include <chrono>

using namespace std::chrono;

int main()
{
	dynamicarray<char> arr(3);

	arr.Push('a');
	arr.Push('b');
	arr.Push('c');
	arr.Push('d');
	arr.Push('e');
	


	 for (int i = 0; i < 5; ++i)
	 {
	 	std::cout << arr[i] << std::endl;
	 }

	std::cin.get();

	return 0;
}


