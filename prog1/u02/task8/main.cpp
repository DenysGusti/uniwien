#include <iostream>

using namespace std;

using ld = long double;

/*
Write a program to convert seconds to the equivalent number of years, days, hours, minutes, and seconds and vice versa.
(Assume that there are always 365 days in a year. Leap years are not taken into account.
*/

int main() {
    char o{};
    do {
        cout << endl << "choose convert seconds to years, days, hours, minutes and seconds or vice versa (s/v): ";
        cin >> o;
    } while (o != 's' && o != 'v');

    uint64_t t{};
    if (o == 's') {
        cout << "seconds = ";
        cin >> t;
        cout << "years, days, hours, minutes and seconds = ";
        cout << t / (365 * 24 * 60 * 60) << " years ";
        t %= 365 * 24 * 60 * 60;
        cout << t / (24 * 60 * 60) << " days ";
        t %= 24 * 60 * 60;
        cout << t / (60 * 60) << " hours ";
        t %= 60 * 60;
        cout << t / 60 << " minutes ";
        t %= 60;
        cout << t << " seconds\n";
    } else {
        uint64_t s{};
        cout << "years: ";
        cin >> t;
        s += t * 365 * 24 * 60 * 60;
        cout << "days: ";
        cin >> t;
        s += t * 24 * 60 * 60;
        cout << "years: ";
        cin >> t;
        s += t * 60 * 60;
        cout << "days: ";
        cin >> t;
        s += t * 60;
        cout << "seconds: ";
        cin >> t;
        s += t;
        cout << "total seconds = " << s << '\n';
    }
    return 0;
}

/*
Input:
choose convert seconds to years, days, hours, minutes and seconds or vice versa (s/v): s
seconds = 1000000000

Output:
years, days, hours, minutes and seconds = 31 years 259 days 1 hours 46 minutes 40 seconds
*/