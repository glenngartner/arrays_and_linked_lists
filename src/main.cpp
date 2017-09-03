#include <iostream>
#include "linked_list_lib.hpp"
#include "LinkedList.h"
#include "interactivity.h"
#include <array>
#include <stdio.h>
#include "typeinfo"


int main() {
    bool restart = false;

    // begin the restart loop. run this at least once
    do {
        char userInput;
        bool keepPrompting = true;
        bool listIsGenerated = false;
        std::string stringInput;
        int autoGenListLength;
        std::vector<std::string> names;
        welcomeTitle();

        // create an empty pointer of LinkedList type. we'll initialize this later
        LinkedList *newList;
        int i = 0;
        while (listIsGenerated == false) {

            // ask what type of list the user wants
            printf(" Do you want to auto-generate a list(a), or make one yourself?(m)");

            // parse the user input, making sure they only enter 1 letter.
            std::cin >> stringInput;
            userInput = stringToChar(stringInput);
            bool valid = false;
            switch (userInput) {
                case 'a':
                    puts("I'm going to randomly generate some items for you");
                    while (valid == false) {

                        puts("How many do you want?");
                        prompt();
                        std::cin >> autoGenListLength;
                        valid = true;
                        if (std::cin.fail()) //cin.fail() checks to see if the value in the cin
                            //stream is the correct type, if not it returns true,
                            //false otherwise.
                        {
                            std::cin.clear(); //This corrects the stream.
                            std::cin.ignore(); //This skips the left over stream data.
                            std::cout << "\n\n   Please enter an Integer only.\n\n" << std::endl;
                            valid = false; //The cin was not an integer so try again.
                        }
                    }
                    // create some random values
                    for (int i = 0; i < autoGenListLength; i++) {
                        // create a random string number, instead of unique name
                        char randomModel = (int) 87;
                        std::string value = "droid_" + std::to_string(randomModel) + "_" + std::to_string(rand() % 100);
                        // read each value in the names vector
                        for (int i = 0; i < names.size(); i++) {
                            // if the random value (name) just generated matches the current value in the name vector
                            while (value == names[i]) {
                                printBillboard("Duplicate found. We can't have that. Changing...", '!', 45, true);
                                std::cout << "this name already existed: " << value << std::endl;
                                // generate a new name
                                value = "droid_model_" + std::to_string(rand() % 100);
                                std::cout << "Changed to: " << value << std::endl;
                            }
                        }
                        names.push_back(value);
                    }
                    listIsGenerated = true;
//                names = {"Carl", "Butch", "Mark", "Steve", "Harvey", "Rich"};
                    printf("\n   Making your list....\n\n");
                    break;
                case 'm':
                    listIsGenerated = true;

                    while (valid == false) {
                        puts("How many names do you want to enter?");
                        prompt();
                        std::cin >> autoGenListLength;
                        valid = true;
                        if (std::cin.fail()) //cin.fail() checks to see if the value in the cin
                            //stream is the correct type, if not it returns true,
                            //false otherwise.
                        {
                            std::cin.clear(); //This corrects the stream.
                            std::cin.ignore(); //This skips the left over stream data.
                            std::cout << "\n\n   Please enter an Integer only.\n\n" << std::endl;
                            valid = false; //The cin was not an integer so try again.
                        }
                    }
                    for (int i = 0; i < autoGenListLength; i++) {
                        printf("   Please enter a name, and press ENTER\n");
                        prompt();
                        std::cin >> stringInput;
                        // check for name duplicates
                        for (int i = 0; i < names.size(); i++) {
                            // if you find one, notify the user and request they enter a new one
                            // remain in this loop until they choose a unique one
                            while (stringInput == names[i]) {
                                puts("\n\n   You've already entered that name.");
                                puts("   Please provide a unique one\n\n");
                                prompt();
                                std::cin >> stringInput;
                            }
                        }
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
        while (keepPrompting) {
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
                case 'r':
                    // clear memory of existing objects
                    delete (newList);
                    stringInput = "";
                    userInput = 0;
                    // reset the app stage prompt loops
                    listIsGenerated = false;
                    keepPrompting = false;
                    restart = true;
                    break;
                case 'x':
                    keepPrompting = false;
                    restart = false;
                    break;
                case -1:
                    break;
                default:
                    printf("\n   sorry, that's not an option. try again\n");
                    break;
            }

        }
    } while (restart);

    return 0;
}