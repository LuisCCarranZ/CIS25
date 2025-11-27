#include <iostream>
#include <string>
#include <fstream>
#include "Item_Functions.h"

using namespace std;

void sortArrayByName(Item* arrInventory, int size) {
	// This sort the array of items by name
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arrInventory[i].name > arrInventory[j].name) {
				swap(arrInventory[i], arrInventory[j]);
			}
		}
	}

}

void assignIdItems(Item* arrInventory, int size) {
	// Assign IDs to items after sorting by name
	// This ensures each item's ID matches its position in the sorted array
	for (int i = 0; i < size; i++) {
		arrInventory[i].id = i;
	}
}

void loadFromFile(Item* arrInventory, string fileName, int size) {
	// Load up to size 100 items from the document named: "itemlist.txt"
	// Sort them by name
	// Assign them IDs numbers
	ifstream inFile(fileName);
	if (inFile.is_open()) {
		string fileLine;
		int indx = 0;
		while (getline(inFile, fileLine) && indx < size) {
			arrInventory[indx].name = fileLine;
			indx++;
		}
		inFile.close();
		sortArrayByName(arrInventory, size);
		assignIdItems(arrInventory, size);
	}
	else {
		cout << "Unable to open file." << endl;
	}
}

string binarySearch(Item* arrInventory, int idTarget, int size) {
	// Search for an item name using its ID number
	// It works with a sorted array
	int leftSide = 0;
	int rightSide = size - 1;
	while (leftSide <= rightSide) {
		int middleSide = (leftSide + rightSide) / 2;
		if (arrInventory[middleSide].id == idTarget) {
			return arrInventory[middleSide].name;
		}
		else if (arrInventory[middleSide].id < idTarget) {
			leftSide = middleSide + 1;
		}
		else {
			rightSide = middleSide - 1;
		}
	}
	return "";
}

void menu(Item* inventory, int size) {
	// User-friendly menu where user can choose to find a determined item
	// If item is not found, it prints "Item 'ID' has not been found"
	// If item is found, it prints the item 'name' and item ID.
	int itemIdtoFind;
	string itemFound;
	int choice;
	while (true) {
		cout << "\n===== INVENTORY MENU =====\n";
		cout << "1. Find an item by ID\n";
		cout << "2. Exit\n";
		cout << "============================\n";
		cout << "Select an option: ";
		cin >> choice;
		if (cin.fail() || (choice > 2 || choice < 1)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << "Invalid option! Try again.\n" << endl;
			continue;
		}
		if (choice == 1) {
			cout << "Insert the item ID: ";
			cin >> itemIdtoFind;
			if (cin.fail() || (choice > 2 || choice < 1)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cerr << "Invalid ID! Must be a number.\n" << endl;
				continue;
			}
			itemFound = binarySearch(inventory, itemIdtoFind, size);
			if (itemFound.empty()) {
				cout << "Item ID: " << itemIdtoFind << " not been found.\n";
			}
			else {
				cout << "Found: " << itemFound << " (ID : " << itemIdtoFind << ")\n";
			}
		}
		else if (choice == 2) {
			cout << "Exiting the program..." << endl;
			break;
		}

	}
}

int main() {
	int sizeArr = 100;
	string fileName = "itemlist.txt";
	Item* inventory = new Item[sizeArr];
	loadFromFile(inventory, fileName, sizeArr);
	menu(inventory, sizeArr);
	delete[] inventory;
	return 0;
}