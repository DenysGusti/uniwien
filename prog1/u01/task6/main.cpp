#include <iostream>

using namespace std;

using ld = long double;

/*
Read in a number n and calculate the sum of all natural numbers <=n. (Problems?)
*/

int main() {
    uint64_t n{};
    cout << "n = ";
    cin >> n;
    cout << "\nsum of all natural numbers <= n = " << n * (n + 1) / 2 << '\n';
    return 0;
}
