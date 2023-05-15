#include <iostream>
#include <vector>

using namespace std;

/*
Write a function for sorting an integer array using the mergesort algorithm: The array to be sorted is recursively divided into half-length subarrays until the (trivial, scalar) arrays consist of a single element. Then 2 partial fields are merged (sorted) into a field that is twice as large. When merging, the first two elements of the fields are successively compared and the smaller one is transferred to the new field until all elements in the new field are sorted and saved. The merging is repeated until, in the last phase, 2 arrays of length n/2 merge into a sorted array of length n. You can use vectors to represent fields in C++.
*/

template<class T>
void mergeSort(vector<T> &a) {
    const size_t n = a.size();
    size_t block_size, block_it, l_it, r_it, l_border, r_border, m_border, i;
    vector<T> sort_block(n);
    for (block_size = 1; block_size < n; block_size *= 2)
        for (block_it = 0; block_it < n - block_size; block_it += 2 * block_size) {
            l_it = 0, r_it = 0;
            l_border = block_it, m_border = block_it + block_size, r_border = min(block_it + 2 * block_size, n);
            while (l_border + l_it < m_border && m_border + r_it < r_border) {
                if (a[l_border + l_it] < a[m_border + r_it]) {
                    sort_block[l_it + r_it] = a[l_border + l_it];
                    ++l_it;
                } else {
                    sort_block[l_it + r_it] = a[m_border + r_it];
                    ++r_it;
                }
            }
            for (; l_border + l_it < m_border; ++l_it)
                sort_block[l_it + r_it] = a[l_border + l_it];
            for (; m_border + r_it < r_border; ++r_it)
                sort_block[l_it + r_it] = a[m_border + r_it];
            for (i = 0; i < l_it + r_it; ++i)
                a[l_border + i] = sort_block[i];
        }
}

int main() {
    vector<int> arr = {5, 4, 3, 2, 1};
    mergeSort(arr);
    for (const auto el: arr)
        cout << el << ' ';
    cout << endl;
    return 0;
}

/*
Input:

Output:
1 2 3 4 5
*/