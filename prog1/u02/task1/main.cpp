#include <iostream>

using namespace std;

using ld = long double;

/*
Write a program that reads two natural numbers m and n and prints the nth digit of the number m.
E.g.: m=1358 n=2 Output: 5 (The digits are counted from the decimal point.)
*/

int main() {
    uint64_t m{}, n{};
    cout << "m = ";
    cin >> m;
    cout << "\nn = ";
    cin >> n;
    for (uint64_t i = 0; i < n - 1; ++i)
        m /= 10;
    cout << "nth digit of the number m is " << m % 10 << '\n';
    return 0;
}

/*
Input:
m = 1358
n = 2

Output:
nth digit of the number m is 5
5
*/