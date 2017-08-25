#include <string>

struct LinkedListItem
{
	std::string name;
	int value;
	LinkedListItem *next;
};

void printSize(LinkedListItem value);

void printValue(LinkedListItem item);


void printMemoryAddress(LinkedListItem item);

LinkedListItem makeListItem(std::string name);

void linkItems(LinkedListItem first, LinkedListItem second);