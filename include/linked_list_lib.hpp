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

std::string neighbor(LinkedListItem *item);

void printAllItemInfo(LinkedListItem *item);

void printLinkedMemoryAddress(LinkedListItem *item);

LinkedListItem * makeListItem(std::string name);

void linkItems(LinkedListItem* first, LinkedListItem* second);

void printArrayIndexMemoryAddress(int value, std::string name, unsigned int index);

void printArrayIndicesMemoryAddresses(std::array<int, 4> &myArray, std::string name);

void printDashedLine();

int listLength(LinkedListItem *firstItem);

void printEntireList(LinkedListItem *firstItem);

void printListNamesOnly(LinkedListItem *firstItem);

void addToTail(LinkedListItem *firstItem, LinkedListItem *newItem);

void removeTail(LinkedListItem *firstItem);

void printBillboard(std::string text, char borderCharacter, unsigned int borderLength, bool blankLineSandwich);

void printBorder(char borderCharacter, unsigned int borderLength);

LinkedListItem* removeHead(LinkedListItem *firstItem);

LinkedListItem* lastListItem(LinkedListItem *firstItem);

void removeItemByName(LinkedListItem *firstItem, std::string nameOfItemToRemove);

LinkedListItem *findItemByName(LinkedListItem *firstItem, std::string nameOfItemToFind);

LinkedListItem *findNeighborInFront(LinkedListItem *firstItem, std::string inFrontOfThisName);

void addToHead(LinkedListItem *firstItem, LinkedListItem *newFirstItem);

void createLinkedList(LinkedListItem *firstItem, std::vector<std::string> &names, bool verbose);

bool verifyNameExistsInList(LinkedListItem *firstItem, std::string nameToFind);

#endif // !linked_list
