#include <iostream>

using namespace std;

using ld = long double;

/*
(*) A beer mail order company sells kegs with a capacity of n liters each (n is a natural number).
Customers can order any quantity in whole litres.
Write a program that takes n and an order quantity and uses an expression to calculate the number of kegs needed.
Use of another statement (if, switch, loop) or conditional evaluation is not allowed.
*/

int main() {
    uint64_t n{}, l{};
    cout << "capacity and quantity, liters = ";
    cin >> n >> l;
    cout << (l + n - 1) / n << " kegs are needed\n";  // n - 1 slightly smaller than n, so it will round to bigger number but not when n divides l
	return 0;
}

/*
Input:
capacity and quantity, liters = 12 36

Output:
3 kegs are needed
*/