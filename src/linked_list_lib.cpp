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
	printValue(item);
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

void printValue(LinkedListItem *item)
{
	std::cout << item->name << "'s value is: " << item->value << std::endl;
	if (item->next == nullptr) {
		std::cout << item->name << " doesn't have a neighbor (it's null)" << std::endl;
	}
	else {
		std::cout << item->name << "'s next neighbor is: " << item->next->name << std::endl;
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

void createLinkedList(LinkedListItem *firstItem, std::array<std::string, 6> &names,
                      std::array<LinkedListItem *, 6>& tempListItemArray, bool verbose) {
//    std::array<LinkedListItem*, 6> tempListItemArray;
    tempListItemArray[0] = firstItem;
    for (int i = 1; i < names.size(); i++) // start the loop at 1, since we've already created the first item
    {
        LinkedListItem newItem= makeListItem(names[i]); // make a new list item
        tempListItemArray[i] = &newItem; // store the address of the new item in the temporary array
        linkItems(*tempListItemArray[i-1], *tempListItemArray[i]); // link this list item to the previous item

        if (verbose)
        {
            std::cout << names[i-1] << " was created and linked to " << names[i] << std::endl;
        }

    }
    printDashedLine();
}

int listLength(LinkedListItem *firstItem) {
    unsigned int length = 1; // starts at 1, since we always have 1 item (the function argument)
    LinkedListItem * itemInScope = firstItem;
    while(itemInScope->next != nullptr)
    {
        length ++;
        itemInScope = itemInScope->next;
    }
    return length;
}

LinkedListItem *lastListItem(LinkedListItem *firstItem) {
    LinkedListItem * itemInScope = firstItem;
    while (itemInScope->next != nullptr)
    {
        itemInScope = itemInScope->next;
    }
    return itemInScope;
}

void printEntireList(LinkedListItem *firstItem) {
    printf("List Details:\n");
//    int length = listLength(firstItem);
//    printDashedLine();
//    printf("Length: \n", length);
    LinkedListItem *itemInScope = firstItem;
    while (true)
    {
        printAllItemInfo(itemInScope);

        if (itemInScope->next == nullptr)
        {
            return;
        } else {
            itemInScope = itemInScope->next;
        }
    }
}

void addToTail(LinkedListItem *firstItem, LinkedListItem *newItem) {
    LinkedListItem *lastItem = lastListItem(firstItem);
    linkItems(*lastItem, *newItem);
    LinkedListItem *newLastItem = lastListItem(firstItem);
    printf("\n");
    printf("***************************************\n");
    printf("New item added to the end of the list:\n");
    printf("***************************************\n");
    printf("\n");
    printAllItemInfo(newItem);
    std::cout << lastItem->name << " was the last in the list.\nNow his new neighbor is " << newLastItem->name << std::endl;
    std::cout << newLastItem->name << " is now last in the list" << std::endl;
}
