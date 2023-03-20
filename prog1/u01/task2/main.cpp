#include <iostream>

using namespace std;

using ld = long double;

/*
Read in item price, quantity and VAT rate and output the total price.
*/

int main() {
    ld price{}, rate{};
    uint64_t quantity{};
    cout << "item price = ";
    cin >> price;
    cout << "\nquantity = ";
    cin >> quantity;
    cout << "\nVAT rate in % = ";
    cin >> rate;
    cout << "\ntotal price = " << price * quantity * (1 + rate / 100) << '\n';
    return 0;
}

/*
Input:
item price = 5
quantity = 20
VAT rate in % = 15

Output:
total price = 115
*/