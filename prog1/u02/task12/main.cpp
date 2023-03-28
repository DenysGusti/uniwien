#include <iostream>

using namespace std;

using ld = long double;

/*
Read in two whole numbers and determine whether the last number entered is a factor of the number entered first.
E.g.: Input: 7 3 Output: 3 does not divide 7. Input: 15 5 Output: 5 divides 15.
*/

int main() {
	uint64_t n{}, m{};
	cout << "n, m = ";
	cin >> n >> m;
	cout << m << (n % m == 0 ? " divides " : " does not divide ") << n << ".\n";
	return 0;
}

/*
Input:
n, m = 7 3

Output:
3 does not divide 7.
*/