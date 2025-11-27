#pragma once
#include <string>

struct Item {
	std::string name;
	int id;
};

void sortArrayByName(Item* arrInventory, int size);

void assignIdItems(Item* arrInventory, int size);

void loadFromFile(Item* arrInventory, std::string fileName, int size);

std::string binarySearch(Item* arrInventory, int idTarget, int size);

void menu(Item* inventory, int size);

