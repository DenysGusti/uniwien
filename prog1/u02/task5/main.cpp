#include <iostream>
#include <cmath>

using namespace std;

using ld = long double;

/*
Read in the coordinates of two points in R³ and calculate the distance between the two points.
*/

int main() {
	ld x_1{}, y_1{}, z_1{}, x_2{}, y_2{}, z_2{};
	cout << "x_1, y_1, z_1 = ";
	cin >> x_1 >> y_1 >> z_1;
	cout << "x_2, y_2, z_2 = ";
	cin >> x_2 >> y_2 >> z_2;
	cout << "the distance between the two points (" << x_1 << ", " << y_1 << ", " << z_1 << ") and (" << x_2 << ", " << y_2 << ", " << z_2 << ") = "; 
	cout << hypot(x_1 - x_2, y_1 - y_2, z_1 - z_2) << '\n';
    return 0;
}

/*
Input:
x_1, y_1, z_1 = 0 0 0 
x_2, y_2, z_2 = 1 4 8

Output:
the distance between the two points (0, 0, 0) and (1, 4, 8) = 9
*/