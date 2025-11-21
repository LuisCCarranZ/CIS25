#include <iostream>
#include <fstream>
#include <string>
#include "Items.h"

using namespace std;

	void Item::saveToFile() {
		ofstream outFile(fileName, ios::app);
		if (outFile.is_open()) {
			outFile << "Item: " << name << ", Amount: " << quantity << endl;
			outFile.close();
			cout << "The item " << name << " saved succesfully to file." << endl;
		}
		else {
			cout << "Unable to open file." << endl;
		}
	}
	void Item::loadFromFile() {
		ifstream inFile(fileName);
		if (inFile.is_open()) {
			string fileLine;
			while (getline(inFile, fileLine)) {
				cout << fileLine << endl;
			}
			inFile.close();
		}
		else {
			cout << "Unable to open file." << endl;
		}
	}