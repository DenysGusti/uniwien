#include <iostream>

using namespace std;

using ld = long double;

uint64_t getPower2(const uint64_t n) {
    uint64_t pow2 = 1;
    for (; !(n % (pow2 * 2)); pow2 *= 2);
    return pow2;
}

/*
Write a program that reads a natural number and returns the largest power of two that divides the read number.

Input       Output
17          1
48          16
1024        1024
*/

int main() {
    for (uint64_t n{}; cin >> n;)
        cout << getPower2(n) << endl;
    return 0;
}

/*
Input:
17
48
1024

Output:
1
16
1024
*/