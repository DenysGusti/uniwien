#include <iostream>
#include <array>

using namespace std;

using ld = long double;

/*
Write a program that calculates the probability of a jackpot (Lottosechser) using the Austrian lottery system (6 out of 45).
*/

void fill_combinations(array<array<uint64_t, 7>,  46> &c) {
    // working with floating-point arithmetic gives errors, factorials are too big, so I use dynamic programming, filling Pascal's triangle
    for (size_t i = 0; i < c.size(); ++i)
        c[i][0] = 1;

    for (size_t n = 1; n < c.size(); ++n)
        for (size_t k = 1; k < c[0].size(); ++k)
            c[n][k] = c[n - 1][k - 1] + c[n - 1][k];
}

int main() {
    array<array<uint64_t, 7>,  46> c{}; // array of combinations, C[n][k] = n!/(k!*(n-k)!)
    fill_combinations(c);

    // for (size_t i = 0; i < c.size(); ++i) {
    //     for (size_t j = 0; j < c[0].size(); ++j)
    //         cout << c[i][j] << '\t';
    //     cout << '\n';
    // }

    cout << "the probability of a jackpot = " << 100.L / c[45][6] << "%\n";  // L for long double
    return 0;
}

/*
Input:

Output:
the probability of a jackpot = 1.22774e-05%
*/