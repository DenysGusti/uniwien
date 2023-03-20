#include <iostream>

using namespace std;

using ld = long double;

/*
Read in a number n and calculate the sum of all natural numbers <=n. (Problems?)
*/

int main() {
    uint64_t n{};  // unsigned long long
    cout << "n = ";
    cin >> n;
    cout << "\nsum of all natural numbers <= n = " << n * (n + 1) / 2 << '\n';
    return 0;
}

/*
Input:
n = 5

Output:
sum of all natural numbers <= n = 15
*/