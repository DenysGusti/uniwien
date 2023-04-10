#include <iostream>

using namespace std;

using ld = long double;

/*
Sort 3 input double numbers without using logical operators.
*/

int main() {
    double a{}, b{}, c{};
    cout << "enter a, b, c = ";
    cin >> a >> b >> c;

    double max_n = (a + b + abs(a - b)) / 2;
    double min_n = (a + b - abs(a - b)) / 2;

    max_n = max(max_n, c);
    min_n = min(min_n, c);

    double mid_n = (a + b + c) - max_n - min_n;

    cout << "sorted: " << min_n << ' ' << mid_n << ' ' << max_n << '\n';
    return 0;
}

/*
Input:
enter a, b, c = 4 1 2

Output:
sorted: 1 2 4
*/