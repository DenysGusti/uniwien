#include <iostream>
#include <string>

using namespace std;

using ld = long double;

/*
Write a function that takes a string and a character as parameters.
The position at which the character first appears in the string is to be returned as an int value.
The string may contain parts in double quotation marks that are to be ignored when searching for the character.
Think about special cases and how your function should react to them. For example:

Parameters: "He said \"I have no hint.\" and headed south" 'h'
Return value: 30
*/

int specialFind(string_view s, const char ch) {
    bool quote_opened = false;
    for (size_t i = 0; i < s.length(); ++i)
        if (s[i] == '"')
            quote_opened = !quote_opened;
        else if (s[i] == ch && !quote_opened)
            return i;
    return static_cast<int>(string::npos);

}

int main() {
    string s;
    char ch{};
    cout << "string = ";
    getline(cin, s);
    cout << "character = ";
    cin >> ch;
    cout << "position beyond double quotation marks: " << specialFind(s, ch) << endl;
    return 0;
}

/*
Input:
string = He said "I have no hint." and headed south   
character = h

Output:
position beyond double quotation marks: 30
*/