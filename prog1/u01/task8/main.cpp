#include <iostream>
#include <cmath>

using namespace std;

using ld = long double;

/*
A spaceship takes off from Earth and travels uniformly at x percent of the speed of light.
Read in the percentage x and calculate how long a trip to Alpha Centauri will take for the pilot.
How much time has passed on Earth?
*/

const static ld c = 299'792'458;  // speed of light
const static ld AC_distance = 4.344 * 9'460'730'472'580'800;  // 4.344 ly
const static ld seconds_to_years = 1 / (3600 * 24 * 365.25);

int main() {
    ld x{}, v{}, t{};
    cout << "x percent = ";
    cin >> x;
    v = c * x / 100;
    t = AC_distance / v;
    cout << "trip will take for pilot " << t * seconds_to_years << " years\n";
    cout << "on Earth has passed " << t / sqrt(1 - v * v / (c * c)) * seconds_to_years << " years\n";  // t' = t * Lorentz factor
    return 0;
}

/*
Input:
x percent = 99

Output:
trip will take for pilot 4.38788 years
on Earth has passed 31.1048 years
*/