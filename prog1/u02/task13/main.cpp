#include <iostream>

using namespace std;

using ld = long double;

/*
(*) Write an expression (i.e. no statement or similar) that rounds a positive number x correctly (i.e. round up from 0.5 and down below).
*/

int64_t rounding(const ld x) {
    return x + 0.5;
}

int main() {
    ld x{};
    cout << "x = ";
    cin >> x;
    cout << rounding(x) << '\n';
    return 0;
}

/*
Input:
x = 4.5

Output:
5
*/