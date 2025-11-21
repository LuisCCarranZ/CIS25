#pragma once
#include <string>

using namespace std;

class Item {
	string fileName;
public:
	Item(string newName) : fileName(newName) {}
	string name;
	int quantity;
	void saveToFile();
	void loadFromFile();
};
