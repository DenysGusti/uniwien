#include <iostream>

using namespace std;

using ld = long double;

void addition_table_modulo_n(const uint64_t n) {
    cout << "\nAddition\n";
    for (uint64_t i = 0; i < n; ++i) {
        for (uint64_t j = 0; j < n; ++j) {
            cout << (i + j) % n << '\t';
        }
        cout << '\n';
    }
}

void multiplication_table_modulo_n(const uint64_t n) {
    cout << "\nMultiplication\n";
    for (uint64_t i = 0; i < n; ++i) {
        for (uint64_t j = 0; j < n; ++j) {
            cout << (i * j) % n << '\t';
        }
        cout << '\n';
    }
}

/*
Create the addition table and the multiplication table modulo n. For example, the output for n=4 could look like:

Addition
0	 	1	 	2	 	3
1		2		3		0
2		3		0		1
3		0		1		2

Multiplication
0	 	0	 	0	 	0
0		1		2		3
0		2		0		2
0		3		2		1
*/

int main() {
    uint64_t n{};
    cout << "n = ";
    cin >> n;
    addition_table_modulo_n(n);
    multiplication_table_modulo_n(n);
    return 0;
}

/*
Input:
n = 5

Output:

Addition
0       1       2       3       4
1       2       3       4       0
2       3       4       0       1
3       4       0       1       2
4       0       1       2       3

Multiplication
0       0       0       0       0
0       1       2       3       4
0       2       4       1       3
0       3       1       4       2
0       4       3       2       1
*/