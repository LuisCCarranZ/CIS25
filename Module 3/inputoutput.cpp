#include <iostream>
#include <string>

using namespace std;

void looping() {
	string itemName;
	double itemPrice;
	int itemAmount;
	char userAnswer;
	do {
		cout << "Checking total cost of a new item:\n";
		cout << "Enter item name:\t";
		cin >> itemName;
		cout << "Enter item price:\t";
		cin >> itemPrice;
		cout << "Enter item quantity:\t";
		cin >> itemAmount;

		cout << "Item " << itemName << " has a total price of $" << (itemPrice * itemAmount) << endl;
		cout << endl;
		cout << "Would you like to check another item (y/n)? ";
		cin >> userAnswer;
		if (cin.fail() || (tolower(userAnswer) != 'y' && tolower(userAnswer) != 'n')) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Choice inserted is not allowed..." << endl;
			cout << "Closing the program..." << endl;
		}
	} while (userAnswer == 'y' && userAnswer != 'n');
}

int main() {
	looping();
	cout << "Good bye!" << endl;
	return 0;
}