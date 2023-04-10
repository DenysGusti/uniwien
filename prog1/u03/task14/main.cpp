#include <iostream>
#include <string>

using namespace std;

using ld = long double;

static size_t inversions = 0;

void mergeSort(string &a) {
    const size_t n = a.length();
    size_t block_size, block_it, l_it, r_it, l_border, r_border, m_border, i;
    string sort_block(n, {});
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
                    inversions += m_border - l_border - l_it;  // here
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

/*
Write a program that reads an integer and prints the number of inversions in the entered number.
We call inversions for a certain digit (starting digit) of the number all digits
that are in the number after the starting digit and are smaller than it.
E.g.: Input 53278 Output 3.
Since 3 goes after 5, 2 goes after 5, and 2 goes after 3
*/

int main() {
    string n;
    cout << "n = ";
    cin >> n;
    mergeSort(n);  // O(n*log(n))
    cout << "inversions = " << inversions << endl;
    return 0;
}

/*
Input:
n = 54321

Output:
inversions = 10
*/