#include <iostream>

using namespace std;

/*
To swap the contents of two variables, you normally use a sequence of the form: temp=y; y=x; x=temp;

Write a swap function that swaps the contents of two int variables without using a helper variable (so don't use an additional local variable in the function). Also no subtractions or divisions (-, -=, /, /=) may be used.
*/

int main() {
    int a = 1, b = 2;
    swap(a, b);
    cout << a << ' ' << b << '\n';
    a ^= b;  // a = a xor b
    b ^= a;
    a ^= b;
    cout << a << ' ' << b << '\n';
    return 0;
}

/*
Input:

Output:
2 1
1 2
*/