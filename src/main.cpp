#include <iostream>
#include "linked_list_lib.hpp"
#include "LinkedList.h"
#include "interactivity.h"
#include <array>

int main() {
    char userInput;
    bool exit;
    std::string stringInput;

    std::array<std::string, 6> names = {"Carl", "Butch", "Mark", "Steve", "Harvey", "Rich"};
    welcomeTitle();
    printf("\nMaking your list....\n\n");
    LinkedList *newList = new LinkedList(names, true);

    while (!exit) {
        printOptions();
        std::cin >> userInput;
        switch (userInput) {
            case 'p':
                newList->printList(false);
                break;
            case 'v':
                newList->printList(true);
                break;
            case 'H':
                nameNewItem();
                std::cin >> stringInput;
                newList->addItemToHeadByName(stringInput);
                break;
            case 'T':
                nameNewItem();
                std::cin >> stringInput;
                newList->addItemToTailByName(stringInput);
                break;
            case 'h':
                newList->removeItemFromHead();
                break;
            case 't':
                newList->removeItemFromTail();
                break;
            case 'x':
                exit = true;
                break;
            default:
                printf("\nsorry, that's not an option. try again\n");
                break;
        }

    }

//    newList->printList(false);
//    newList->addItemToTailByName("Duke");
//    newList->addItemToTailByName("Mike");
//    newList->removeItemFromTail();
//    newList->removeItemFromHead();
//    newList->addItemToHeadByName("Becky");
//    newList->removeListItemByName("Dirk");
//    newList->whoIsMyHead();
//    newList->printItemDetailsByName("Duke");

    return 0;
}