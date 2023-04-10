#include <iostream>
#include <string>
#include <complex>

using namespace std;

using ld = long double;

/*
Write a program to solve the quadratic equation x²+px+q=0 (caution: watch out for possible complex solutions).
Note: The cmath library contains the sqrt() function, which is used to calculate the square root.
The passed value should not be less than 0 (zero), otherwise an error will be raised.
*/

template<class T>
ostream& operator<<(ostream& out, const complex<T> &n) {
    if (n.real()) out << n.real();
    if (n.imag()) out << showpos << n.imag() << noshowpos << 'i';
    return out;
}

int main() {
    ld p{}, q{};
    cout << "x^2+px+q=0\nenter p, q: ";
    cin >> p >> q;
    auto D = sqrt(complex{p * p - 4 * q});
    cout << "x1, x2 = " << (-p - D) / 2.l << ", " << (-p + D) / 2.l << '\n';
    return 0;
}

/*
Input:
enter p, q: 4 5

Output:
x1, x2 = -2-1i, -2+1i
*/