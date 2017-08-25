#include <iostream>
#include "header.h"
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

	LinkedListItem item1 = makeListItem("matt");
	LinkedListItem item2 = makeListItem("carl");
	linkItems(item1, item2);
	printValue(item1);
	printValue(item2);
	std::cin >> userInput; 
	return 0;
}

LinkedListItem makeListItem(std::string name)
{
	LinkedListItem item;
	item.name = name;
	item.value = rand() % 100;
	return item;
}

void linkItems(LinkedListItem first, LinkedListItem second)
{
	first.next = &second;
}

void printSize(LinkedListItem value)
{
	std::cout << "Size is: " << sizeof(value) << std::endl;
}

void printValue(LinkedListItem item)
{
	std::cout << item.name << "'s value is: " << item.value << std::endl;
	std::cout << item.name << "'s next neighbor is: " << item.next->name << std::endl;
}

void printMemoryAddress(LinkedListItem item)
{
	std::cout << "Address is: " << &item << std::endl;
}