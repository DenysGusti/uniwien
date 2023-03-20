#include <iostream>

using namespace std;

using ld = long double;

/*
Convert from Celsius to Fahrenheit.
*/

int main() {
    ld degrees{};
    cout << "degrees C = ";
    cin >> degrees;
    cout << "\ndegrees F = " << degrees * 1.8 + 32 << '\n';
    return 0;
}

/*
Input:
degrees C = 37

Output:
degrees F = 98.6
*/