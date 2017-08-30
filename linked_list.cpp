#include <iostream>
#include "linked_list.h"
#include <string>

int main()
{	
	int userInput;

	// LinkedListItem item1, item2, item3, item4;
	// item1.value = 10;
	// item1.next = &item2;

	// item2.value = 25;
	// item2.next = NULL;
	
	// printMemoryAddress(item1);
	// printValue(item1.next->value);
	// printMemoryAddress(item2);

	int array1[4] = { 1, 2, 3, 4 };
	int array2[4] = { 5, 6, 7, 8 };

	//printArrayMemoryAddress(array1);
	//printArrayMemoryAddress(array2);

	LinkedListItem item1 = makeListItem("matt");
	LinkedListItem item2 = makeListItem("carl");
	linkItems(item1, item2);
	printLinkedMemoryAddress(&item1);
	printLinkedMemoryAddress(&item2);
	printValue(item1);
	printValue(item2);
	printSize(item1);
	printSize(item2);
	std::cin >> userInput; 
	return 0;
}

LinkedListItem makeListItem(std::string name)
{
	LinkedListItem item;
	item.name = name;
	item.value = rand() % 100;
	item.next = nullptr;
	return item;
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
		std::cout << "item.next is null\n";
	}
	else {
		std::cout << item.name << "'s next neighbor is: " << item.next->name << std::endl;
	}
}

void printLinkedMemoryAddress(LinkedListItem *item)
{
	std::cout << item->name << "'s Address is: " << item << std::endl;
}

void printArrayMemoryAddress(int array[])
{
	std::cout << "Array address is: " << array << std::endl;
}

//void printArrayIndicesMemoryAddresses(int myArray[])
//{
//	for (int i = 0; i < myArray->size(); i++)
//	{
//		printArrayMemoryAddress(myArray[i]);
//	}
//}