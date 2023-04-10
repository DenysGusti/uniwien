#include <iostream>
#include <cmath>
#include <string>

using namespace std;

using ld = long double;

bool isOp(const char op) {
    return op == '+' || op == '-' || op == '*' || op == '/' || op == '!';
}

ld parse_string(const string &s) {
    ld result = NAN;
    char op;
    if (s.back() != '!') {
        cout << "invalid expression" << endl;
        return NAN;
    }
    for (size_t prev_idx = 0, next_idx = 0; next_idx < s.length(); ++next_idx) {
        if (isOp(s[next_idx])) {
            if (prev_idx == 0) {
                result = stod(s.substr(0, next_idx));
            } else {
                switch (op) {
                case '+':
                    result += stod(s.substr(prev_idx, next_idx - prev_idx));
                    break;
                case '-':
                    result -= stod(s.substr(prev_idx, next_idx - prev_idx));
                    break;
                case '*':
                    result *= stod(s.substr(prev_idx, next_idx - prev_idx));
                    break;
                case '/':
                    if (stod(s.substr(prev_idx, next_idx - prev_idx)) == 0) {
                        cout << "division by 0" << endl;
                        return NAN;
                    }
                    result /= stod(s.substr(prev_idx, next_idx - prev_idx));
                    break;
                default:
                    cout << "invalid operator" << endl;
                    return NAN;
                }
            }
            op = s[next_idx];
            prev_idx = next_idx + 1;
        }
    }
    return result;
}

/*
Write a program that simulates a very simple calculator.
A mathematical expression containing numbers and the binary operators +,-,* and / is entered.
The expression is ended with an exclamation mark. The program should calculate the result of the expression,
doing the operations strictly from left to right. (This means that multiplicative operators do not apply before additive operators!)
E.g.: Input 2+3-4/2*3-1! Output 0.5
*/

int main() {
    string s;
    getline(cin, s);
    cout << parse_string(s) << endl;
    return 0;
}

/*
Input:
20+30-40/20*30-10!

Output:
5
*/