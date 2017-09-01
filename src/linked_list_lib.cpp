#include <iostream>
#include <string>
#include <array>
#include "linked_list_lib.hpp"

LinkedListItem makeListItem(std::string name)
{
	LinkedListItem item;
	item.name = name;
	item.value = rand() % 100;
	item.next = nullptr;
	return item;
}

void printAllItemInfo(LinkedListItem *item)
{
	printLinkedMemoryAddress(item);
	printSize(*item);
	printValue(*item);
    printDashedLine();
}

void linkItems(LinkedListItem& first, LinkedListItem& second)
{
	first.next = &second;
}

void printSize(LinkedListItem item)
{
	std::cout << item.name << "'s size is: " << sizeof(item) << std::endl;
}

void printValue(LinkedListItem& item)
{
	std::cout << item.name << "'s value is: " << item.value << std::endl;
	if (item.next == nullptr) {
		std::cout << item.name << " doesn't have a neighbor (it's null)" << std::endl;
	}
	else {
		std::cout << item.name << "'s next neighbor is: " << item.next->name << std::endl;
	}
}

void printLinkedMemoryAddress(LinkedListItem *item)
{
	std::cout << item->name << "'s Address is: " << item << std::endl;
}

void printArrayIndexMemoryAddress(int value, std::string name, unsigned int index)
{
	std::cout << name << "[" << index << "] address: " << &value << std::endl;
}

void printArrayIndicesMemoryAddresses(std::array<int, 4> &myArray, std::string name)
{
	for (int i = 0; i < myArray.size(); i++)
	{
        printArrayIndexMemoryAddress(myArray[i], name, i);
	}
    printDashedLine();
}

void printDashedLine() {
    std::cout << "--------------------------------" << std::endl;
}

LinkedListItem createLinkedList(std::array<std::string, 6> &names, bool verbose) {
    std::array<LinkedListItem, 6> tempListItemArray;
    LinkedListItem firstItem = makeListItem(names[0]);
    tempListItemArray[0] = firstItem;
    for (int i = 1; i < names.size(); i++)
    {
        if (verbose)
        {
            std::cout << names[i-1] << " was created and linked to " << names[i] << std::endl;
        }

        tempListItemArray[i] = makeListItem(names[i]); // create a new list item, and store it in the array
        linkItems(tempListItemArray[i-1], tempListItemArray[i]); // link this list item to the previous item

    }
    printDashedLine();

    return firstItem;
}
