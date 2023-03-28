#include <iostream>

using namespace std;

using ld = long double;

/*
A beer mail order company sells kegs with a capacity of n liters each. Customers can order any quantity in whole litres.
Write a program that takes n and an order quantity and calculates the number of kegs needed. (Use of an if statement is allowed.)
*/

int main() {
	uint64_t n{}, l{};
	cout << "capacity and quantity, liters = ";
	cin >> n >> l;
	cout << l / n + (l % n ? 1 : 0)  << " kegs are needed\n";
	return 0;
}

/*
Input:
capacity and quantity, liters = 12 45

Output:
4 kegs are needed
*/