//
// Created by glenn on 9/1/2017.
//

#include "interactivity.h"
#include "linked_list_lib.hpp"
#include <iostream>

void prompt() {
    printf(" -->: ");
}

void printOptions() {
    printf("\n\n");
    printBorder('.', 35);
    printf("\n What next? Here're your options:\n");
    printf(" (p) print a list of item names\n");
    printf(" (v) print a list with all details\n");
    printf(" (H) add an item to the head\n");
    printf(" (T) add an item to the tail\n");
    printf(" (h) remove an item from the head\n");
    printf(" (t) remove an item from the tail\n");
    printf(" (n) remove an item by name\n");
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
