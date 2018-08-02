#include <iostream>
#include "LinkedList.h"
int main()
{
	LinkedList <int> lnkedList;
	
	
	lnkedList.Push_Front(20);
	lnkedList.Push_Front(30);
	//std::cin.get();
	//lnkedList.PopBack();
	//lin
	//Iterator<int> itr = lnkedList.Begin();

	for (Iterator<int> i = lnkedList.Begin(); i != lnkedList.End(); ++i)
	{
		std::cout << *i << std::endl;
	}
	//lnkedList.
	std::cin.get();
	return 0;
	
}
