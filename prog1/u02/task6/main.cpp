#include <iostream>
#include <cmath>

using namespace std;

using ld = long double;

/*
Calculate ax²+bx+c using Horner's method for arbitrary inputs of a,b,c and x.
*/

const static int degree = 2;

int main() {
    ld x{}, c{}, result{}; // 3 variables
    cout << "x = ";
    cin >> x;

    for (int i = 0; i <= degree; ++i) {
        cout << '\n' << static_cast<char>('a' + i) << " = ";  // ax^2+bx+c
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

Output:
value of the polynomial at the point x (2) = 7
*/