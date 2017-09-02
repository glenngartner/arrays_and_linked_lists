#include <iostream>
#include <string>
#include <array>
#include "linked_list_lib.hpp"

LinkedListItem *makeListItem(std::string name) {
    LinkedListItem *item = new LinkedListItem;
    item->name = name;
    item->value = rand() % 100;
    item->next = nullptr;
    return item;
}

void printAllItemInfo(LinkedListItem *item) {
    std::cout << item->name
              << " >> address: " << item
              << " | size: " << sizeof(*item)
              << " | value: " << item->value
              << " | neighbor: " << neighbor(item)
              << std::endl;
}

void linkItems(LinkedListItem *first, LinkedListItem *second) {
    first->next = second;
}

void printSize(LinkedListItem item) {
    std::cout << item.name << "'s size is: " << sizeof(item) << std::endl;
}


std::string neighbor(LinkedListItem *item) {
    if (item->next == nullptr) {
        return " <none> (it's null)";
    } else {
        return item->next->name;
    }
}

void printValue(LinkedListItem *item) {
    std::cout << item->name << "'s value is: " << item->value << std::endl;
}

void printLinkedMemoryAddress(LinkedListItem *item) {
    std::cout << item->name << "'s Address is: " << item << std::endl;
}

void printArrayIndexMemoryAddress(int value, std::string name, unsigned int index) {
    std::cout << name << "[" << index << "] address: " << &value << std::endl;
}

void printArrayIndicesMemoryAddresses(std::array<int, 4> &myArray, std::string name) {
    for (int i = 0; i < myArray.size(); i++) {
        printArrayIndexMemoryAddress(myArray[i], name, i);
    }
    printDashedLine();
}

void printDashedLine() {
    std::cout << "--------------------------------" << std::endl;
}

void createLinkedList(LinkedListItem *firstItem, std::array<std::string, 6> &names, bool verbose) {
    std::array<LinkedListItem *, 6> tempListItemArray;
    tempListItemArray[0] = firstItem;
    for (int i = 1; i < names.size(); i++) // start the loop at 1, since we've already created the first item
    {
        LinkedListItem *newItem = makeListItem(names[i]); // make a new list item
        tempListItemArray[i] = newItem; // store the address of the new item in the temporary array
        linkItems(tempListItemArray[i - 1], tempListItemArray[i]); // link this list item to the previous item

        if (verbose) {
            std::cout << names[i - 1] << " was created and linked to " << names[i] << std::endl;
        }

    }
    printDashedLine();
}

int listLength(LinkedListItem *firstItem) {
    unsigned int length = 1; // starts at 1, since we always have 1 item (the function argument)
    LinkedListItem *itemInScope = firstItem;
    while (itemInScope->next != nullptr) {
        length++;
        itemInScope = itemInScope->next;
    }
    return length;
}

LinkedListItem *lastListItem(LinkedListItem *firstItem) {
    LinkedListItem *itemInScope = firstItem;
    while (itemInScope->next != nullptr) {
        itemInScope = itemInScope->next;
    }
    return itemInScope;
}

void printEntireList(LinkedListItem *firstItem) {
    printBillboard("Full List With Details", '#', 25, true);
    LinkedListItem *itemInScope = firstItem;
    while (itemInScope->next != nullptr) {
        printAllItemInfo(itemInScope);
        itemInScope = itemInScope->next;
    }
    printAllItemInfo(itemInScope);
}

void addToTail(LinkedListItem *firstItem, LinkedListItem *newItem) {
    if (verifyNameExistsInList(firstItem, newItem->name)) {
        printf("\n\nSorry, that name already exists. Try another one\n\n");
    } else {
        LinkedListItem *lastItem = lastListItem(firstItem);
        linkItems(lastItem, newItem);
        LinkedListItem *newLastItem = lastListItem(firstItem);
        printBillboard("New item added to the end of the list", '+', 50, true);
        printAllItemInfo(newItem);
        std::cout << lastItem->name << " was the last in the list.\nNow his new neighbor is " << newLastItem->name
                  << std::endl;
        std::cout << newLastItem->name << " is now last in the list" << std::endl;
    }
}

void removeTail(LinkedListItem *firstItem) {

    printBillboard("Deleted the last item in the list", 'x', 40, true);

    if (firstItem->next == nullptr) {
        printf("There's only one item in the list, so I'm deleting nothing\n");
        printf("Your list is unchanged\n");
    } else {
        LinkedListItem *currentItem = firstItem;
        while (currentItem->next->next != nullptr) {
            currentItem = currentItem->next;
        }
        std::string nameToDelete = currentItem->next->name;
        delete currentItem->next;
        currentItem->next = nullptr;
        std::cout << nameToDelete << " has been deleted" << std::endl;

        LinkedListItem *newLastItem = lastListItem(firstItem);
        std::cout << newLastItem->name << " is now the last in the list" << std::endl;
    }
}

