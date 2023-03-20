#include <iostream>

using namespace std;

using ld = long double;

/*
(*) Read in a value x, as well as the coefficients of a fourth degree polynomial
and calculate the value of the polynomial at the position x.
Use a maximum of 3 variables with fundamental data type for this.
Also, perform a maximum of 4 multiplications in the calculation.
*/
const static int degree = 4;

int main() {
    ld x{}, c{}, result{}; // 3 variables
    cout << "x = ";
    cin >> x;

    for (int i = 0; i <= degree; ++i) {
        cout << '\n' << static_cast<char>('a' + i) << " = ";  // ax^4+bx^3+cx^2+dx+e
        cin >> c;
        result = !i ? c : result * x + c;  // Horner's method, for first iteration just c
    }

    cout << "\nvalue of the polynomial at the point x (" << x << ") = " << result << '\n';
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