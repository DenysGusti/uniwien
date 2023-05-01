#include <iostream>

using namespace std;

uint64_t A(const uint64_t m, const uint64_t n) {
    if (m == 0)
        return n + 1;
    if (n == 0)
        return A(m - 1, 1);
    return A(m - 1, A(m, n - 1));
}

/*
The Ackermann function A(m,n) is defined for natural numbers m and n as:
A(m, n) =
{
    n + 1                   if m=0
    A(m - 1, 1)             if m > 0 and n = 0
    A(m - 1, A(m, n - 1))   if m > 0 and n > 0
}
Write a function that takes two integer parameters and returns the appropriate value of the Ackerman function.
*/

int main() {
    int64_t m{}, n{};
    cout << "m, n = ";
    cin >> m >> n;
    cout << "A(" << m << ", " << n << ") = " << A(m, n) << endl;
    return 0;
}

/*
Input:
m, n = 3 4

Output:
A(3, 4) = 125
*/