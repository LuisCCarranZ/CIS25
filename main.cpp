#include "Items.h"

int main() {
	Item tool("items.txt");
	tool.name = "Screwdriver";
	tool.quantity = 10;
	tool.saveToFile();
	tool.name = "Hammer";
	tool.quantity = 15;
	tool.saveToFile();
	tool.loadFromFile();
	return 0;
}