//
// Created by Glenn P. Gartner on 9/1/17.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "linked_list_lib.hpp"
#include "string"


class LinkedList {
public:
    LinkedList(std::array<std::string, 6> &names, bool verbose);

    LinkedListItem* firstItem;

    void whoIsMyHead();

    int printListLength();

    void printList(bool verbose);

    void addItemToTailByName(std::string name);

    void removeItemFromTail();

    LinkedListItem* removeItemFromHead();

    void removeListItemByName(std::string nameOfItemToRemove);

    void addItemToHeadByName(std::string newItemName);
};


#endif //LINKED_LIST_H
