#include <iostream>
#include <string>
#include "Product.h"

using namespace std;

int main() {
	Product p1(9137, "Laptop", 997.99);
	Product p2(1465, "Cellphone", 650.95);
	Product p3(6390, "Television", 1000.30);
	p1.printDetails();
	p2.printDetails();
	p3.printDetails();
	return 0;
}