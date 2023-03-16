#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

using ld = long double;

/*
Read in a radius r and an angle a and calculate the area of the circular sector defined by r and a.
*/

int main() {
    ld r{}, a{};
    cout << "r, a in degrees = ";
    cin >> r >> a;
    a *= M_PI / 180;
    cout << "\narea of the circular sector = " << r * r / 2 * a << '\n';
    return 0;
}
