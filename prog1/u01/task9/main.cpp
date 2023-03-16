#include <iostream>

using namespace std;

using ld = long double;

/*
x grams of hydrogen are to be burned.
Read in x and calculate how many grams of oxygen are required for the reaction and how many milliliters of water are produced.
*/

int main() {
    ld x{};
    cout << "x grams = ";
    cin >> x;
    cout << x * 8 << " grams of oxygen are required for the reaction\n" << x * 9 << " milliliters of water are produced\n";
    return 0;
}
