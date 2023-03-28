#include <iostream>

using namespace std;

using ld = long double;

/*
Write a program that reads a three-digit number and returns the number obtained by reversing the sequence of digits.
E.g.: Input: 123 Output: 321
*/

int main() {
    uint64_t n{}, mod{};
    cout << "a three-digit number = ";
    cin >> n;

    cout << "\nreversed = ";
    for (; n; n /= 10)
        cout << n % 10;
    cout << '\n';
    return 0;
}

/*
Input:
a three-digit number = 123

Output:
reversed = 321
*/