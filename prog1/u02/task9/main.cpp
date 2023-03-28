#include <iostream>
#include <random>

using namespace std;

using ld = long double;

/*
A somewhat determined roulette player always bets a fixed amount on the number 0. She does this until this number is finally rolled.
Write a program that reads the amount and number of trials required and calculates the roulette player's win or loss.
*/

int main() {
    uint64_t amount{}, trials{};
    cout << "Enter amount and number of trials: ";
    cin >> amount >> trials;

    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<uint64_t> dist(0, 36);
    int64_t won{};
    for (uint64_t i = 0; i < trials; ++i)
        won += amount * (dist(gen) == 0 ? 35 : -1); // x35 if wins
    cout << "player has gained: " << won << "\nexpected: " <<  amount * trials / -37.L << '\n'; // E = (35*(1/37)-1*(36/37)) = -1/37
    return 0;
}

/*
Input:
Enter amount and number of trials: 1 1000000

Output:
player has gained: -28288
expected: -27027
*/