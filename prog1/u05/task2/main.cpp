#include <iostream>
#include <vector>

using namespace std;

/*
Write a function that takes a vector of integers as a parameter and returns a corresponding vector of integers
in which any two adjacent entries are swapped. Don't use a loop in your function.
E.g.: Output vector: {1,2,3,4,5,6} Result vector: {2,1,4,3,6,5}
Note that the vector can also contain an odd number of entries.
*/

vector<int> swapAdj(vector<int> &v, size_t l = 0, size_t r = 1) {
    if (v.size() < 2 || l == v.size() || r == v.size())
        return v;
    swap(v[l], v[r]);
    return swapAdj(v, l + 2, r + 2);
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    for (const auto el: swapAdj(v))
        cout << el << ' ';
    return 0;
}

/*
Input:

Output:
2 1 4 3 6 5
*/