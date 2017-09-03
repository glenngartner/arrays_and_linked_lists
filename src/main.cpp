#include <iostream>
#include "linked_list_lib.hpp"
#include "LinkedList.h"
#include "interactivity.h"
#include <array>
#include "typeinfo"


int main() {
    char userInput;
    bool run = true;
    bool listIsGenerated = false;
    std::string stringInput;
    int autoGenListLength;

//    std::array<std::string, 6> names;
    std::vector<std::string> names;
    welcomeTitle();

    // create an empty pointer of LinkedList type. we'll initialize this later
    LinkedList *newList;
    int i = 0;
    while (listIsGenerated == false) {

        // ask what type of list the user wants
        printf(" Do you want to auto-generate a list(a), or make one yourself?(m)");

        // parse the user input, making sure they only enter 1 letter.
        std::getline(std::cin, stringInput);
        userInput = stringToChar(stringInput);
        switch (userInput) {
            case 'a':
                puts("I'm going to randomly generate some items for you");
                puts("How many do you want?");
                std::cin >> autoGenListLength;
                // create some random values
                for (int i = 0; i < autoGenListLength; i++) {
                    std::string value = std::to_string(100 * rand());

                    names.push_back(value);
                }
                listIsGenerated = true;
//                names = {"Carl", "Butch", "Mark", "Steve", "Harvey", "Rich"};
                printf("\n   Making your list....\n\n");
                break;
            case 'm':
                listIsGenerated = true;
                puts("How many names do you want to enter?");
                prompt();
                std::cin >> autoGenListLength;
                for (int i = 0; i < autoGenListLength; i++) {
                    printf("   Please enter a name, and press ENTER\n");
                    prompt();
                    std::cin >> stringInput;
                    names.push_back(stringInput);
                }
                break;
            case -1:
                break;
            default:
                printf("\n   That's not an option. Please try again\n\n");
                break;
        }
    }
    // create the new LinkedList object
    newList = new LinkedList(names, true);

    // while the program should run
    while (run) {
        printOptions();
        std::cin >> stringInput;
        userInput = stringToChar(stringInput);
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
                printf("   Which name do you want to remove?");
                prompt();
                std::cin >> stringInput;
                newList->removeListItemByName(stringInput);
                break;
            case 'x':
                run = false;
                break;
            case -1:
                break;
            default:
                printf("\n   sorry, that's not an option. try again\n");
                break;
        }

    }

    return 0;
}