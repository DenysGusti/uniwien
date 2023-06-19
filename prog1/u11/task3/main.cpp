#include <iostream>
#include <algorithm>

using namespace std;

/*
Implement a function that takes a two-dimensional square array of size 5 of int values ​​(int[5][5]) as a parameter and tests whether the given array is a magic square. If so, return the magic number of the square (which is the sum of all rows, columns, and the diagonals), otherwise 0.
*/

void order(double * const arr, double * * const parr, const size_t n) {
    for (size_t i = 0; i < n; ++i)
        parr[i] = &arr[i];
    sort(parr, parr + n, [] (const auto p1, const auto p2) -> bool { return *p1 < *p2; });
}

int main() {
    double arr[] = {5, 4, 3, 2, 1, 0};
    const size_t n = sizeof(arr) / sizeof(arr[0]);
    double * parr[n]{};
    order(arr, parr, n);
    for (size_t i = 0; i < n; ++i)
        cout << *parr[i] << ' ';
    cout << endl;
    return 0;
}

/*
Input:

Output:
0 1 2 3 4 5
*/