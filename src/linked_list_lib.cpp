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

void printArrayIndexMemoryAddress(int index)
{
	std::cout << "Array address is: " << &index << std::endl;
}

void printArrayIndicesMemoryAddresses(std::array<int, 4>& myArray)
{
	for (int i = 0; i < myArray.size(); i++)
	{
		printArrayIndexMemoryAddress(myArray[i]);
	}
    printDashedLine();
}

void printDashedLine() {
    std::cout << "--------------------------------" << std::endl;
}
