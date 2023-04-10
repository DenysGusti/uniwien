#include <iostream>
#include <unordered_map>

using namespace std;

using ld = long double;

/*
(*) Like task 2, but for arbitraty real numbers.
E.g.: input 17.23 output one-seven-point-two-three.
*/

int main() {
    unordered_map<char, string> representations = {
        {'0', "zero"}, {'1', "one"}, {'2', "two"}, {'3', "three"}, {'4', "four"},
        {'5', "five"}, {'6', "six"}, {'7', "seven"}, {'8', "eight"}, {'9', "nine"},
        {'.', "point"}
        };

    string number;
    cout << "enter a real number: ";
    cin >> number;

    for (const auto &digit: number)
        cout << representations[digit] << (&digit != &number.back() ? "-" : "");
    cout << '\n';
    return 0;
}

/*
Input:
enter a real number: 123.456

Output:
one-two-three-point-four-five-six
*/