LinkedListItem *removeHead(LinkedListItem *firstItem) {
    printBillboard("Deleting the first item in the list", 'x', 40, true);
    LinkedListItem *secondItem = firstItem->next;
    std::cout << firstItem->name << " was deleted from the beginning of the list" << std::endl;
    delete firstItem;
    std::cout << secondItem->name << " is now the first item in the list" << std::endl;
    printf("\n");
    return secondItem;
}

void addToHead(LinkedListItem *firstItem, LinkedListItem *newFirstItem) {
    if (verifyNameExistsInList(firstItem, newFirstItem->name)) {
        printf("\n\nSorry, that name already exists. Try another one\n\n");
    } else {
        printBillboard("Added new item to the head of the list.", '+', 50, true);
        linkItems(newFirstItem, firstItem);
        std::cout << newFirstItem->name << " was added to the front of the list" << std::endl;
        printAllItemInfo(newFirstItem);
        printf("Print the list to see the new changes\n");
    }
}

void printBillboard(std::string text, char borderCharacter, unsigned int borderLength, bool blankLineSandwich) {
    if (blankLineSandwich) {
        printf("\n");
    }
    printBorder(borderCharacter, borderLength);
    printf("\n");
    std::cout << text;
    printf("\n");
    printBorder(borderCharacter, borderLength);
    if (blankLineSandwich) {
        printf("\n\n");
    }
}

void printBorder(char borderCharacter, unsigned int borderLength) {
    for (int i = 1; i <= borderLength; i++) {
        std::cout << borderCharacter;
    }
}

void removeItemByName(LinkedListItem *firstItem, std::string nameOfItemToRemove) {
    // first, verify the name exists
    if (verifyNameExistsInList(firstItem, nameOfItemToRemove)) {
        // return the item pointer, by searching for its name
        LinkedListItem *item = findItemByName(firstItem, nameOfItemToRemove);
        if (firstItem->name !=nameOfItemToRemove) { // if you're deleting the list head, there's no previous item
            // find the previous item, if one exists
            LinkedListItem *previousItem = findNeighborInFront(firstItem, nameOfItemToRemove);
            linkItems(previousItem, item->next);
            printBillboard("Deleted an item from the list", 'x', 40, true);
            std::cout << item->name << " was deleted from the list" << std::endl;
            if (item->next != nullptr) {
                std::cout << previousItem->name << " is now linked to " << item->next->name << std::endl;
            } else {
                std::cout << previousItem->name << " is not linked to anyone (it's last in the list) " << std::endl;
            }
        } else {
            printBillboard("Deleted an item from the list", 'x', 40, true);
            std::cout << item->name << " was deleted from the list" << std::endl;
        }
        printf("\n");
        delete (item);
    } else {
        printf("\nThat name doesn't exist. Please try another\n");
    }
}

LinkedListItem *findItemByName(LinkedListItem *firstItem, std::string nameOfItemToFind) {
    LinkedListItem *currentItem = firstItem;
    // verify the name exists, first. if so, return a pointer to the item
    if (verifyNameExistsInList(firstItem, nameOfItemToFind)) {
        while (currentItem->name != nameOfItemToFind) {
            currentItem = currentItem->next;
        }

        return currentItem;
    } else {
        return nullptr; // that name doesn't exist, so return a nullptr
    }
}

LinkedListItem *findNeighborInFront(LinkedListItem *firstItem, std::string inFrontOfThisName) {
    LinkedListItem *currentItem = firstItem;
    while (currentItem->next->name != inFrontOfThisName) {
        currentItem = currentItem->next;
    }
    return currentItem;
}

void printListNamesOnly(LinkedListItem *firstItem) {
    LinkedListItem *currentItem = firstItem;
    printBillboard("Full list by names", '=', 20, true);
    while (currentItem->next != nullptr) {
        std::cout << currentItem->name << std::endl;
        currentItem = currentItem->next;
    }
    std::cout << currentItem->name << std::endl;
}

bool verifyNameExistsInList(LinkedListItem *firstItem, std::string nameToFind) {
    LinkedListItem *currentItem = firstItem;
    while (currentItem->name != nameToFind) {
        if (currentItem->next == nullptr) {
            if (currentItem->name != nameToFind) {
//                std::cout << nameToFind << " wasn't found in the list" << std::endl;
                return false;
            }
            break;
        }
        currentItem = currentItem->next;
    }
    if (currentItem->name == nameToFind) {
//        std::cout << nameToFind << " was found in the list" << std::endl;
        return true;
    }
}

