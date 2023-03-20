#include <iostream>

using namespace std;

using ld = long double;  // ld for shortening long double

/*
Read in the length and width of a rectangle and use them to calculate the perimeter and area of the rectangle.
*/

int main() {
    ld lenght{}, width{};
    cout << "length, width = ";
    cin >> lenght >> width;
    cout << "\nperimeter = " << 2 * (lenght + width) << "\narea = " << lenght * width << '\n';
    return 0;
}

/*
Input:
length, width = 3 4

Output:
perimeter = 14
area = 12
*/