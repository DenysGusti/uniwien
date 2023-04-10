#include <iostream>
#include <cmath>

using namespace std;

using ld = long double;

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

/*
A natural number is called almost perfect if the sum of its proper divisors
(that is, all divisors that are strictly smaller than the number itself) is one less than the number.
For example, 4 is almost perfect since 4=1*2*2 and 1+2=3=4-1. Find all almost perfect numbers in the range 0 to 10^7.
*/

int main() {
    // almost perfect numbers are powers of 2 (because sum of all divisors of 2^n equals to 2^n - 1)
    cout << "all almost perfect numbers in the range 0 to 10^7:\n";
    for (uint64_t i = 1; i <= 10'000'000;  i <<= 1)
        cout << i << ' ';

    cout << endl << "naive approach:\n";
    for (uint64_t i = 1; i <= 10'000'000; ++i)
        if (getAliquotSum(i) == i - 1)
            cout << i << ' ';
    return 0;
}

/*
Input:

Output:
all almost perfect numbers in the range 0 to 10^7:
1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152 4194304 8388608
naive approach:
1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152 4194304 8388608
*/