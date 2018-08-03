#include <iostream>
#include "LinkedList.h"
int main()
{
	LinkedList <int> lnkedList;
	
	
	lnkedList.PushFront(20); 
	lnkedList.PushFront(30);
	lnkedList.pushBack(400);
	lnkedList.PushFront(32);
	lnkedList.count();
 	std::cout << lnkedList.nodefirst()->value << std::endl;
	std::cout << lnkedList.nodelast()->value << std::endl;
	//std::cin.get();
	//lnkedList.PopFront();
	//lnkedList.empty();
	//lnkedList.PopBack();
	// lnkedList.clear();

	Iterator<int> itr(lnkedList.Begin());

	for (; itr != lnkedList.End(); ++itr)
	{
		std::cout << *itr << std::endl;
	}
	std::cin.get();
	return 0;
}
