#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void allPermA(string s) {
    for(sort(begin(s), end(s)); next_permutation(begin(s), end(s)); cout << s << ' ');
}

void allPermM(string &s, size_t l = 0, size_t r = string::npos) {
    if (l == r) {
        cout << s << ' ';
        return;
    }
    if (r == string::npos)
        r = s.length() - 1;
    for (auto i = l; i <= r; ++i) {
        swap(s[l], s[i]);
        allPermM(s, l + 1, r);
        swap(s[l], s[i]);
    }
}

/*
(*) Write a function that takes a string (data type string) as a parameter
and outputs all possible permutations of the characters contained in the string.
(You can assume that each character appears only once.) E.g.:
Parameter: abc
Output: abc acb bac bca cab cba
*/

int main() {
    string s;
    cout << "string: ";
    getline(cin, s);
    allPermA(s);
    return 0;
}

/*
Input:
string: abc

Output:
acb bac bca cab cba
*/