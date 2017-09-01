#include <iostream>
#include "linked_list_lib.hpp"
#include <array>

int main()
{	
	int userInput;

	std::array<int, 4> array1 = { 1, 2, 3, 4 };
	std::array<int, 4> array2 = { 5, 6, 7, 8 };
    array2.size();

//    printArrayIndicesMemoryAddresses(array1, "array1");
//    printArrayIndicesMemoryAddresses(array2, "array2");

    LinkedListItem item1 = makeListItem("matt");
	LinkedListItem item2 = makeListItem("carl");
	LinkedListItem item3 = makeListItem("steve");
	LinkedListItem item4 = makeListItem("frank");
	LinkedListItem item5 = makeListItem("mike");
	LinkedListItem item6 = makeListItem("blitzen");
	linkItems(item1, item2);
	linkItems(item2, item3);
	linkItems(item3, item4);
	linkItems(item4, item5);
	linkItems(item5, item6);
//	printAllItemInfo(&item1);
//	printAllItemInfo(&item2);
//	printAllItemInfo(&item3);
//	printAllItemInfo(&item4);
//	printAllItemInfo(&item5);
//	printAllItemInfo(&item6);

    // print the length of the list
    std::cout << "list length: "<< listLength(&item1) << std::endl;
    printDashedLine();

    // get the last item in the list, only providing the first
    LinkedListItem* lastItem = lastListItem(&item1);
    printDashedLine();
    printf("Print last item, only providing the first in the list\n");
    printAllItemInfo(lastItem);
    printDashedLine();

    // print the entire list
    printEntireList(&item1);

    // add a new item to the tail
    LinkedListItem newItem = makeListItem("last man standing");
    addToTail(&item1, &newItem);


//    std::array<std::string, 6> names = {"Carl", "Butch", "Mark", "Steve", "Abel", "Hank"};
//    LinkedListItem item1 = makeListItem("Carl");
//    std::array<LinkedListItem*, 6> tempListItemArray;
//    createLinkedList(&item1, names, tempListItemArray, true);
//
//    printValue(&item1);
//    printAllItemInfo(&item1);

	std::cin >> userInput; 
	return 0;
}