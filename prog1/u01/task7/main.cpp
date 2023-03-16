#include <iostream>

using namespace std;

using ld = long double;

/*
Convert euros to dollars, or vice versa.
*/

const static ld EUR_to_USD = 1.054749961;
const static ld USD_to_EUR = 1 / EUR_to_USD;

int main() {
    ld money{};
    char o{};
    cout << "money = ";
    cin >> money;
    do {
        cout << endl << "choose convert to euros or dollars (e/d): ";
        cin >> o;
        cout << o;
    } while (o != 'e' && o != 'd');

    if (o == 'e')
        cout << '\n' << money << " USD = " << money * USD_to_EUR << " EUR\n";
    else
        cout << '\n' << money << " EUR = " << money * EUR_to_USD << " USD\n";
    return 0;
}
