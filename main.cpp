#include <iostream>
#include "header.h"

int main()
{	
	int userInput;

	LinkedListItem item1, item2, item3, item4;
	item1.value = 10;
	item1.next = &item2;

	item2.value = 25;
	item2.next = NULL;
	
	printMemoryAddress(item1);
	printValue(item1.next->value);
	printMemoryAddress(item2);
	std::cin >> userInput; 
	return 0;
}

void printSize(int value)
{
	std::cout << "Size is: " << sizeof(value) << std::endl;
}

void printValue(int value)
{
	std::cout << "Value is: " << value << std::endl;
}

void printMemoryAddress(LinkedListItem item)
{
	std::cout << "Address is: " << &item << std::endl;
}