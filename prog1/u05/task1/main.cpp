#include <iostream>
#include <string>

using namespace std;

/*
Write two functions that each take a string as a parameter and return the reversed string (i.e. the original string read from right to left).
To do this, use a loop in the first function and no loop in the second function.
Only the methods of the class string listed under "Description" may be used.
*/

string reverseL(const string &s) {
    string rec_s;
    rec_s.reserve(s.length());
    for(size_t i = s.length() - 1; i != string::npos; --i)
        rec_s += s[i];
    return rec_s;
}

string reverseR(const string &s) {
    return s.back() + (s.empty() ? "" : reverseR(s.substr(0, s.length() - 1)));
}

int main() {
    string s;
    cout << "string: ";
    cin >> s;
    cout << reverseL(s) << endl;
    cout << reverseR(s) << endl;
    return 0;
}

/*
Input:
string: abc

Output:
cba
cba
*/