#include <iostream>
#include <string>
#include "Product.h"

using namespace std;

Product::Product(int i, string n, double p)
	: id(i), name(n), price(p) {
	cout << "Constructor has been called!" << endl; }

Product::~Product() {
	cout << "Destructor has been called!" << endl; }

void Product::printDetails() {
	cout << "Id: " << id << ", Name: " << name << ", Price: $" << price << endl;}