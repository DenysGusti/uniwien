#include <iostream>
#include <limits>

using namespace std;

using ld = long double;

/*
Read in any number of double values (ending with EOF) and output the maximum, the minimum and the mean of the entered values.
*/

int main() {
    double  sum_of_values = 0,
            min_of_values = numeric_limits<double>::infinity(),
            max_of_values = -numeric_limits<double>::infinity();
    size_t count_values = 0;

    cout << "enter values: ";
    for (double value{}; cin >> value; ++count_values, sum_of_values += value) {
        min_of_values = min(min_of_values, value);
        max_of_values = max(max_of_values, value);
    }

    if (!count_values)
        cout << "no values entered.\n";
    else
        cout << "\nminimum: " << min_of_values << "\nmaximum: " << max_of_values << "\nmean: " << sum_of_values / count_values << '\n';
    return 0;
}

/*
Input:
enter values: 5 1 4 2 3

Output:
minimum: 1
maximum: 5
mean: 3
*/