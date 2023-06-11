#include <iostream>
#include <algorithm>

using namespace std;

/*
Write a function that takes an array of double values, an array of pointers to double values ​​of equal length and the length of the arrays as parameters, and sets the pointers in the second array such that the first pointer points to the smallest element in the first array , the second pointer to the second smallest, etc.
Note: The numbers in the first array are sorted logically without having to reposition them. If you want to iterate through the sort order, you simply use the pointer array and dereference one pointer at a time.
Tip: You can use one of the already known sorting methods. First set each pointer to the corresponding element in the value array (i.e. first pointer to first value, second to second, etc.) and then apply the sorting algorithm to the pointer array. If a comparison of values ​​is to be carried out in the sorting process, do not compare the pointers themselves, but the dereferenced pointers (that is, the values ​​to which the pointer is pointed).
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