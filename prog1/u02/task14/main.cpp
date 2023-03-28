#include <iostream>
#include <iomanip>

using namespace std;

using ld = long double;

/*
(*) Evaluate the expression 2147483647+1 using the data types int, unsigned, long and double respectively. Compare and interpret the results.
Note: The current settings on the environment provided by us cause the undefined behavior of int-overflow to be recognized at runtime
and lead to the program aborting. In order to achieve the desired behavior, the corresponding test programs (sanitizer) must not be included.
This can be achieved by prefixing the compile command with a backslash (i.e. \clang++ ...).
*/

int main() {
    cout << "2147483647+1=\n"; // 2^31-1
	cout << "using int: " << 2147483647+1 << '\n';  // overflow, implementation-defined, warning, in praxis -2147483648
	cout << "using unsigned: " << 2147483647u+1u << '\n';  // within the range, 2147483648
	cout << "using long: " << 2147483647l+1l << '\n';  // size of 4 bytes, max signed 2^31-1, overflow just like int, -2147483648
	cout << "using double: " << fixed << setprecision(1) << 2147483647.+1. << '\n';  //  floating-point type, a much larger range, no error because power of 2
    return 0;
}

/*
Input:

Output:
2147483647+1=
using int: -2147483648
using unsigned: 2147483648
using long: -2147483648
using double: 2147483648.0
*/