#include <iostream>
#include <array>

using namespace std;

using ld = long double;

/*
Read in five measured values of a test series and determine the mean value.
*/

const static size_t n = 5;

int main() {
    array<ld, n> values{};
    for (size_t i = 0; i < values.size(); ++i) {
        cout << "\na[" << i << "] = ";
        cin >> values[i];
    }

    ld mean{};
    for (const auto val: values)
        mean += val / values.size();

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
