#include <iostream>
#include "linked_list_lib.hpp"
#include <array>

int main()
{	
	int userInput;

	std::array<int, 4> array1 = { 1, 2, 3, 4 };
	std::array<int, 4> array2 = { 5, 6, 7, 8 };
    array2.size();

    printArrayIndicesMemoryAddresses(array1, "array1");
    printArrayIndicesMemoryAddresses(array2, "array2");

//    LinkedListItem item1 = makeListItem("matt");
//	LinkedListItem item2 = makeListItem("carl");
//	LinkedListItem item3 = makeListItem("steve");
//	linkItems(item1, item2);
//	linkItems(item2, item3);
//	printAllItemInfo(&item1);
//	printAllItemInfo(&item2);
//	printAllItemInfo(&item3);

    std::array<std::string, 6> names = {"Carl", "Butch", "Mark", "Steve", "Abel", "Hank"};
    LinkedListItem item1 = createLinkedList(names, true);

    printAllItemInfo(&item1);

	std::cin >> userInput; 
	return 0;
}