#include <iostream>

using namespace std;

using ld = long double;

/*
Read a double number and determine whether the user entered an integer or not.
E.g.: Input: 3.7 Output: Not an integer. Input:5 Output: An integer.
*/

int main() {
    double n{};
    cout << "n = ";
    cin >> n;
    cout << (n - static_cast<int>(n) == 0 ? "An" : "Not an") << " integer.\n";
    return 0;
}

/*
Input:
n = 3.0

Output:
An integer.
*/