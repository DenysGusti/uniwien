#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

using ld = long double;

/*
Write a program that reads a four-digit integer and prints its verbal representation.
E.g. input 1723 output one-seven-two-three.
*/

int main() {
    unordered_map<char, string> representations = {
        {'0', "zero"}, {'1', "one"}, {'2', "two"}, {'3', "three"}, {'4', "four"},
        {'5', "five"}, {'6', "six"}, {'7', "seven"}, {'8', "eight"}, {'9', "nine"}
        };

    string number;
    cout << "enter a four-digit integer: ";
    cin >> number;

    for (const auto &digit: number)
        cout << representations[digit] << (&digit != &number.back() ? "-" : "");
    cout << '\n';
    return 0;
}

/*
Input:
enter a four-digit integer: 1723

Output:
one-seven-two-three
*/