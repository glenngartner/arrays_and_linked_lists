#include <iostream>
#include "linked_list_lib.hpp"
#include "LinkedList.h"
#include <array>

void printOptions(){
    printf("What would you like to do?\n");
}

int main()
{	
	int userInput;

//	std::array<int, 4> array1 = { 1, 2, 3, 4 };
//	std::array<int, 4> array2 = { 5, 6, 7, 8 };
//    array2.size();

//    printArrayIndicesMemoryAddresses(array1, "array1");
//    printArrayIndicesMemoryAddresses(array2, "array2");

    std::array<std::string, 6> names = {"Carl", "Butch", "Mark", "Steve", "Harvey", "Rich"};

    printf("\nMaking your list....\n\n");
    LinkedList *newList = new LinkedList(names, true);
    printOptions();
    std::cin >> userInput;

    newList->printList(false);
    newList->addItemToTailByName("Duke");
    newList->addItemToTailByName("Mike");
    newList->removeItemFromTail();
    newList->removeItemFromHead();
    newList->addItemToHeadByName("Becky");
    newList->removeListItemByName("Dirk");
    newList->whoIsMyHead();
    newList->printItemDetailsByName("Duke");


	std::cin >> userInput; 
	return 0;
}