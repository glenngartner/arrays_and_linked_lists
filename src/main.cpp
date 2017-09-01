#include <iostream>
#include "linked_list_lib.hpp"
#include "LinkedList.h"
#include <array>

int main()
{	
	int userInput;

//	std::array<int, 4> array1 = { 1, 2, 3, 4 };
//	std::array<int, 4> array2 = { 5, 6, 7, 8 };
//    array2.size();

//    printArrayIndicesMemoryAddresses(array1, "array1");
//    printArrayIndicesMemoryAddresses(array2, "array2");

    std::array<std::string, 6> names = {"Carl", "Butch", "Mark", "Steve", "Harvey", "Rich"};

    LinkedList *newList = new LinkedList(names, true);
    newList->printList(false);
    newList->addItemToTailByName("Duke");
    newList->addItemToTailByName("Mike");
    newList->removeItemFromTail();
    newList->removeItemFromHead();
    newList->addItemToHeadByName("Becky");
    newList->removeListItemByName("Dirk");
    newList->whoIsMyHead();
//    newList->printItemDetailsByName("Mike");


	std::cin >> userInput; 
	return 0;
}