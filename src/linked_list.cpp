#include <iostream>
#include "linked_list_lib.hpp"
#include <array>

int main()
{	
	int userInput;

	std::array<int, 4> array1 = { 1, 2, 3, 4 };
	std::array<int, 4> array2 = { 5, 6, 7, 8 };
    array2.size();

    printArrayIndicesMemoryAddresses(array1);

    LinkedListItem item1 = makeListItem("matt");
	LinkedListItem item2 = makeListItem("carl");
	LinkedListItem item3 = makeListItem("steve");
	linkItems(item1, item2);
	linkItems(item2, item3);
	printAllItemInfo(&item1);
	printAllItemInfo(&item2);
	printAllItemInfo(&item3);

	std::cin >> userInput; 
	return 0;
}