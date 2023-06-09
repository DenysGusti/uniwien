#include <iostream>

using namespace std;

using ld = long double;

/*
(*) Read in five measured values of a test series and determine the mean value. Use a maximum of 2 variables with fundamental data type for this.
*/
const static int n = 5;

int main() {
    ld mean{}, test{};
    for (int i = 0; i < n; ++i) {
        cout << "\na[" << i << "] = ";
        cin >> test;
        mean += test / n;
    }
    cout << "\nthe mean value = " << mean << '\n';
    return 0;
}

/*
Input:
a[0] = 1
a[1] = 2
a[2] = 3
a[3] = 4
a[4] = 5

Output:
the mean value = 3
*/