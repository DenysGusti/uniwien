#include <iostream>
#include <array>

using namespace std;

using ld = long double;

/*
Write a program that calculates the probability of a jackpot (Lottosechser) using the Austrian lottery system (6 out of 45).
*/

void fill_combinations(array<array<uint64_t, 7>,  46> &c) {
    for (size_t i = 0; i < c.size(); ++i)
        c[i][0] = 1;

    for (size_t n = 1; n < c.size(); ++n)
        for (size_t k = 1; k < c[0].size(); ++k)
            c[n][k] = c[n - 1][k - 1] + c[n - 1][k];
}

int main() {
    array<array<uint64_t, 7>,  46> c{};
    fill_combinations(c);
    cout << "the probability of a jackpot = " << 1.L / c[6][45] << '\n';
    return 0;
}
