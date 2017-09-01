//
// Created by Glenn P. Gartner on 9/1/17.
//

#include "LinkedList.h"
#include "linked_list_lib.hpp"
#include <iostream>
#include <string>

LinkedList::LinkedList(std::array<std::string, 6> &names, bool verbose)
{
    LinkedList::firstItem = makeListItem(names[0]);
    createLinkedList(LinkedList::firstItem, names, verbose);
}

void LinkedList::printList(bool verbose) {
    if(verbose){
        printEntireList(LinkedList::firstItem);
    } else {
        printListNamesOnly(LinkedList::firstItem);
    }
}

void LinkedList::addItemToTailByName(std::string name) {
    LinkedListItem *newItem = makeListItem(name);
    addToTail(LinkedList::firstItem, newItem);
}

void LinkedList::removeItemFromTail() {
    removeTail(LinkedList::firstItem);
}

LinkedListItem* LinkedList::removeItemFromHead() {
    LinkedList::firstItem = removeHead(LinkedList::firstItem);
}

void LinkedList::addItemToHeadByName(std::string newItemName) {
    LinkedListItem *newFirstItem = makeListItem(newItemName);
    addToHead(LinkedList::firstItem, newFirstItem);
    LinkedList::firstItem = newFirstItem;
}

int LinkedList::printListLength() {
    listLength(LinkedList::firstItem);
}

void LinkedList::removeListItemByName(std::string nameOfItemToRemove) {
    removeItemByName(LinkedList::firstItem, nameOfItemToRemove);
}

void LinkedList::whoIsMyHead() {
    std::string name = LinkedList::firstItem->name + " is my head";
    printBillboard(name, '=', 20, true);
}

void LinkedList::printItemDetailsByName(std::string name) {
    LinkedListItem* item = findItemByName(LinkedList::firstItem, name);
    std::string printString= "Details on " + item->name;
    printBillboard(printString, 'o', 25, true);
    printAllItemInfo(item);
}