#include <iostream>

using namespace std;

using ld = long double;

/*
Read in 2 interval limits and then any number of numbers (ending with EOF) and output how many numbers were smaller
than the lower interval limit, how many were in the interval and how many were larger than the upper interval limit.
*/

int main() {
    int64_t lower{}, upper{};
    uint64_t in_interval{}, below_lower{}, above_upper{};

    cout << "enter lower interval limit: ";
    cin >> lower;
    cout << "enter upper interval limit: ";
    cin >> upper;

    cout << "enter numbers (EOF to terminate): ";
    for (int64_t number{}; cin >> number; )
        number < lower ? ++below_lower : (number > upper ? ++above_upper : ++in_interval);

    cout    << "smaller than the lower limit: " << below_lower
            << "\nin interval: " << in_interval
            << "\nlarger than the upper limit: " << above_upper << '\n';
    return 0;
}

/*
Input:
enter lower interval limit: 5
enter upper interval limit: 10
enter numbers (EOF to terminate): 2 6 12 8 4 9 1

Output:
smaller than the lower limit: 2
in interval: 3
larger than the upper limit: 1
*/