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

void printValue(LinkedListItem *item);

void printAllItemInfo(LinkedListItem *item);

void printLinkedMemoryAddress(LinkedListItem *item);

LinkedListItem * makeListItem(std::string name);

void linkItems(LinkedListItem* first, LinkedListItem* second);

void printArrayIndexMemoryAddress(int value, std::string name, unsigned int index);

void printArrayIndicesMemoryAddresses(std::array<int, 4> &myArray, std::string name);

void printDashedLine();

int listLength(LinkedListItem *firstItem);

void printEntireList(LinkedListItem *firstItem);

void addToTail(LinkedListItem *firstItem, LinkedListItem *newItem);

void removeTail(LinkedListItem *firstItem);

LinkedListItem* removeHead(LinkedListItem *firstItem);

LinkedListItem* lastListItem(LinkedListItem *firstItem);

void addToHead(LinkedListItem *firstItem, LinkedListItem *newFirstItem);

void createLinkedList(LinkedListItem *firstItem, std::array<std::string, 6> &names, bool verbose);

#endif // !linked_list
