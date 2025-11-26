#include <iostream>
#include <string>
#include "function_loops.h"

using namespace std;

void displayItem(string arrInv[], int size) {
	if (size > 0) {
		cout << endl;
		for (int i = 0; i < size; i++) {
			cout << (i + 1) << ". Item name: " << arrInv[i] << endl;
		}
	}
	else {
		cout << "Inventory is empty." << endl;
		cout << endl;
	}
}

void addItem(string arrInv[], int &itemNReference, int limitSize) {
	//Notice int &itemNReference, it passes the item number by reference.
	//This allows the function to directly modify the integer in that location.
	//Function adds a new item to the array arrInv[]
	string itemName;
	if ((limitSize - itemNReference) > 0) {
		cout << "Insert the item name to add it to the inventory." << endl;
		cout << "Free slots " << (limitSize - itemNReference) << ": ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, itemName);
		arrInv[itemNReference] = itemName;
		itemNReference++;
		cout << "Item " << itemName << " added!\n";
		cout << endl;
	}
	else {
		cout << "No more free slots" << endl;
		cout << endl;
	}
}

char confirmExit(string arrInv[], int size) {
	char choice;
	while (true) {
		cout << "\nThe next items will be permanently deleted:" << endl;
		displayItem(arrInv, size);
		cout << "Are you sure that you want to exit (y/n)? ";
		cin >> choice;
		choice = tolower(choice);
		if (choice != 'y' && choice != 'n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Makes sure to select the correct option.." << endl;
			cout << endl;
			continue;
		}
		else if (choice == 'y' || choice == 'n') {
			return choice;
		}
	}
}

void menu() {
	int choice;
	int itemNumber = 0;
	string inventoryArr[10] = {};
	cout << "Welcome to PTC Inventory!" << endl;
	cout << endl;
	while (true) {
		cout << "What would you like to do (insert 1, 2, or 3)? " << endl;
		cout << "1. Add Item\n2. View Items\n3. Exit" << endl;
		cout << ">> ";
		cin >> choice;
		if (cin.fail() || (choice > 3 || choice < 1)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Something went wrong, please makes sure to choose from the given options." << endl;
			cout << endl;
			continue;
		}
		if (choice == 1) {
			addItem(inventoryArr, itemNumber, 10);
		}
		else if (choice == 2) {
			displayItem(inventoryArr, itemNumber);
		}
		else if (choice == 3) {
			if (confirmExit(inventoryArr, itemNumber) == 'y') {
				cout << "Items have been deleted." << endl;
				cout << "Closing the program.." << endl;
				break;
			}
		}

	}
}

int main() {
	menu();
	return 0;
}