#pragma once
#ifndef linked_list
#define linked_list

#include <vector>
#include <array>
#include <string>

struct LinkedListItem
{
	std::string name;
	int value;
	LinkedListItem *next;
};

void printSize(LinkedListItem value);

void printValue(LinkedListItem& item);

void printAllItemInfo(LinkedListItem *item);

void printLinkedMemoryAddress(LinkedListItem *item);

LinkedListItem makeListItem(std::string name);

void linkItems(LinkedListItem& first, LinkedListItem& second);

void printArrayIndexMemoryAddress(int index);

void printArrayIndicesMemoryAddresses(std::array<int, 4>& myArray);

void printDashedLine();

#endif // !linked_list
