#include <iostream>

using namespace std;

using ld = long double;

bool checkCollatzConjectureFor(uint64_t n) {
    while (n > 1) n = (!(n & 1) ? n : (3 * n + 1)) >> 1;
    return true;
} 

/*
Check if the sequence
n[i+1] = n[i]/2 for even n[i]
n[i+1] = 3n[i]+1 for odd n[i]
always reaches the value 1 for different (arbitrary) positive starting values n[0].
*/

int main() {
    uint64_t n{};
    cout << "enter n[0]: ";
    cin >> n;
    cout << "the sequence has reached 1: " << boolalpha << checkCollatzConjectureFor(n) << '\n';
    return 0;
}

/*
Input:
enter n[0]: 989345275647
the sequence has reached 1: true

Output:
the sequence has reached 1: true
*/