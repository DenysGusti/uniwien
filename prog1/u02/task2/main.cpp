#include <iostream>

using namespace std;

using ld = long double;

/*
Write a program that reads a three-digit number and uses the sum of the digits to check whether the entered number is divisible by 3.
*/

int main() {
    uint64_t n{}, mod{};
    cout << "a three-digit number = ";
    cin >> n;

    cout << n;
    for (; n; n /= 10)
        mod = (mod + n % 10) % 3;
    cout << " is " << (mod > 0 ? "not " : "") << "divisible by 3\n";
    return 0;
}

/*
Input:
a three-digit number = 456

Output:
456 is  divisible by 3
*/