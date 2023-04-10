#include <iostream>

using namespace std;

using ld = long double;

uint64_t fact(const uint64_t n) {
    uint64_t result = 1;
    for (uint64_t i = 2; i <= n; ++i) result *= i;
    return result;
}

/*
Calculate the factorial of n (n!) using a loop.
*/

int main() {
    uint64_t n{};
    cout << "n = ";
    cin >> n;
    cout << n << "! = " << fact(n) << '\n';
    return 0;
}

/*
Input:
n = 10

Output:
10! = 3628800
*/