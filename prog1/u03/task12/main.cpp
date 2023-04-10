#include <iostream>
#include <cmath>

using namespace std;

using ld = long double;

/*
A natural number is called perfect if the sum of its proper divisors
(that is, all divisors that are strictly smaller than the number itself) is the same as the number.
For example, 6 is a perfect number since 6=1*2*3 and 1+2+3=6. If the sum of the proper divisors is less than the number,
the number is said to be deficient. If the sum of the proper divisors is greater than the number, the number is called abundant.
Write a program that reads a natural number and returns whether the number read is perfect, deficient, or abundant.
(The reason given here is not part of the output.)

Input   Output      Reason
5       deficient   1 is the only proper divisor
6       perfect     1+2+3=6
12      abundant    1+2+3+4+6=16>12
*/

uint64_t getAliquotSum(const uint64_t n) {
    if (n == 1)
        return 0;
    uint64_t sum_of_divisors = 1;
    const uint64_t sqrt_n = sqrt(static_cast<ld>(n));
    for (uint64_t i = 2; i <= sqrt_n; ++i)
        if (n % i == 0) {
            sum_of_divisors += i;
            if (i * i != n)
                sum_of_divisors += n / i;
        }
    return sum_of_divisors;
}

int main() {
    uint64_t n{};
    cout << "n = ";
    cin >> n;
    auto aliquotSum = getAliquotSum(n);
    cout << (aliquotSum == n ? "perfect" : (aliquotSum < n ? "deficient" : "abundant")) << endl;
    return 0;
}

/*
Input:
n = 2305843008139952128

Output:
perfect
*/