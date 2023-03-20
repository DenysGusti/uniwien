#include <iostream>
#include <array>
#include <cmath>

using namespace std;

using ld = long double;

/*
Read in a value x, and the coefficients of a fourth degree polynomial, and calculate the value of the polynomial at the point x.
*/

const static size_t degree = 4;

int main() {
    ld x{};
    cout << "x = ";
    cin >> x;
    array<ld, degree + 1> coefficients{};  // array of coefficients
    for (size_t i = 0; i < coefficients.size(); ++i) {
        cout << '\n' << static_cast<char>('a' + i) << " = ";  // ax^4+bx^3+cx^2+dx+e
        cin >> coefficients[i];
    }

    ld ans{};
    for (size_t i = 0; i < coefficients.size(); ++i)
        ans += coefficients[i] * pow(x, coefficients.size() - 1 - i);

    cout << "\nvalue of the polynomial at the point x (" << x << ") = " << ans << '\n';
    return 0;
}

/*
Input:
x = 2
a = 1
b = 1
c = 1
d = 1
e = 1

Output:
value of the polynomial at the point x (2) = 31
*/