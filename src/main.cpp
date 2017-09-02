#include <iostream>
#include "linked_list_lib.hpp"
#include "LinkedList.h"
#include "interactivity.h"
#include <array>

int main() {
    char userInput;
    bool run = true;
    bool autoGenerateList;
    std::string stringInput;

    std::array<std::string, 6> names = {"Carl", "Butch", "Mark", "Steve", "Harvey", "Rich"};
    welcomeTitle();

    // create an empty pointer of LinkedList type
    LinkedList *newList;

    while (autoGenerateList == NULL) {

        // ask what type of list the user wants
        printf("Do you want to auto-generate (a) a list, or make one yourself?(m)");
        std::cin >> userInput;
//        userInput == 'a' ? autoGenerateList = true : autoGenerateList = false;
        switch (userInput) {
            case 'a':
                autoGenerateList = true;
                printf("\nMaking your list....\n\n");
                newList = new LinkedList(names, true);
                break;
            case 'm':
                autoGenerateList = false;
                printf("Please enter your own names");
                std::cin >> stringInput;
                newList = new LinkedList(names, true);
                break;
            default:
                printf("\nThat's not an option. Please try again\n\n");
        }
    }

    // while the program should run (not run)
    while (run) {
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
            case 'n':
                printf("Which name do you want to remove?");
                prompt();
                std::cin >> stringInput;
                newList->removeListItemByName(stringInput);
                break;
            case 'x':
                run = false;
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