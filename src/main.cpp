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

    std::array<std::string, 6> names = {"Carl", "Butch", "Mark", "Steve", "Abel", "Hank"};
    LinkedListItem *item1 = makeListItem("Carl");
    std::array<LinkedListItem*, 6> tempListItemArray;
	createLinkedList(item1, names, true);

	// print the length of the list
    std::cout << "list length: "<< listLength(item1) << std::endl;
    printDashedLine();

    // get the last item in the list, only providing the first
    LinkedListItem* lastItem = lastListItem(item1);
    printDashedLine();
    printf("Print last item, only providing the first in the list\n");
    printAllItemInfo(lastItem);
    printDashedLine();

    // print the entire list
    printEntireList(item1);

    // add a new item to the tail
    LinkedListItem *newItem = makeListItem("last man standing");
    addToTail(item1, newItem);

    // remove the last item in the list
    removeTail(item1);

    // remove the first item in the list, and return the new first item
    LinkedListItem *newFirstItem = removeHead(item1);

    // add new item to the front of the list

    LinkedListItem *newNewFirstItem = makeListItem("Marky Mark");
    addToHead(newFirstItem, newNewFirstItem);

	std::cin >> userInput; 
	return 0;
}