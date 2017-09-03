//
// Created by glenn on 9/1/2017.
//

#include "interactivity.h"
#include "linked_list_lib.hpp"
#include <iostream>
#include <c++/sstream>

void prompt() {
    printf(" -->: ");
}

void printOptions() {
    printf("\n\n");
    printBorder('.', 35);
    printf("\n What next? Here're your options:\n\n");
    printf(" (p) print a list of item names\n");
    printf(" (v) print a list with all details\n");
    printf(" (H) add an item to the head\n");
    printf(" (T) add an item to the tail\n");
    printf(" (h) remove an item from the head\n");
    printf(" (t) remove an item from the tail\n");
    printf(" (n) remove an item by name\n");
    printf(" (r) restart & generate a new list\n");
    printf(" (x) exit the app\n");
    printBorder('.', 35);
    printf("\n");
    prompt();
}

void welcomeTitle() {
    printBillboard("Welcome to List Linker (version pre-maturely Alpha)", '#', 52, true);
}

void nameNewItem() {
    printf(" What would you like to name your new item?\n");
    prompt();
}

char stringToChar(std::string stringInput){
    char userInput;
    // parse the user input, making sure they only enter 1 letter.
    if (stringInput.length() != 1){
        printf("\n\n   One letter only, please.\n   Try again.\n\n");
        userInput = -1;
    } else {
        userInput = stringInput[0];
    }
    return userInput;
}

bool onlyInt(const char *output) {
        int check;
        std::string user_input;
//        std::cout<<output<<std::endl;
        while(1)
        {
            getline(std::cin,user_input);//gets user input as a string
            std::stringstream convert(user_input);//makes string into a stream
            if(convert >> check &&!(convert >> user_input))//checking for valid conversion and any rejects if any unconverted input left
            {
                return true;
            }
            else
            {
                std::cin.clear();
                std::cout<<"ERROR!\nwrong input\nPlease enter a NATURAL NUMBER only"<<std::endl;
                return false;
            }
        }
}
