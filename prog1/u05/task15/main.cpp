#include <iostream>

using namespace std;

/*
Write a function int stack() that when called causes the stack to overflow.
(Note: This overflow, commonly referred to as "stack overflow", is indicated on the computers in our labs by the program aborting
and the error message "Segmentation fault".) How many times must the stack() function be called recursively until there is a stack overflow?
How can you speed this up and how can you estimate the size of the stack from your results?
*/
static uint64_t c = 0;

uint64_t stack() {
    ++c;
    if (c % 1'000'000'000 == 0)
        cout << c << endl;
    return stack();
}

int main() {
    stack();
    return 0;
}

/*
Input:

Output:
1000000000
...
no call stack overflow???
*/