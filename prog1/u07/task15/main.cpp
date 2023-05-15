#include <iostream>
#include <vector>
#include <array>

using namespace std;

/*
(*) Implement the quicksort algorithm (as described in Wikipedia for example).
*/

const static size_t MAX_LEVELS = 64;

template<class T>
void quickSort(vector<T> &arr) {
    array<size_t, MAX_LEVELS> beg, end;
    size_t L{}, R{};
    int i = 0;

    beg[0] = 0;
    end[0] = arr.size();
    while (i >= 0) {
        L = beg[i];
        R = end[i];
        if (L + 1 < R--) {
            int piv = arr[L];
            if (i == beg.size() - 1)
                throw runtime_error{"> MAX_LEVELS"};
            while (L < R) {
                while (arr[R] >= piv && L < R)
                    R--;
                if (L < R)
                    arr[L++] = arr[R];
                while (arr[L] <= piv && L < R)
                    L++;
                if (L < R)
                    arr[R--] = arr[L];
            }
            arr[L] = piv;
            if (L - beg[i] > end[i] - R) { 
                beg[i + 1] = L + 1;
                end[i + 1] = end[i];
                end[i++] = L;
            } else {
                beg[i + 1] = beg[i];
                end[i + 1] = L;
                beg[i++] = L + 1;
            }
        } else
            --i;
    }
}

int main() {
    vector<int> arr = {5, 4, 3, 2, 1};
    quickSort(arr);
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