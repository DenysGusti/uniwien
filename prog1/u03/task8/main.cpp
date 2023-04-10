#include <iostream>

using namespace std;

using ld = long double;

uint64_t task_sum(const uint64_t n) {
    uint64_t ans = 0, add_sum{};
    for (uint64_t i = 1; i <= n; ++i) {
        add_sum = i;
        for (uint64_t j = 1; j < i; ++j)
            add_sum *= i;
        ans += add_sum;
    }
    return ans;
}

/*
Determine the value sum (i. e. 1^1+2^2+3^3+,…,+n^n for any natural number n).
The use of mathematical functions (such as pow from cmath) is not allowed.
*/

int main() {
    uint64_t n{};
    cout << "n = ";
    cin >> n;
    cout << "sum = " << task_sum(n) << endl;
    return 0;
}

/*
Input:
n = 10

Output:
sum = 10405071317
*/