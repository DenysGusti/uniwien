#include <iostream>
#include <string>

using namespace std;

using ld = long double;

/*
Write a function that takes a string and a character as parameters and returns the string
that results when the character is removed from the string (you don't have to explicitly remove the character from the string.
It might be easier to start a new string as a copy of the input string - character by character - and simply ignore the character to be "deleted"
when copying). To test, write a main program that first reads in a string and then repeatedly reads a single character and outputs the result
when the last input character is removed from the string. The program should be terminated by entering EOF, e.g.:

Input: SickoSisters
Input: S
Output: ickoisters
Input: i
Output: SckoSsters
Input: Ctrl-D
program end
*/

string removeCharacters(string_view s, const char ch) {
    string res;
    res.reserve(s.length());
    for (const auto c: s)
        if (c != ch)
            res += c;
    return res;
}


int main() {
    string s;
    cout << "string: ";
    getline(cin, s);

    for (char ch{}; true;) {
        cout << "character to delete: ";
        if (!(cin >> ch)) break;
        cout << removeCharacters(s, ch) << endl;
    }

    return 0;
}

/*
Input:
string: SickoSisters           
character to delete: S
character to delete: i
character to delete: ^Z

Output:
ickoisters
SckoSsters
*/