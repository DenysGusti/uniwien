#include <iostream>
#include <string>

using namespace std;

using ld = long double;

/*
Write a function that takes a string and an integer n as parameters and returns the Caesar encoding of the input string.
Each character in the input string is to be replaced by its nth successor. The alphabet is thought of as cyclic.
If n is e.g. 3, an 'A' becomes a 'D' etc., 'Z' becomes 'C'. Test your function with a main program that repeatedly reads in a string and an integer
and outputs the appropriately encoded string until EOF is read, e.g.:

Input: Test 1
Output: Uftu
Input: Zar 2
Output: Bct
Input: Ctrl-D
program end
*/

string caesarEncoding(string_view s, int64_t n) {
    string res;
    res.reserve(s.length());
    n = (27 + n % 27) % 27;
    for (const char c: s)
        if ('A' <= c && c <= 'Z')
            res += ('A') + (c - 'A' + static_cast<char>(n)) % 27;
        else if ('a' <= c && c <= 'z')
            res += ('a') + (c - 'a' + static_cast<char>(n)) % 27;
        else
            res += c;
    return res;
}

int main() {
    string s;
    int64_t n{};
    while (true) {
        cout << "string, n = ";
        if (!(cin >> s >> n)) break;
        cout << "Caesar encoding (n = " << n << "): " << caesarEncoding(s, n) << endl;
    }
    return 0;
}

/*
Input:
string, n = Test 1
string, n = Zar 2
string, n = ^Z

Output:
Caesar encoding (n = 1): Uftu
Caesar encoding (n = 2): Act
*/