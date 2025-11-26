#pragma once
#include <string>

// Display items in the inventory
void displayItem(std::string arrInv[], int size);

// Add a new item to the inventory
void addItem(std::string arrInv[], int& itemNReference, int limitSize);

// This let's you confirm if the you want to exit the program
char confirmExit(std::string arrInv[], int size);

// This is the interactive menu.
void menu();