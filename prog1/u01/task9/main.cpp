#include <iostream>

using namespace std;

using ld = long double;

/*
x grams of hydrogen are to be burned.
Read in x and calculate how many grams of oxygen are required for the reaction and how many milliliters of water are produced.
*/

int main() {
    ld x{};
    cout << "x grams = ";
    cin >> x;
    //  2H2+O2->2H20; M(H2)=2g/mol, M(O2)=32g/mol, M(H2O)=18g/mol; m(O2)=0.5*M(O2)/M(H2)*m(H2)=8x; V(H20)=m(H20)/p(H20)=1*M(H20)/M(H2)*m(H2)/1g/ml=9x
    cout << x * 8 << " grams of oxygen are required for the reaction\n" << x * 9 << " milliliters of water are produced\n";
    return 0;
}

/*
Input:
x grams = 22.22

Output:
177.76 grams of oxygen are required for the reaction
199.98 milliliters of water are produced
*/