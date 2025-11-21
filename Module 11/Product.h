#pragma once
#include <string>

class Product {
	int id;
	std::string name;
	double price;
public:
	Product(int, std::string, double);
	void printDetails();
	~Product();
};