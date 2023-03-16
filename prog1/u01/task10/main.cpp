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
    array<ld, degree + 1> coefficients{};
    for (size_t i = 0; i < coefficients.size(); ++i) {
        cout << '\n' << static_cast<char>('a' + i) << " = ";
        cin >> coefficients[i];
    }

    ld ans{};
    for (size_t i = 0; i < coefficients.size(); ++i)
        ans += coefficients[i] * pow(x, coefficients.size() - i - 1);

    cout << "\nvalue of the polynomial at the point x (" << x << ") = " << ans << '\n';
    return 0;
}
