#include <iostream>
#include "dynamicarray.h"
#include <chrono>

using namespace std::chrono;

int main()
{
//	dynamicarray<char> arr(3);
//
//	arr.Push('a');
//	arr.Push('b');
//	arr.Push('c');
//	arr.Push('d');
//	arr.Push('e');
//
	dynamicarray<int> arr1(1);
	
	arr1.Push(10);
	arr1.Push(2);
	arr1.Push(45);
	arr1.Push(10);
	arr1.Push(1);
	arr1.Push(6);

	// arr1.getsize(); 
	//arr1.sort();


	//std::cin.get();

	 for (int i = 0; i < 5; ++i)
	 {
	 	std::cout << arr1[i] << std::endl;
	 }
 
	std::cin.get();

	return 0;
}


