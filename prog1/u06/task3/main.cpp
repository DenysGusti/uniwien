#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
Write a function that takes a natural number n as a parameter and returns a vector containing all prime numbers < = n. Use the Sieve of Erathostenes to find the prime numbers.
*/

vector<uint64_t> sieveOfEratosthenes(const uint64_t n) {
    if (n <= 1)
        return {};
    vector<bool> a(n - 1, true);
    uint64_t sqrt_n = ceil(sqrt(static_cast<long double>(n)));
    for (size_t i = 2; i <= sqrt_n; ++i)
        if (a[i - 2])
            for (size_t j = i; i * j <= n; ++j)
                a[i * j - 2] = false;
    vector<uint64_t> res;
    res.reserve(a.size());
    for (size_t i = 0; i < a.size(); ++i)
        if (a[i])
            res.push_back(i + 2);
    return res;
}

int main() {
    uint64_t n{};
    cout << "n = ";
    cin >> n;
    for (const auto el: sieveOfEratosthenes(n))
        cout << el << ' ';
    cout << endl;
    return 0;
}

/*
Input:
n = 100

Output:
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
*/