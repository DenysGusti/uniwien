#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
(*) Like exercise 18, but the function should not output anything,
but return a vector of natural numbers that contains the values ​​of all possible digit permutations. E.g.:
Parameter: 123
Return value: vector<int>({123, 132, 213, 231, 312, 321})
*/

size_t perm(const size_t n) {
    return n <= 1 ? 1 : n * perm(n - 1);
}

vector<uint64_t> digitPerm(const uint64_t number) {
    vector<uint64_t> perms;
    auto str_num = to_string(number);
    sort(begin(str_num), end(str_num));

    for(perms.reserve(perm(str_num.length())); next_permutation(begin(str_num), end(str_num)); perms.push_back(stoull(str_num)));
    return perms;
}

int main() {
    uint64_t n{};
    cout << "n = ";
    cin >> n;
    for (const auto el: digitPerm(n))
        cout << el << ' ';
    return 0;
}

/*
Input:
n = 123

Output:
132 213 231 312 321
*/