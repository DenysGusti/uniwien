#include <iostream>
#include <array>

using namespace std;

using ld = long double;

/*
Read in three values, output the last digit for each of the three values in reverse order,
and then output the remainder of the values in the order they were read in.
E.g. input is 137 42 5809, output is 927134580.
*/

const static size_t n = 3;

int main() {
    array<uint64_t, n> values{};
    for (size_t i = 0; i < values.size(); ++i) {
        cout << "\na[" << i << "] = ";
        cin >> values[i];
    }
    for (const auto el: values)
        cout << el << '\n';

    for (size_t i = values.size(); i > 0; --i)
        cout << values[i - 1] % 10;
    for (const auto el: values)
        cout << el / 10;
    cout << '\n';
    return 0;
}
